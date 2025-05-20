//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <stdlib.h>
#include <stdio.h>

// Error handling macro
#define ERR_EXIT(err) do { \
    fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, ERR_error_string(err, NULL)); \
    exit(EXIT_FAILURE); \
} while (0)

// Generate a random AES-256 key
unsigned char *generate_aes_key(void) {
    unsigned char *key = malloc(32);
    if (!key) {
        ERR_EXIT(ERR_get_error());
    }
    if (RAND_bytes(key, 32) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    return key;
}

// Encrypt a message using AES-256 in CBC mode
unsigned char *aes_encrypt(unsigned char *plaintext, size_t plaintext_len, unsigned char *key) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        ERR_EXIT(ERR_get_error());
    }
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    unsigned char *ciphertext = malloc(plaintext_len + EVP_CIPHER_CTX_block_size(ctx));
    if (!ciphertext) {
        ERR_EXIT(ERR_get_error());
    }
    int ciphertext_len = 0;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext;
}

// Decrypt a message using AES-256 in CBC mode
unsigned char *aes_decrypt(unsigned char *ciphertext, size_t ciphertext_len, unsigned char *key) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        ERR_EXIT(ERR_get_error());
    }
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    unsigned char *plaintext = malloc(ciphertext_len + EVP_CIPHER_CTX_block_size(ctx));
    if (!plaintext) {
        ERR_EXIT(ERR_get_error());
    }
    int plaintext_len = 0;
    if (EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    if (EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len) != 1) {
        ERR_EXIT(ERR_get_error());
    }
    EVP_CIPHER_CTX_free(ctx);
    return plaintext;
}

int main(void) {
    ERR_load_crypto_strings();
    unsigned char *key = generate_aes_key();
    const char *plaintext = "Hello, world!";
    size_t plaintext_len = strlen(plaintext);
    unsigned char *ciphertext = aes_encrypt((unsigned char *)plaintext, plaintext_len, key);
    size_t ciphertext_len = strlen((char *)ciphertext);
    unsigned char *decryptedtext = aes_decrypt(ciphertext, ciphertext_len, key);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decryptedtext);
    free(key);
    free(ciphertext);
    free(decryptedtext);
    ERR_free_strings();
    return 0;
}