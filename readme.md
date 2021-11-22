```

██████╗ ███████╗ █████╗ 
██╔══██╗██╔════╝██╔══██╗
██████╔╝███████╗███████║
██╔══██╗╚════██║██╔══██║
██║  ██║███████║██║  ██║
╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
                        
```

## About RSA

[refer](https://en.wikipedia.org/wiki/RSA_(cryptosystem))

[RSA (Rivest–Shamir–Adleman)](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) is one of the commonly used  [asymmetric cryptography algorithm](https://en.wikipedia.org/wiki/Public-key_cryptography) . 

### Operation

The RSA algorithm involves four steps: key generation, key distribution, encryption, and decryption.

## RSA Proof of correctness

Before establishing the proof of correctness, there are two theorems that are essential in undertstanding it:

1. Fermat's little theorem
2. Chinese remainder theorem

### Fermat's little theorem

Fermat's little theorem states that if p is a prime number, then for any integer a, the number ap − a is an integer multiple of p.

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_00.svg)