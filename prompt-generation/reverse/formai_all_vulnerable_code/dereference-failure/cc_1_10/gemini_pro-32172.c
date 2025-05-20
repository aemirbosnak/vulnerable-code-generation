//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <cipher> <key> <plaintext>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the cipher context
    const EVP_CIPHER *cipher = EVP_get_cipherbyname(argv[1]);
    if (cipher == NULL) {
        fprintf(stderr, "Unknown cipher: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Initialize the cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error initializing cipher context\n");
        return EXIT_FAILURE;
    }

    // Set the key and IV
    unsigned char key[EVP_CIPHER_key_length(cipher)];
    unsigned char iv[EVP_CIPHER_iv_length(cipher)];
    if (!EVP_BytesToKey(cipher, EVP_md5(), NULL, argv[2], strlen(argv[2]), 1, key, iv)) {
        fprintf(stderr, "Error setting key and IV\n");
        return EXIT_FAILURE;
    }

    // Encrypt the plaintext
    int plaintext_len = strlen(argv[3]);
    unsigned char ciphertext[BUFSIZE];
    int ciphertext_len;
    if (!EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv)) {
        fprintf(stderr, "Error initializing encryption\n");
        return EXIT_FAILURE;
    }
    if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, argv[3], plaintext_len)) {
        fprintf(stderr, "Error encrypting data\n");
        return EXIT_FAILURE;
    }
    int final_len;
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len)) {
        fprintf(stderr, "Error finalizing encryption\n");
        return EXIT_FAILURE;
    }
    ciphertext_len += final_len;

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return EXIT_SUCCESS;
}