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
    
    ret_val += p.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), 10, -1);
    ret_val += q.big_int_get_random_unsigned_prime_rabin_miller_threaded(static_cast<int>(bit_size_arg), 10, -1);
    ret_val += p.big_int_multiply(q, pq);

    bi::big_int bi_1;
    ret_val += bi_1.big_int_from_base_type(1, false);
    ret_val += p.big_int_unsigned_sub(bi_1, p_minus_1);
    ret_val += q.big_int_unsigned_sub(bi_1, q_minus_1);
    ret_val += p_minus_1.big_int_multiply(q_minus_1, p_minus_1q_minus_1);

    ret_val += d.big_int_from_base_type(DEFAULT_32_BIT_PUBLIC_KEY, false);

    if (d.big_int_unsigned_compare(p_minus_1q_minus_1) >= 0) {
        throw std::invalid_argument("Error initializing RSA");
    }

    ret_val += d.big_int_modular_inverse_extended_euclidean_algorithm(p_minus_1q_minus_1, e);

    if (ret_val != 0) {
        throw std::invalid_argument("Error initializing RSA");
    }

}

bi::big_int rsa::get_private_key() {
    return e;
}

bi::big_int rsa::get_public_key() {
    return d;
}

bi::big_int rsa::get_modulus() {
    return pq;
}
