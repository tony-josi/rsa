/** 
 *  @file   rsa.cc
 *  @brief  Soruce file for the RSA library
 *
 *  This file contains the implementation of the RSA library
 *
 *  @author         Tony Josi   https://github.com/tony-josi/rsa
 *  @copyright      Copyright (C) 2021 Tony Josi
 *  @bug            No known bugs.
 */

#include <stdexcept>

#include "rsa.hpp"

constexpr uint32_t DEFAULT_32_BIT_PUBLIC_KEY = 0x10001;

rsa::rsa(size_t bit_size_arg, int miller_rabin_rounds = 20, int max_number_of_threads_for_miller_rabin = -1) {

    int ret_val = 0;
    
    if (bit_size_arg < 64 || bit_size_arg % 2 != 0) {
        throw std::invalid_argument("Invalid bit size for RSA, must be greater than or equal to 64 and even");
    }
    bit_size_arg /= 2;
    bit_size = bit_size_arg;
    
    /* Create 2 random primes with RSA bitsize bits. */
    int pq_comp_res;
    do {
        ret_val += p.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), \
        miller_rabin_rounds, max_number_of_threads_for_miller_rabin);
        ret_val += q.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), \
        miller_rabin_rounds, max_number_of_threads_for_miller_rabin);
    } while((pq_comp_res = p.big_int_unsigned_compare(q)) == 0); /* Continue until we have distinct primes p, q. */

    ret_val += p.big_int_multiply(q, pq);

    bi::big_int bi_1;
    ret_val += bi_1.big_int_from_base_type(1, false);

    /* Calculate p-1 and q-1 */
    ret_val += p.big_int_unsigned_sub(bi_1, p_minus_1);
    ret_val += q.big_int_unsigned_sub(bi_1, q_minus_1);
    ret_val += p_minus_1.big_int_multiply(q_minus_1, p_minus_1q_minus_1);

    /* Initialise public key, [uses DEFAULT_32_BIT_PUBLIC_KEY as the default public key, hence the minimum 64 bits key size restrictions.] */
    ret_val += e.big_int_from_base_type(DEFAULT_32_BIT_PUBLIC_KEY, false);

    if (e.big_int_unsigned_compare(p_minus_1q_minus_1) >= 0) {
        throw std::invalid_argument("Error initializing RSA");
    }

    /* Calculate the private key as the modular inverse of the 
       public key in (p-1)(q-1). */
    ret_val += e.big_int_modular_inverse_extended_euclidean_algorithm(p_minus_1q_minus_1, d);

    /* Store the smaller prime among p & q and private key modulo smaller prime
       for faster/efficient decryption. [Fermat's Little theorem]. */
    if (pq_comp_res > 0) {
        smaller_prime = q;
        ret_val += d.big_int_modulus(q_minus_1, reduced_d);
    } else {
        smaller_prime = p;
        ret_val += d.big_int_modulus(p_minus_1, reduced_d);
    }

    /* Throw if error. */
    if (ret_val != 0) {
        throw std::invalid_argument("Error initializing RSA");
    }

}

bi::big_int rsa::get_private_key() {
    return d;
}

bi::big_int rsa::get_public_key() {
    return e;
}

bi::big_int rsa::get_modulus() {
    return pq;
}

int rsa::rsa_encrypt(bi::big_int &plain, bi::big_int &cipher) {

    if (plain.big_int_get_num_of_bits() > bit_size) {
        throw std::invalid_argument("Plain text too long");
    }

    /* c  = m ^ e mod pq = m ^ e mod p = m ^ e mod q     [Chinese remainder theorem].
        refer ==> https://tony-josi.github.io/Articles/RSA_Proof/rsa_proof.html */
    return plain.big_int_fast_modular_exponentiation(e, smaller_prime, cipher);
}

int rsa::rsa_decrypt_textbook_method(bi::big_int &cipher, bi::big_int &decipher) {

    if (cipher.big_int_get_num_of_bits() > bit_size) {
        throw std::invalid_argument("Cipher text too long");
    }

    /* m  = c ^ d mod pq = c ^ d mod p = c ^ d mod q     [Chinese remainder theorem].
        refer ==> https://tony-josi.github.io/Articles/RSA_Proof/rsa_proof.html */
    return cipher.big_int_fast_modular_exponentiation(d, smaller_prime, decipher);
}

int rsa::rsa_decrypt(bi::big_int &cipher, bi::big_int &decipher) {

    if (cipher.big_int_get_num_of_bits() > bit_size) {
        throw std::invalid_argument("Cipher text too long");
    }

    /* Refer ==> RSA optimizing the decryption algorithm
       from https://tony-josi.github.io/Articles/RSA_Proof/rsa_proof.html */

    int ret_val = 0;
    bi::big_int reduced_cipher_text;
    ret_val += cipher.big_int_modulus(smaller_prime, reduced_cipher_text);

    ret_val += reduced_cipher_text.big_int_fast_modular_exponentiation(reduced_d, smaller_prime, decipher);
    return ret_val;

}