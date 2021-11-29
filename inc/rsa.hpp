/** 
 *  @file   rsa.hpp
 *  @brief  Header file for the RSA library
 *
 *  This file contains the header code and the DS used in the RSA library
 *
 *  @author         Tony Josi   https://github.com/tony-josi/rsa
 *  @copyright      Copyright (C) 2021 Tony Josi
 *  @bug            No known bugs.
 */

#pragma once

#include <stdint.h>

#include "big_int.hpp"

class rsa {

private:
    size_t          bit_size;
    bi::big_int     p;
    bi::big_int     q;
    bi::big_int     p_minus_1;
    bi::big_int     q_minus_1;
    bi::big_int     pq;
    bi::big_int     p_minus_1q_minus_1;
    bi::big_int     e;
    bi::big_int     d;
    bi::big_int     smaller_prime;
    bi::big_int     reduced_d;

public:

    rsa(size_t bit_size, int miller_rabin_rounds = 20, int max_number_of_threads_for_miller_rabin = -1);

    int             rsa_encrypt(bi::big_int &plain, bi::big_int &cipher);
    int             rsa_decrypt_textbook_method(bi::big_int &cipher, bi::big_int &decipher);
    int             rsa_decrypt(bi::big_int &cipher, bi::big_int &decipher);
    bi::big_int     get_public_key(); 
    bi::big_int     get_private_key(); 
    bi::big_int     get_modulus();

};

