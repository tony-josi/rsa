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

### Chinese remainder theorem

In number theory, the Chinese remainder theorem states that if one knows the remainders of the Euclidean division of an integer n by several integers, then one can determine uniquely the remainder of the division of n by the product of these integers, under the condition that the divisors are pairwise coprime.

If the remainders are same then:

Theorem: ***If, x = y (mod p) &  x = y (mod q) with p and q coprime. Then x = y (mod pq).***

Proof: 
```
x = y (mod p)
x = y + kp
x - y = kp

p divides (x - y)

Similarly,

x = y (mod q)
x = y + kq
x - y = kq

q divides (x - y)

=> kp = kq = x - y

kq = x - y

Muliply with p on both sides,

kpq = (x - y)p

Take mod pq,

0 = (x - y)p mod pq

=> 0 = (x - y) mod pq

=> x = y mod pq

The same can be arrived from kp = x - y .

```

### RSA Proof

We need to prove that,

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_02.gif) --------------- (1)

where **m** can be any integer, **p and q** are distinct prime numbers and **e and d** are positive integers satisfying,

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_05.gif) --------------- (2)

According to the Chinese remainder theorem (CRT) equation (1) is valid if, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_03.gif) --------------- (3)

and

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_04.gif) --------------- (4)

are valid.

From equation (2) 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_06.gif) --------------- (5)

where m and n are some integers, because `ed - 1` is a multiple of the lcm of `(p-1, q-1)`, and lcm of `(p-1, q-1)` will be `m(p - 1) = n(q - 1)`.