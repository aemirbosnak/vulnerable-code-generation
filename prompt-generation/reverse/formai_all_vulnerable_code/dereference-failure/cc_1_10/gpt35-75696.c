//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEYLEN 32
#define IVLEN 12

int main(int argc, char** argv) {
    unsigned char* plaintext = "Hello, world!";
    unsigned char key[KEYLEN];
    unsigned char iv[IVLEN];
    unsigned char* ciphertext = malloc(strlen(plaintext) + EVP_MAX_BLOCK_LENGTH);
    int ciphertextLen, plaintextLen = strlen(plaintext), totalLen = 0;
    EVP_CIPHER_CTX* ctx = NULL;

    // Generate a random key and IV
    if (RAND_bytes(key, KEYLEN) != 1 || RAND_bytes(iv, IVLEN) != 1) {
        fprintf(stderr, "Could not generate key and/or IV\n");
        return -1;
    }

    // Create the cipher context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Could not create cipher context\n");
        return -1;
    }

    // Initialize encryption
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, key, iv) != 1) {
        fprintf(stderr, "Could not initialize encryption\n");
        return -1;
    }

    // Encrypt the plaintext
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertextLen, plaintext, plaintextLen) != 1) {
        fprintf(stderr, "Encryption error\n");
        return -1;
    }
    totalLen += ciphertextLen;

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + totalLen, &ciphertextLen) != 1) {
        fprintf(stderr, "Encryption error\n");
        return -1;
    }
    totalLen += ciphertextLen;

    // Generate a tag for the ciphertext
    unsigned int tagLen;
    unsigned char tag[EVP_GCM_TLS_TAG_LEN];
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_GET_TAG, EVP_GCM_TLS_TAG_LEN, tag) != 1) {
        fprintf(stderr, "Could not generate tag\n");
        return -1;
    }
    totalLen += EVP_GCM_TLS_TAG_LEN;

    // Print the ciphertext and tag
    printf("Ciphertext (hex):\n");
    for (int i = 0; i < totalLen; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\nTag (hex):\n");
    for (int i = 0; i < EVP_GCM_TLS_TAG_LEN; i++) {
        printf("%02x", tag[i]);
    }
    printf("\n");

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}