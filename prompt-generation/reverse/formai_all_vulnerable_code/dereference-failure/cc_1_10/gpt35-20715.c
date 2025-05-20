//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdbool.h>

#define AES_KEY_SIZE 32
#define BLOCK_SIZE 16

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <plaintext> <key> <iv>\n", argv[0]);
        exit(1);
    }

    OpenSSL_add_all_algorithms();
    uint8_t *plaintext = (uint8_t *) argv[1];
    uint8_t *key = (uint8_t *) argv[2];
    uint8_t *iv = (uint8_t *) argv[3];
    uint8_t ciphertext[sizeof(plaintext) + BLOCK_SIZE];
    uint8_t decrypted[sizeof(plaintext)];
    int ciphertext_len, decrypted_len;

    // Encryption
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating encryption context.\n");
        exit(1);
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing encryption.\n");
        exit(1);
    }

    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen((char *) plaintext)) != 1) {
        fprintf(stderr, "Error encrypting.\n");
        exit(1);
    }

    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        fprintf(stderr, "Error encrypting.\n");
        exit(1);
    }

    ciphertext_len += BLOCK_SIZE;

    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decryption
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing decryption.\n");
        exit(1);
    }

    if (EVP_DecryptUpdate(ctx, decrypted, &decrypted_len, ciphertext, ciphertext_len) != 1) {
        fprintf(stderr, "Error decrypting.\n");
        exit(1);
    }

    if (EVP_DecryptFinal_ex(ctx, decrypted + decrypted_len, &decrypted_len) != 1) {
        fprintf(stderr, "Error decrypting.\n");
        exit(1);
    }

    printf("Decrypted text: %s\n", decrypted);

    EVP_CIPHER_CTX_cleanup(ctx);
    return 0;
}