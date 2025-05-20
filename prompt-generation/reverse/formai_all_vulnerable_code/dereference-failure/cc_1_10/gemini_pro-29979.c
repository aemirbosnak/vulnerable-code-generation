//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

typedef struct {
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    int key_len;
    int iv_len;
} cipher_t;

void cipher_init(cipher_t *cipher, const char *cipher_name, const unsigned char *key, int key_len, const unsigned char *iv, int iv_len) {
    cipher->ctx = EVP_CIPHER_CTX_new();
    if (cipher->ctx == NULL) {
        fprintf(stderr, "EVP_CIPHER_CTX_new() failed\n");
        exit(1);
    }

    const EVP_CIPHER *cipher_type = EVP_get_cipherbyname(cipher_name);
    if (cipher_type == NULL) {
        fprintf(stderr, "EVP_get_cipherbyname() failed\n");
        exit(1);
    }

    if (!EVP_CipherInit_ex(cipher->ctx, cipher_type, NULL, key, iv, 1)) {
        fprintf(stderr, "EVP_CipherInit_ex() failed\n");
        exit(1);
    }

    cipher->key_len = key_len;
    cipher->iv_len = iv_len;
}

void cipher_update(cipher_t *cipher, const unsigned char *input, int input_len, unsigned char *output, int *output_len) {
    int out_len = 0;
    if (!EVP_CipherUpdate(cipher->ctx, output, &out_len, input, input_len)) {
        fprintf(stderr, "EVP_CipherUpdate() failed\n");
        exit(1);
    }
    *output_len = out_len;
}

void cipher_final(cipher_t *cipher, unsigned char *output, int *output_len) {
    int out_len = 0;
    if (!EVP_CipherFinal_ex(cipher->ctx, output, &out_len)) {
        fprintf(stderr, "EVP_CipherFinal_ex() failed\n");
        exit(1);
    }
    *output_len = out_len;
}

void cipher_cleanup(cipher_t *cipher) {
    EVP_CIPHER_CTX_free(cipher->ctx);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s cipher_name key iv plaintext\n", argv[0]);
        exit(1);
    }

    const char *cipher_name = argv[1];
    const unsigned char *key = (const unsigned char *)argv[2];
    int key_len = strlen(argv[2]);
    const unsigned char *iv = (const unsigned char *)argv[3];
    int iv_len = strlen(argv[3]);
    const unsigned char *plaintext = (const unsigned char *)argv[4];
    int plaintext_len = strlen(argv[4]);

    cipher_t cipher;
    cipher_init(&cipher, cipher_name, key, key_len, iv, iv_len);

    unsigned char ciphertext[plaintext_len + EVP_MAX_BLOCK_LENGTH];
    int ciphertext_len = 0;
    cipher_update(&cipher, plaintext, plaintext_len, ciphertext, &ciphertext_len);
    cipher_final(&cipher, ciphertext + ciphertext_len, &ciphertext_len);

    printf("Ciphertext: %s\n", ciphertext);

    cipher_cleanup(&cipher);

    return 0;
}