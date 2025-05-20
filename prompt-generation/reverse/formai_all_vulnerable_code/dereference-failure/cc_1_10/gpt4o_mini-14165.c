//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Generate a random prime number using the Sieve of Eratosthenes
void generate_prime(int *prime, int start, int end) {
    int *sieve = malloc((end + 1) * sizeof(int));
    for (int i = 0; i <= end; i++) sieve[i] = 1; // Initialize all entries as prime

    for (int i = 2; i <= sqrt(end); i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= end; j += i) {
                sieve[j] = 0; // Not a prime number
            }
        }
    }

    // Collect all prime numbers in the given range
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (sieve[i] && i > 1) {
            prime[count++] = i;
        }
    }
    free(sieve);
}

// Compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Compute modular inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0; // No inverse if m=1

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to calculate (base^exp) mod mod using binary exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply base with result
            result = (result * base) % mod;

        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod; // base = base^2
    }
    return result;
}

// RSA Structure Definition
typedef struct {
    int e; // public exponent
    int d; // private exponent
    int n; // modulus
} RSAKeyPair;

// Generate RSA Key Pair
void generate_rsa_key_pair(RSAKeyPair *keypair, int prime1, int prime2) {
    keypair->n = prime1 * prime2; // n = p * q
    int phi = (prime1 - 1) * (prime2 - 1); // φ(n)

    // Choose e
    keypair->e = 65537; // Common choice for e

    // Compute d, the modular inverse of e % φ(n)
    keypair->d = mod_inverse(keypair->e, phi);
}

// RSA Encryption
long long rsa_encrypt(long long plaintext, RSAKeyPair *keypair) {
    return mod_exp(plaintext, keypair->e, keypair->n);
}

// RSA Decryption
long long rsa_decrypt(long long ciphertext, RSAKeyPair *keypair) {
    return mod_exp(ciphertext, keypair->d, keypair->n);
}

int main() {
    int prime_range_start = 1000;
    int prime_range_end = 5000;
    int primes[1000];
    
    // Generate prime numbers
    generate_prime(primes, prime_range_start, prime_range_end);

    // For RSA, we need two distinct prime numbers
    int prime1 = primes[rand() % (sizeof(primes) / sizeof(primes[0]))];
    int prime2;
    do {
        prime2 = primes[rand() % (sizeof(primes) / sizeof(primes[0]))];
    } while (prime1 == prime2); // Ensure distinct primes

    printf("Selected Prime 1: %d\n", prime1);
    printf("Selected Prime 2: %d\n", prime2);

    RSAKeyPair keypair;
    generate_rsa_key_pair(&keypair, prime1, prime2);

    printf("Public Key (e, n): (%d, %d)\n", keypair.e, keypair.n);
    printf("Private Key (d, n): (%d, %d)\n\n", keypair.d, keypair.n);

    long long plaintext = 1234; // Example plaintext
    printf("Plaintext: %lld\n", plaintext);

    long long ciphertext = rsa_encrypt(plaintext, &keypair);
    printf("Ciphertext: %lld\n", ciphertext);

    long long decryptedtext = rsa_decrypt(ciphertext, &keypair);
    printf("Decrypted Text: %lld\n", decryptedtext);

    return 0;
}