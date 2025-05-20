//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1;
    long long half = mod_exp(base, exp / 2, mod);
    long long half_sq = (half * half) % mod;
    if (exp % 2 == 0)
        return half_sq;
    return (base * half_sq) % mod;
}

// Function to find the modular multiplicative inverse
long long mod_inverse(int e, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1)
            return x;
    }
    return -1; // This should not happen for valid RSA keys
}

// Recursive function to generate prime numbers (simple sieve method)
void generate_primes(int n, int *primes, int *count) {
    if (n < 2) return;

    int *is_prime = (int *)malloc((n + 1) * sizeof(int));
    memset(is_prime, 1, (n + 1) * sizeof(int));
    
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = 0;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[*count] = i;
            (*count)++;
        }
    }
    free(is_prime);
}

// Helper function to find two distinct prime numbers
void find_distinct_primes(int *p, int *q) {
    int primes[1000], count = 0;
    generate_primes(1000, primes, &count);
    *p = primes[rand() % count];
    *q = primes[rand() % count];
    while (*q == *p) {
        *q = primes[rand() % count];
    }
}

// RSA Key Generation
void generate_keys(int *e, int *d, int *n) {
    int p, q;
    find_distinct_primes(&p, &q);
    
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    
    // Choose e
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }
    
    // Calculate d
    *d = mod_inverse(*e, phi);
}

// RSA Encryption
long long rsa_encrypt(long long message, int e, int n) {
    return mod_exp(message, e, n);
}

// RSA Decryption
long long rsa_decrypt(long long cipher, int d, int n) {
    return mod_exp(cipher, d, n);
}

// Main function
int main() {
    srand(time(NULL));
    int e, d, n;

    // Generate RSA keys
    generate_keys(&e, &d, &n);
    
    printf("Public Key: (e=%d, n=%d)\n", e, n);
    printf("Private Key: (d=%d, n=%d)\n", d, n);

    // Example message
    long long message = 123; // message to encrypt
    printf("Original Message: %lld\n", message);
    
    // Encrypt message
    long long cipher = rsa_encrypt(message, e, n);
    printf("Encrypted Cipher: %lld\n", cipher);
    
    // Decrypt message
    long long decrypted_message = rsa_decrypt(cipher, d, n);
    printf("Decrypted Message: %lld\n", decrypted_message);

    return 0;
}