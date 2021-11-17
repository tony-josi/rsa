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

public:

    rsa(size_t bit_size);

    int             rsa_encrypt(bi::big_int &plain, bi::big_int &cipher);
    int             rsa_decrypt(bi::big_int &cipher, bi::big_int &decipher);
    bi::big_int     get_public_key(); 
    bi::big_int     get_private_key(); 
    bi::big_int     get_modulus();

};

