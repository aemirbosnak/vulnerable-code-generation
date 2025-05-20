//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to perform modulo exponentiation
long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to compute gcd using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find modular inverse using Extended Euclidean Algorithm
long long mod_inverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) x += m0;

    return x;
}

// Function to generate prime numbers using Sieve of Eratosthenes
void sieve_of_eratosthenes(int limit, int *primes, int *prime_count) {
    int *is_prime = (int *)malloc((limit + 1) * sizeof(int));
    memset(is_prime, 1, (limit + 1) * sizeof(int));
    is_prime[0] = is_prime[1] = 0;

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = 0;
            }
        }
    }
    
    *prime_count = 0;
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            primes[(*prime_count)++] = p;
        }
    }
    free(is_prime);
}

// Function to generate RSA keys
void rsa_generate_keys(long long *public_key, long long *private_key, long long *n) {
    int primes[1000];
    int prime_count = 0;
    sieve_of_eratosthenes(10000, primes, &prime_count);

    long long p = primes[rand() % prime_count];
    long long q = primes[rand() % prime_count];
    
    while (p == q) {
        q = primes[rand() % prime_count];
    }

    *n = p * q;
    long long phi_n = (p - 1) * (q - 1);

    *public_key = 65537; // commonly used prime for e
    *private_key = mod_inverse(*public_key, phi_n);
}

// Function to encrypt the message
long long rsa_encrypt(long long message, long long public_key, long long n) {
    return modular_exponentiation(message, public_key, n);
}

// Function to decrypt the message
long long rsa_decrypt(long long ciphertext, long long private_key, long long n) {
    return modular_exponentiation(ciphertext, private_key, n);
}

int main() {
    srand(time(NULL));

    long long public_key, private_key, n;
    rsa_generate_keys(&public_key, &private_key, &n);
    
    printf("Public Key: %lld\n", public_key);
    printf("Private Key: %lld\n", private_key);
    printf("n: %lld\n", n);
    
    long long message;
    printf("Enter a message to encrypt (numeric value): ");
    scanf("%lld", &message);

    long long ciphertext = rsa_encrypt(message, public_key, n);
    printf("Ciphertext: %lld\n", ciphertext);

    long long decrypted_message = rsa_decrypt(ciphertext, private_key, n);
    printf("Decrypted Message: %lld\n", decrypted_message);

    return 0;
}