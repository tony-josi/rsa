#include <iostream>

#include "rsa.hpp"

int main () {

    rsa rsa_128(128);
    bi::big_int pub_key = rsa_128.get_public_key();
    bi::big_int priv_key = rsa_128.get_private_key();

    std::cout<<"PUB: "<<pub_key.big_int_to_string();
    std::cout<<"PRIV: "<<priv_key.big_int_to_string();

    return 0;

}