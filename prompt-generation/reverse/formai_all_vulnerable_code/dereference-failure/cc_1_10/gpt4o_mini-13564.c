//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long long n; // Modulus
    long long e; // Public exponent
    long long d; // Private exponent
} RSAKeyPair;

// Function to calculate the greatest common divisor.
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate modular inverse using Extended Euclidean Algorithm.
long long mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to generate prime numbers using Sieve of Eratosthenes.
void generate_primes(int limit, int *primes, int *count) {
    int *is_prime = (int *)malloc((limit + 1) * sizeof(int));
    memset(is_prime, 1, (limit + 1) * sizeof(int));

    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not primes.

    for (int i = 2; i <= sqrt(limit); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    *count = 0;
    for (int i = 0; i <= limit; i++) {
        if (is_prime[i]) {
            primes[(*count)++] = i;
        }
    }

    free(is_prime);
}

// Function to generate RSA key pair.
RSAKeyPair generate_rsa_keypair(int prime_limit) {
    RSAKeyPair keys;
    int primes[prime_limit];
    int prime_count;

    generate_primes(prime_limit, primes, &prime_count);
    int p = primes[rand() % prime_count];
    int q = primes[rand() % prime_count];

    keys.n = p * q;
    long long phi = (p - 1) * (q - 1);

    // Choosing e
    keys.e = 3;
    while (gcd(keys.e, phi) != 1) {
        keys.e += 2; // Make e odd
    }

    // Calculating d
    keys.d = mod_inverse(keys.e, phi);

    return keys;
}

// Function to encrypt the message using RSA.
long long rsa_encrypt(long long message, long long e, long long n) {
    long long result = 1;
    for (long long i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Function to decrypt the message using RSA.
long long rsa_decrypt(long long ciphertext, long long d, long long n) {
    long long result = 1;
    for (long long i = 0; i < d; i++) {
        result = (result * ciphertext) % n;
    }
    return result;
}

int main() {
    srand(time(NULL));

    int prime_limit = 100; // Limit within which to find primes
    RSAKeyPair keys = generate_rsa_keypair(prime_limit);

    printf("Generated RSA Key Pair:\n");
    printf("Public Key (n, e): (%lld, %lld)\n", keys.n, keys.e);
    printf("Private Key (d): %lld\n", keys.d);

    // Example plaintext message
    long long message = 42;
    printf("Original message: %lld\n", message);

    // Encrypt the message
    long long encrypted_message = rsa_encrypt(message, keys.e, keys.n);
    printf("Encrypted message: %lld\n", encrypted_message);

    // Decrypt the message
    long long decrypted_message = rsa_decrypt(encrypted_message, keys.d, keys.n);
    printf("Decrypted message: %lld\n", decrypted_message);

    // Verification
    if (message == decrypted_message) {
        printf("Success! The decrypted message matches the original message.\n");
    } else {
        printf("Error! The decrypted message does not match the original message.\n");
    }

    return 0;
}