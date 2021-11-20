#include <stdexcept>

#include "rsa.hpp"

constexpr uint32_t DEFAULT_32_BIT_PUBLIC_KEY = 0x10001;

rsa::rsa(size_t bit_size_arg) {

    int ret_val = 0;
    bit_size = bit_size_arg;
    
    if (bit_size_arg < 64 || bit_size_arg % 2 != 0) {
        throw std::invalid_argument("Invalid bit size for RSA, must be greater than or equal to 64 and even");
    }
    bit_size_arg /= 2;
    
    int pq_comp_res;
    do {
        ret_val += p.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), 10, -1);
        ret_val += q.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), 10, -1);
    } while((pq_comp_res = p.big_int_unsigned_compare(q)) == 0); /* Continue until we have distinct primes p, q. */

    is_p_larger = pq_comp_res > 0 ? true : false;

    ret_val += p.big_int_multiply(q, pq);

    bi::big_int bi_1;
    ret_val += bi_1.big_int_from_base_type(1, false);
    ret_val += p.big_int_unsigned_sub(bi_1, p_minus_1);
    ret_val += q.big_int_unsigned_sub(bi_1, q_minus_1);
    ret_val += p_minus_1.big_int_multiply(q_minus_1, p_minus_1q_minus_1);

    ret_val += e.big_int_from_base_type(DEFAULT_32_BIT_PUBLIC_KEY, false);

    if (e.big_int_unsigned_compare(p_minus_1q_minus_1) >= 0) {
        throw std::invalid_argument("Error initializing RSA");
    }

    ret_val += e.big_int_modular_inverse_extended_euclidean_algorithm(p_minus_1q_minus_1, d);

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

    return plain.big_int_fast_modular_exponentiation(e, pq, cipher);
}

int rsa::rsa_decrypt_textbook_method(bi::big_int &cipher, bi::big_int &decipher) {

    if (cipher.big_int_get_num_of_bits() > bit_size) {
        throw std::invalid_argument("Cipher text too long");
    }

    return cipher.big_int_fast_modular_exponentiation(d, pq, decipher);
}

int rsa::rsa_decrypt(bi::big_int &cipher, bi::big_int &decipher) {

    if (cipher.big_int_get_num_of_bits() > bit_size) {
        throw std::invalid_argument("Cipher text too long");
    }

    int ret_val = 0;

    bi::big_int samller_prime, samller_prime_minus_1;
    if (is_p_larger) {
        samller_prime = q;
        samller_prime_minus_1 = q_minus_1;
    } else {
        samller_prime = p;
        samller_prime_minus_1 = p_minus_1;
    }

    bi::big_int reduced_cipher_text;
    ret_val += cipher.big_int_modulus(samller_prime, reduced_cipher_text);

    bi::big_int reduced_exponent;
    ret_val += d.big_int_modulus(samller_prime_minus_1, reduced_exponent);

    ret_val += reduced_cipher_text.big_int_fast_modular_exponentiation(reduced_exponent, samller_prime, decipher);
    return ret_val;

}