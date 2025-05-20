//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    long long n; // Modulus
    long long e; // Public exponent
} PublicKey;

typedef struct {
    long long n; // Modulus
    long long d; // Private exponent
} PrivateKey;

// Function to compute gcd of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find the modular inverse
long long modInverse(long long a, long long m) {
    a = a % m;
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If no modular inverse
}

// Function to perform modular exponentiation
long long power(long long base, long long exp, long long mod) {
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

// Function to generate prime numbers using Sieve of Eratosthenes
void generatePrimes(int limit, int *primes, int *count) {
    int *isPrime = malloc(sizeof(int) * (limit + 1));
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = 1; // Assume all numbers are prime
    }
    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = 0;
            }
        }
    }

    *count = 0;
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) {
            primes[(*count)++] = i;
        }
    }
    free(isPrime);
}

// Function to generate RSA keys
void generateRSAKeys(PublicKey *pubKey, PrivateKey *privKey) {
    int primes[1000], primeCount;
    generatePrimes(100, primes, &primeCount);

    srand(time(NULL));
    int pIndex = rand() % primeCount;
    int qIndex;
    do {
        qIndex = rand() % primeCount;
    } while (pIndex == qIndex);

    long long p = primes[pIndex];
    long long q = primes[qIndex];

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 65537; // Commonly used prime
    while (gcd(e, phi) != 1) {
        e += 2; // Ensure e is odd
    }

    long long d = modInverse(e, phi);

    pubKey->n = n;
    pubKey->e = e;
    privKey->n = n;
    privKey->d = d;
}

// Function to encrypt the message
long long encrypt(long long message, PublicKey pubKey) {
    return power(message, pubKey.e, pubKey.n);
}

// Function to decrypt the message
long long decrypt(long long cipherText, PrivateKey privKey) {
    return power(cipherText, privKey.d, privKey.n);
}

// Main function to demonstrate RSA encryption and decryption
int main() {
    PublicKey pubKey;
    PrivateKey privKey;

    // Generate RSA keys
    generateRSAKeys(&pubKey, &privKey);

    printf("Public Key: (n: %lld, e: %lld)\n", pubKey.n, pubKey.e);
    printf("Private Key: (n: %lld, d: %lld)\n\n", privKey.n, privKey.d);

    long long message;
    printf("Enter a message to encrypt (numerical): ");
    scanf("%lld", &message);

    // Encrypt the message
    long long cipherText = encrypt(message, pubKey);
    printf("Encrypted Message: %lld\n", cipherText);

    // Decrypt the message
    long long decryptedMessage = decrypt(cipherText, privKey);
    printf("Decrypted Message: %lld\n", decryptedMessage);

    return 0;
}