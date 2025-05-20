//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Returns gcd of a and b
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Returns modular exponentiation (a^b) mod m
int mod_exp(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Returns 1 if n is prime, 0 otherwise
int is_prime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6;
    }
    return 1;
}

// Generates a random prime number of size bits
int prime_gen(int bits) {
    int p = 0;
    while (!is_prime(p)) {
        int a = rand() % (int) pow(2, bits - 1);
        p = (1 << (bits - 1)) | (a << 1) | 1;
    }
    return p;
}

// Returns modular multiplicative inverse of a mod m,
// using the extended Euclidean algorithm
int mult_inv(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

// Generates public and private keys for the RSA algorithm
void rsa_gen_keys(int bits, int *n, int *e, int *d) {
    // Generate two random prime numbers
    int p = prime_gen(bits), q = prime_gen(bits);

    // Calculate n and phi(n)
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose public exponent e
    *e = 65537;
    while (gcd(phi, *e) != 1)
        (*e)++;

    // Calculate private exponent d
    *d = mult_inv(*e, phi);
}

// Encrypts the message m using the public key (n, e)
int rsa_encrypt(int m, int n, int e) {
    return mod_exp(m, e, n);
}

// Decrypts the message c using the private key (n, d)
int rsa_decrypt(int c, int n, int d) {
    return mod_exp(c, d, n);
}

// Test the RSA implementation
int main() {
    int bits = 1024; // Size of the prime numbers
    int n, e, d; // Public and private keys
    rsa_gen_keys(bits, &n, &e, &d);
    printf("Public key: (n=%d, e=%d)\n", n, e);
    printf("Private key: (n=%d, d=%d)\n", n, d);

    int m = 12345; // Message to be encrypted
    int c = rsa_encrypt(m, n, e);
    printf("Encrypted message: %d\n", c);

    int decrypted = rsa_decrypt(c, n, d);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}