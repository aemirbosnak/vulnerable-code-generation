//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <openssl/rand.h>
#include <openssl/bn.h>

typedef struct {
    BIGNUM *n;
    BIGNUM *e;
    BIGNUM *d;
    BIGNUM *p;
    BIGNUM *q;
} RSA_KEY;

RSA_KEY *rsa_generate_key(int bits) {
    RSA_KEY *key = malloc(sizeof(RSA_KEY));

    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();

    BN_generate_prime_ex(p, bits / 2, 0, NULL, NULL, NULL);
    BN_generate_prime_ex(q, bits / 2, 0, NULL, NULL, NULL);

    key->n = BN_new();
    BN_mul(key->n, p, q, NULL);

    BIGNUM *phi_n = BN_new();
    BN_sub(p, p, BN_value_one());
    BN_sub(q, q, BN_value_one());
    BN_mul(phi_n, p, q, NULL);

    key->e = BN_new();
    BN_set_word(key->e, 65537);

    BIGNUM *gcd = BN_new();
    BN_gcd(gcd, key->e, phi_n, NULL);

    if (!BN_is_one(gcd)) {
        RSA_free(key);
        return NULL;
    }

    key->d = BN_new();
    BN_mod_inverse(key->d, key->e, phi_n, NULL);

    key->p = p;
    key->q = q;

    return key;
}

int rsa_encrypt(RSA_KEY *key, uint8_t *plaintext, int plaintext_len, uint8_t **ciphertext, int *ciphertext_len) {
    BIGNUM *m = BN_new();
    BN_bin2bn(plaintext, plaintext_len, m);

    BIGNUM *c = BN_new();
    BN_mod_exp(c, m, key->e, key->n, NULL);

    *ciphertext_len = BN_num_bytes(c);
    *ciphertext = malloc(*ciphertext_len);
    BN_bn2bin(c, *ciphertext);

    BN_free(m);
    BN_free(c);

    return 0;
}

int rsa_decrypt(RSA_KEY *key, uint8_t *ciphertext, int ciphertext_len, uint8_t **plaintext, int *plaintext_len) {
    BIGNUM *c = BN_new();
    BN_bin2bn(ciphertext, ciphertext_len, c);

    BIGNUM *m = BN_new();
    BN_mod_exp(m, c, key->d, key->n, NULL);

    *plaintext_len = BN_num_bytes(m);
    *plaintext = malloc(*plaintext_len);
    BN_bn2bin(m, *plaintext);

    BN_free(c);
    BN_free(m);

    return 0;
}

void rsa_free(RSA_KEY *key) {
    BN_free(key->n);
    BN_free(key->e);
    BN_free(key->d);
    BN_free(key->p);
    BN_free(key->q);
    free(key);
}

int main() {
    RSA_KEY *key = rsa_generate_key(2048);

    uint8_t plaintext[] = "Hello, world!";
    int plaintext_len = strlen(plaintext);

    uint8_t *ciphertext;
    int ciphertext_len;

    rsa_encrypt(key, plaintext, plaintext_len, &ciphertext, &ciphertext_len);

    uint8_t *decryptedtext;
    int decryptedtext_len;

    rsa_decrypt(key, ciphertext, ciphertext_len, &decryptedtext, &decryptedtext_len);

    if (plaintext_len != decryptedtext_len || memcmp(plaintext, decryptedtext, plaintext_len) != 0) {
        printf("Encryption/decryption failed.\n");
    } else {
        printf("Encryption/decryption successful.\n");
    }

    rsa_free(key);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}