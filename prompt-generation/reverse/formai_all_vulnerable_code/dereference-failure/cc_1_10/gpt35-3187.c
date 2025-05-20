//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    unsigned char buffer[BUFFER_SIZE];
    unsigned char *plaintext, *ciphertext;
    int plaintext_length, ciphertext_length;
    int i;

    if (argc != 2) {
        printf("Usage: %s <text_to_encrypt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    plaintext = (unsigned char *) argv[1];
    plaintext_length = strlen((char *) plaintext);

    // Generate random key and IV
    RAND_bytes(key, EVP_MAX_KEY_LENGTH);
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);

    // Allocate memory for ciphertext
    ciphertext = malloc(plaintext_length + EVP_CIPHER_block_size(EVP_aes_256_cbc()));

    // Create and initialize context
    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    // Set up encryption
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_length, plaintext, plaintext_length);

    // Finalize encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &i);
    ciphertext_length += i;

    printf("Plaintext:\n%s\n\n", plaintext);
    printf("Key:\n");
    for (i = 0; i < EVP_MAX_KEY_LENGTH; i++) {
        printf("%02x", key[i]);
    }
    printf("\n\nIV:\n");
    for (i = 0; i < EVP_MAX_IV_LENGTH; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n\nCiphertext:\n");
    for (i = 0; i < ciphertext_length; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}