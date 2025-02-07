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

Before establishing the proof of correctness, there are two theorems that are essential in undertstanding RSA:

1. Fermat's little theorem
2. Chinese remainder theorem

### Fermat's little theorem

Fermat's little theorem states that if p is a prime number, then for any integer a, the number a^p − a is an integer multiple of p.

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_00.svg)

Proof:

### Group

In mathematics, a group is a set with an operation that associates every pair of elements of the set to an element of the set—also known as a binary operation—that satisfies the following properties:

1. The operation is associative.
1. The operation has an identity element.
1. Every element of the set has an inverse element.

One of the more familiar groups is the set of integers:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_16.svg)

together with addition.

#### Multiplicative group of integers modulo n

In modular arithmetic, the integers coprime (relatively prime) to n from the set 
![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_17.svg)
 of n non-negative integers form a group under multiplication modulo n, called the multiplicative group of integers modulo n. Equivalently, the elements of this group can be thought of as the congruence classes, also known as residues modulo n, that are coprime to n.

#### Euler's totient function

In number theory, Euler's totient function counts the positive integers up to a given integer n that are relatively prime to n.

For example, the totatives of n = 9 are the six numbers 1, 2, 4, 5, 7 and 8. They are all relatively prime to 9, but the other three numbers in this range, 3, 6, and 9 are not, since gcd(9, 3) = gcd(9, 6) = 3 and gcd(9, 9) = 9. Therefore, φ(9) = 6.

#### Euler's theorem

In number theory, Euler's theorem (also known as the Fermat–Euler theorem or Euler's totient theorem) states that, if n and a are coprime positive integers, then 
![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_18.svg)
 is congruent to 
1 modulo n, where 
![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_19.svg) denotes Euler's totient function; that is:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_20.svg)

#### Proof of Euler's theorem

Consider the Multiplicative Group Modulo 𝑛
Define the set of integers that are coprime to 𝑛:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_21.png)

Since multiplication modulo n is a well-defined operation among numbers coprime to n, multiplying every element of S by a (where 
gcd(a,n) = 1) produces another set of numbers that are also distinct and coprime to n:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_22.png)

Since multiplication by a is a bijection in this set (i.e., it maps each element uniquely onto another element in the set), the product of all elements in S remains unchanged modulo n:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_23.png)

Since product of coprimes is also coprimes we can cancel it from both sides (i.e., multiply by its modular inverse), giving:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_24.png)


#### Proof Fermat's little theorem

Euler's theorem is a generalization of Fermat's little theorem: For any modulus n and any integer a coprime to n, one has

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_25.svg)

where φ(n) denotes Euler's totient function (which counts the integers from 1 to n that are coprime to n). Fermat's little theorem is indeed a special case, because if n is a prime number, then φ(n) = n − 1 [Because a prime number n have n-1 co primes].

Hence:

![fermats](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_26.svg)


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

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_05.gif) --------------- (2).

According to the Chinese remainder theorem (CRT) equation (1) is valid if, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_03.gif) --------------- (3) and 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_04.gif) --------------- (4) are valid.

From equation (2) 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_06.gif) --------------- (5) 

where `u` and `v` are some integers, because `ed - 1` is a multiple of the `lcm of (p-1, q-1)`, and `lcm of (p-1, q-1)` will be `u(p - 1) = v(q - 1)`.

Equation (3) can be written as, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_07.gif) --------------- (6), 

which in turn can be written as 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_08.gif) --------------- (7), 

which can be further reduced using the **Fermats Little theorem** to, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_09.gif) --------------- (8), 

which is **valid** as `p` is prime.

Similarly equation (4) can be written as, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_10.gif) --------------- (9), 

which in turn can be written as 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_11.gif) --------------- (10), 

which can be further reduced using the **Fermats Little theorem** to, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_12.gif) --------------- (11), 

which is also **valid** as `q` is prime.

**Hence as both equation (3) and (4) are valid, according to CRT equation 1 is valid.** Hence correctness of RSA is proved.

## RSA optimizing the decryption algorithm

The textbook RSA decryption algorithm is as follows:

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_13.gif) --------------- (12),

where c is the cipher text, d is the private/decryption key, m is the original message. But as c, d, and pq will be very large the decryption process will take long time to execute.

To optimize the calculation of equation 12, by using the CRT we can reduce it to, 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_14.gif) --------------- (13) 

which can be further reduced to 

![rsa](https://github.com/tony-josi/rsa/blob/master/res/readme_images/rsa_15.gif) --------------- (14) 

by using the **Fermats Little theorem**.

## About the project

The project make use of the [`big-int`](https://github.com/tony-josi/big_int) repository for the mathematical calculation involving big numbers used in the RSA algorithm. For the decryption stage both the textbook algorithm and the optimized algorithm are implemented.

### Building the project

```
mkdir build && cd build
cmake ..
make
```