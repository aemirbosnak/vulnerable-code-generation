//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Define the key size for AES encryption
#define AES_KEY_SIZE 256

// Function to encrypt a string using AES in CBC mode
void encrypt_string(const char *plaintext, const char *key, char *ciphertext) {
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char *pt = (unsigned char *) plaintext;
    unsigned char *ct = (unsigned char *) ciphertext;
    unsigned char *key_data = (unsigned char *) key;
    EVP_CIPHER_CTX *ctx;
    int len = strlen(plaintext);
    int iv_length = EVP_MAX_IV_LENGTH;

    // Generate the initialization vector (IV)
    if (RAND_bytes(iv, iv_length) <= 0) {
        printf("Error generating IV\n");
        return;
    }

    // Create the cipher context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating cipher context\n");
        return;
    }

    // Initialize the cipher context with the key and IV
    if (1!= EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_data, iv)) {
        printf("Error initializing cipher\n");
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    // Encrypt the plaintext
    if (1!= EVP_EncryptUpdate(ctx, ct, &len, pt, len)) {
        printf("Error encrypting plaintext\n");
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    // Finalize the encryption
    if (1!= EVP_EncryptFinal_ex(ctx, ct + len, NULL)) {
        printf("Error finalizing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    // Free the cipher context
    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        return 1;
    }

    const char *plaintext = argv[1];
    const char *key = argv[2];
    char ciphertext[EVP_MAX_IV_LENGTH + 256]; // 256 bytes for ciphertext

    encrypt_string(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}