#include <iostream>

#include "rsa.hpp"

int main () {

    rsa rsa_128(1024);
    bi::big_int pub_key = rsa_128.get_public_key();
    bi::big_int priv_key = rsa_128.get_private_key();
    bi::big_int modulus = rsa_128.get_modulus();

    std::cout<<"PUB: "<<pub_key.big_int_to_string()<<"\n";
    std::cout<<"PRIV: "<<priv_key.big_int_to_string()<<"\n";
    std::cout<<"MOD: "<<modulus.big_int_to_string()<<"\n";

    bi::big_int plain, cipher, decipher, decipher_tb;
    plain.big_int_from_string("DEAD");
    rsa_128.rsa_encrypt(plain, cipher);
    rsa_128.rsa_decrypt(cipher, decipher);

    std::cout<<"CIPHER: "<<cipher.big_int_to_string()<<"\n";
    std::cout<<"DECIPHER: "<<decipher.big_int_to_string()<<"\n";

    rsa_128.rsa_decrypt_textbook_method(cipher, decipher_tb);
    std::cout << "DECIPHER TB: " << decipher_tb.big_int_to_string() << "\n";

    return 0;

}