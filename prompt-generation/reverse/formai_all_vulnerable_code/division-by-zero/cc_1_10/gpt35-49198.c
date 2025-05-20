//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

// Function prototypes
int isPrime(int n);
int gcd(int a, int b);
int extended_euclid(int A, int B, int *X, int *Y);
uint64_t fastExponentiation(uint64_t a, uint64_t b, uint64_t m);
uint64_t generatePrime();
uint64_t generateRelativePrime(uint64_t phi_n);

// Global variables
uint64_t p;      // prime number p
uint64_t q;      // prime number q
uint64_t n;      // n = p*q
uint64_t phi_n;  // Euler's totient function of n
uint64_t e;      // public key e
uint64_t d;      // private key d

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Generate two prime numbers p and q
    p = generatePrime();
    q = generatePrime();

    // Calculate n and phi(n)
    n = p*q;
    phi_n = (p-1)*(q-1);

    // Generate public key e (1 < e < phi(n) and gcd(e, phi(n)) = 1)
    e = generateRelativePrime(phi_n);

    // Generate private key d such that d is the multiplicative inverse of e modulo phi(n)
    int X, Y;
    extended_euclid(e, phi_n, &X, &Y);
    d = X < 0 ? X + phi_n : X;

    // Print public and private keys
    printf("Public key (n,e): (%lu,%lu)\n", n, e);
    printf("Private key (d): %lu\n", d);

    // Test encryption and decryption
    uint64_t message = 42;
    printf("Original message: %lu\n", message);

    // Encrypt message with public key
    uint64_t ciphertext = fastExponentiation(message, e, n);
    printf("Encrypted message: %lu\n", ciphertext);

    // Decrypt message with private key
    uint64_t decrypted_message = fastExponentiation(ciphertext, d, n);
    printf("Decrypted message: %lu\n", decrypted_message);

    return 0;
}

// Check if n is prime
int isPrime(int n) {
    if(n == 2 || n == 3)
        return 1;
    if(n < 2 || n % 2 == 0)
        return 0;
    for(int i = 3; i < sqrt(n)+1; i += 2)
        if(n % i == 0)
            return 0;
    return 1;
}

// Calculate greatest common divisor of a and b
int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

// Extended Euclidean algorithm for calculating modular multiplicative inverse
int extended_euclid(int A, int B, int *X, int *Y) {
    if(A == 0) {
        *X = 0;
        *Y = 1;
        return B;
    }

    int X1, Y1;
    int gcd = extended_euclid(B % A, A, &X1, &Y1);

    *X = Y1 - (B/A) * X1;
    *Y = X1;

    return gcd;
}

// Fast exponentiation for calculating a^b modulo m
uint64_t fastExponentiation(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t result = 1;
    while(b) {
        if(b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

// Generate a random prime number
uint64_t generatePrime() {
    uint64_t prime;
    do {
        prime = rand() % (1LL << 32);
    } while(!isPrime(prime));
    return prime;
}

// Generate a relative prime to phi(n)
uint64_t generateRelativePrime(uint64_t phi_n) {
    uint64_t relative_prime;
    do {
        relative_prime = rand() % (phi_n-2) + 2;
    } while(gcd(relative_prime, phi_n) != 1);
    return relative_prime;
}