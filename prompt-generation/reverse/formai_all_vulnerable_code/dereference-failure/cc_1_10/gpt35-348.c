//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define PRIME_SIZE 16
#define INT_SIZE sizeof(int32_t)

typedef struct PublicKey {
    uint32_t n;
    uint32_t e;
} PublicKey;

typedef struct PrivateKey {
    uint32_t n;
    uint32_t d;
} PrivateKey;

int miller_rabin(uint32_t n, uint32_t a);
PrivateKey* create_private_key(uint32_t p, uint32_t q);
uint32_t modular_pow(uint32_t base, uint32_t exponent, uint32_t modulus);
PublicKey* create_public_key(uint32_t p, uint32_t q);
void encrypt(uint32_t message, PublicKey* pubkey);
uint32_t decrypt(uint32_t ciphertext, PrivateKey* privkey);

int main() {
    srand(time(NULL));
    uint32_t p = rand() % (1 << PRIME_SIZE);
    while (!miller_rabin(p, 2)) {
        p = rand() % (1 << PRIME_SIZE);
    }
    uint32_t q = rand() % (1 << PRIME_SIZE);
    while (!miller_rabin(q, 2)) {
        q = rand() % (1 << PRIME_SIZE);
    }
    printf("p: %u\nq: %u\n", p, q);
    PublicKey* pubkey = create_public_key(p, q);
    PrivateKey* privkey = create_private_key(p, q);
    printf("Public Key (n, e): (%u, %u)\n", pubkey->n, pubkey->e);
    printf("Private Key (n, d): (%u, %u)\n", privkey->n, privkey->d);

    uint32_t message = rand() % pubkey->n;
    printf("Message to encrypt: %u\n", message);
    encrypt(message, pubkey);

    uint32_t ciphertext = rand() % pubkey->n;
    printf("Ciphertext to decrypt: %u\n", ciphertext);
    uint32_t decrypted_message = decrypt(ciphertext, privkey);
    printf("Decrypted message: %u\n", decrypted_message);

    free(pubkey);
    free(privkey);
    return 0;
}

// Miller-Rabin primality test
int miller_rabin(uint32_t n, uint32_t a) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    uint32_t s = 0, d = n - 1;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }
    uint32_t x = modular_pow(a, d, n);
    if (x == 1 || x == n - 1) return 1;
    for (int i = 0; i < s - 1; i++) {
        x = modular_pow(x, 2, n);
        if (x == n - 1) return 1;
    }
    return 0;
}

// Create private key
PrivateKey* create_private_key(uint32_t p, uint32_t q) {
    PrivateKey* privkey = (PrivateKey*) malloc(sizeof(PrivateKey));
    privkey->n = p * q;
    uint32_t phi = (p - 1) * (q - 1);
    uint32_t e = 65537;
    while (e < phi) {
        if (miller_rabin(phi / e, 2)) {
            privkey->d = e;
            break;
        }
        e++;
    }
    return privkey;
}

// Modular exponentiation
uint32_t modular_pow(uint32_t base, uint32_t exponent, uint32_t modulus) {
    if (modulus == 1) return 0;
    uint32_t result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

// Create public key
PublicKey* create_public_key(uint32_t p, uint32_t q) {
    PublicKey* pubkey = (PublicKey*) malloc(sizeof(PublicKey));
    pubkey->n = p * q;
    pubkey->e = 65537;
    return pubkey;
}

// Encrypt message
void encrypt(uint32_t message, PublicKey* pubkey) {
    uint32_t ciphertext = modular_pow(message, pubkey->e, pubkey->n);
    printf("Ciphertext: %u\n", ciphertext);
}

// Decrypt ciphertext
uint32_t decrypt(uint32_t ciphertext, PrivateKey* privkey) {
    uint32_t message = modular_pow(ciphertext, privkey->d, privkey->n);
    return message;
}