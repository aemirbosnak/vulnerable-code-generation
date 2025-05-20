//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>

// Generate a random prime number of the given bit length.
BIGNUM *generatePrime(int bitLength) {
    BIGNUM *prime = BN_new();
    while (1) {
        BN_generate_prime_ex(prime, bitLength, 1, NULL, NULL, NULL);
        if (BN_is_prime_ex(prime, 100, NULL, NULL) == 1) {
            break;
        }
    }
    return prime;
}

// Compute the modular inverse of x modulo m.
BIGNUM *modInv(BIGNUM *x, BIGNUM *m) {
    BIGNUM *inv = BN_new();
    BN_mod_inverse(inv, x, m, NULL);
    return inv;
}

// Generate a public and private key pair.
void generateKeyPair(BIGNUM *p, BIGNUM *q, BIGNUM **n, BIGNUM **e, BIGNUM **d) {
    *n = BN_new();
    BN_mul(*n, p, q, NULL);
    BIGNUM *phi = BN_new();
    BN_mul(phi, p, q, NULL);
    BN_sub_word(phi, 1);
    *e = BN_new();
    BN_set_word(*e, 65537);
    *d = modInv(*e, phi);
    BN_free(phi);
}

// Encrypt a message using RSA.
BIGNUM *encrypt(BIGNUM *m, BIGNUM *e, BIGNUM *n) {
    BIGNUM *c = BN_new();
    BN_mod_exp(c, m, e, n, NULL);
    return c;
}

// Decrypt a message using RSA.
BIGNUM *decrypt(BIGNUM *c, BIGNUM *d, BIGNUM *n) {
    BIGNUM *m = BN_new();
    BN_mod_exp(m, c, d, n, NULL);
    return m;
}

int main() {
    int bitLength = 1024;
    BIGNUM *p = generatePrime(bitLength);
    BIGNUM *q = generatePrime(bitLength);
    BIGNUM *n, *e, *d;
    generateKeyPair(p, q, &n, &e, &d);

    char *message = "Hello, world!";
    BIGNUM *m = BN_new();
    BN_bin2bn(message, strlen(message), m);
    BIGNUM *c = encrypt(m, e, n);
    BIGNUM *m2 = decrypt(c, d, n);

    char *decryptedMessage = malloc(BN_num_bytes(m2) + 1);
    BN_bn2bin(m2, decryptedMessage);
    decryptedMessage[BN_num_bytes(m2)] = '\0';

    printf("Original message: %s\n", message);
    printf("Encrypted message (in hexadecimal): ");
    BN_print_fp(stdout, c);
    printf("\n");
    printf("Decrypted message: %s\n", decryptedMessage);

    BN_free(p);
    BN_free(q);
    BN_free(n);
    BN_free(e);
    BN_free(d);
    BN_free(m);
    BN_free(c);
    BN_free(m2);
    free(decryptedMessage);
    return 0;
}