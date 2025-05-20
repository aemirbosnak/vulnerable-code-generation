//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PRIME_LENGTH 8
#define MAX_ITERATIONS 1000

// Utility function to calculate GCD of two numbers
uint64_t gcd(uint64_t a, uint64_t b) {
    uint64_t temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Utility function to calculate modular exponentiation
uint64_t mod_exp(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

// Generate large prime number
uint64_t generate_prime_number(void) {
    int is_prime = 0;
    int iterations;
    uint64_t randomNumber;
    uint64_t randomNumberCandidate;
    while (!is_prime) {
        randomNumberCandidate = rand();
        randomNumber = (randomNumberCandidate % 100) + 1;
        is_prime = 1;
        for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
            uint64_t randomNumberCandidateMinusOne = randomNumberCandidate - 1;
            uint64_t a = (rand() % (randomNumberCandidateMinusOne)) + 1;
            if (gcd(a, randomNumberCandidate) != 1) {
                is_prime = 0;
            }
            if (mod_exp(a, randomNumberCandidateMinusOne, randomNumberCandidate) != 1) {
                is_prime = 0;
            }
            if (is_prime == 0) {
                break;
            }
        }
    }
    return randomNumber;
}

// Encrypt the given message
uint64_t encrypt_message(uint64_t message, uint64_t e, uint64_t n) {
    uint64_t encrypted_message;
    encrypted_message = mod_exp(message, e, n);
    return encrypted_message;
}

// Decrypt the given message
uint64_t decrypt_message(uint64_t message, uint64_t d, uint64_t n) {
    uint64_t decrypted_message;
    decrypted_message = mod_exp(message, d, n);
    return decrypted_message;
}

int main() {
    uint64_t p, q, n, phi, e, d, message, encrypted_message, decrypted_message;

    // Generate two prime numbers
    p = generate_prime_number();
    q = generate_prime_number();
    printf("p: %llu\n", p);
    printf("q: %llu\n", q);

    // Compute modulus N and totient phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose an encryption exponent e
    e = 65537;

    // Compute decryption exponent d using the extended Euclidean algorithm
    d = 0;
    while (gcd(e, phi) != 1) {
        e++;
    }
    uint64_t temp_phi = phi;
    uint64_t x = 0, y = 1;
    uint64_t lastx = 1, lasty = 0;
    uint64_t quotient, remainder;

    while (temp_phi != 0) {
        quotient = e / temp_phi;
        remainder = e % temp_phi;
        e = temp_phi;
        temp_phi = remainder;

        uint64_t newx = lastx - quotient * x;
        lastx = x;
        x = newx;

        uint64_t newy = lasty - quotient * y;
        lasty = y;
        y = newy;
    }

    // Compute message to be encrypted
    printf("Enter the message to be encrypted: ");
    scanf("%llu", &message);

    // Encrypt message
    encrypted_message = encrypt_message(message, e, n);
    printf("Encrypted message: %llu\n", encrypted_message);

    // Decrypt message
    decrypted_message = decrypt_message(encrypted_message, lastx + phi, n);
    printf("Decrypted message: %llu\n", decrypted_message);

    return 0;
}