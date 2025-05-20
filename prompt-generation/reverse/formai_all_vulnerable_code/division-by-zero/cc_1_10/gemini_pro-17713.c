//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ** Demonstration of a Minimal & Naive Implementation of a Public-Key Algorithm **

// ** Utilities **

// Calculate modular exponentiation using binary exponentiation (Montgomery Method)
unsigned long long modExp(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Generate a random prime number of a given bit length
unsigned long long generatePrime(int bitLength) {
    unsigned long long candidate;
    do {
        candidate = (rand() % (1 << bitLength)) | (1 << (bitLength - 1)); // Generate an odd number
        // Perform primality test using Fermat's Little Theorem
        if (modExp(2, candidate - 1, candidate) != 1) {
            continue; // Not prime, try again
        }
    } while (candidate % 3 == 0 || candidate % 5 == 0 || candidate % 7 == 0); // Eliminate small primes
    return candidate;
}

// Calculate the modular inverse of a number using the Extended Euclidean Algorithm
unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    int r0 = a, r1 = m, x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    while (r1 != 0) {
        int q = r0 / r1;
        int r = r0 % r1;
        r0 = r1;
        r1 = r;
        int x = x0 - q * x1;
        x0 = x1;
        x1 = x;
        int y = y0 - q * y1;
        y0 = y1;
        y1 = y;
    }
    return (x0 + m) % m;
}

// ** Key Generation **

// Generate a public key (e, n) and a private key (d, n)
void generateKeys(unsigned long long* e, unsigned long long* d, unsigned long long* n, int keySize) {
    // Generate two distinct large primes, p and q
    unsigned long long p = generatePrime(keySize / 2);
    unsigned long long q = generatePrime(keySize / 2);
    while (p == q) {
        q = generatePrime(keySize / 2);
    }
    // Calculate the modulus n = p * q
    *n = p * q;
    // Calculate the totient of n, φ(n) = (p - 1) * (q - 1)
    unsigned long long phi_n = (p - 1) * (q - 1);
    // Choose a public exponent, e, that is relatively prime to φ(n)
    *e = 65537; // Commonly used value
    // Calculate the private exponent, d, using the modular inverse
    *d = modInverse(*e, phi_n);
}

// ** Encryption **

// Encrypt a plaintext message using the public key
unsigned long long encrypt(unsigned long long plaintext, unsigned long long e, unsigned long long n) {
    return modExp(plaintext, e, n);
}

// ** Decryption **

// Decrypt a ciphertext using the private key
unsigned long long decrypt(unsigned long long ciphertext, unsigned long long d, unsigned long long n) {
    return modExp(ciphertext, d, n);
}

// ** Main **

int main() {
    // Generate key size (in bits)
    int keySize = 2048;
    // Generate public and private keys
    unsigned long long e, d, n;
    generateKeys(&e, &d, &n, keySize);

    // Message to be encrypted
    unsigned long long plaintext = 123456789;

    // ** Encryption **
    unsigned long long ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted Message: %llu\n", ciphertext);

    // ** Decryption **
    unsigned long long decryptedText = decrypt(ciphertext, d, n);
    printf("Decrypted Message: %llu\n", decryptedText);

    return 0;
}