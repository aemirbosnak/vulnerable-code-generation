//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define ENCRYPTION_BLOCK_SIZE 16

struct cipher_context {
    EVP_CIPHER_CTX *encrypt_ctx;
    EVP_CIPHER_CTX *decrypt_ctx;
    uint8_t key[EVP_MAX_KEY_LENGTH];
    uint8_t iv[ENCRYPTION_BLOCK_SIZE];
};

struct cipher_context *cipher_context_new(const char *key, const char *iv)
{
    struct cipher_context *ctx = malloc(sizeof(struct cipher_context));
    if (!ctx)
        return NULL;

    memcpy(ctx->key, key, strlen(key));
    memcpy(ctx->iv, iv, ENCRYPTION_BLOCK_SIZE);

    ctx->encrypt_ctx = EVP_CIPHER_CTX_new();
    if (!ctx->encrypt_ctx) {
        free(ctx);
        return NULL;
    }

    ctx->decrypt_ctx = EVP_CIPHER_CTX_new();
    if (!ctx->decrypt_ctx) {
        EVP_CIPHER_CTX_free(ctx->encrypt_ctx);
        free(ctx);
        return NULL;
    }

    return ctx;
}

void cipher_context_free(struct cipher_context *ctx)
{
    EVP_CIPHER_CTX_free(ctx->encrypt_ctx);
    EVP_CIPHER_CTX_free(ctx->decrypt_ctx);
    free(ctx);
}

int cipher_encrypt(struct cipher_context *ctx, const void *plaintext, size_t plaintext_len, void *ciphertext, size_t ciphertext_len)
{
    int outlen;

    if (EVP_EncryptInit_ex(ctx->encrypt_ctx, EVP_aes_256_cbc(), NULL, ctx->key, ctx->iv) != 1)
        return -1;

    if (EVP_EncryptUpdate(ctx->encrypt_ctx, ciphertext, &outlen, plaintext, plaintext_len) != 1)
        return -1;

    if (EVP_EncryptFinal_ex(ctx->encrypt_ctx, ciphertext + outlen, &outlen) != 1)
        return -1;

    return 0;
}

int cipher_decrypt(struct cipher_context *ctx, const void *ciphertext, size_t ciphertext_len, void *plaintext, size_t plaintext_len)
{
    int outlen;

    if (EVP_DecryptInit_ex(ctx->decrypt_ctx, EVP_aes_256_cbc(), NULL, ctx->key, ctx->iv) != 1)
        return -1;

    if (EVP_DecryptUpdate(ctx->decrypt_ctx, plaintext, &outlen, ciphertext, ciphertext_len) != 1)
        return -1;

    if (EVP_DecryptFinal_ex(ctx->decrypt_ctx, plaintext + outlen, &outlen) != 1)
        return -1;

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <key> <iv> <message>\n", argv[0]);
        return 1;
    }

    struct cipher_context *ctx = cipher_context_new(argv[1], argv[2]);
    if (!ctx) {
        fprintf(stderr, "Failed to create cipher context\n");
        return 1;
    }

    size_t ciphertext_len = strlen(argv[3]) + 1;
    uint8_t *ciphertext = malloc(ciphertext_len);
    if (!ciphertext) {
        fprintf(stderr, "Failed to allocate memory for ciphertext\n");
        cipher_context_free(ctx);
        return 1;
    }

    if (cipher_encrypt(ctx, argv[3], strlen(argv[3]), ciphertext, ciphertext_len) != 0) {
        fprintf(stderr, "Failed to encrypt message\n");
        free(ciphertext);
        cipher_context_free(ctx);
        return 1;
    }

    uint8_t *plaintext = malloc(ciphertext_len);
    if (!plaintext) {
        fprintf(stderr, "Failed to allocate memory for plaintext\n");
        free(ciphertext);
        cipher_context_free(ctx);
        return 1;
    }

    if (cipher_decrypt(ctx, ciphertext, ciphertext_len, plaintext, ciphertext_len) != 0) {
        fprintf(stderr, "Failed to decrypt message\n");
        free(plaintext);
        free(ciphertext);
        cipher_context_free(ctx);
        return 1;
    }

    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: %s\n", plaintext);

    free(plaintext);
    free(ciphertext);
    cipher_context_free(ctx);

    return 0;
}