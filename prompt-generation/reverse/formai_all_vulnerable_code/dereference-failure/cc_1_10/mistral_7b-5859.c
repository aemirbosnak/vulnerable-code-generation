//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define BUFFER_SIZE 256

int main() {
    char *plaintext = "This is a secret message.";
    char *ciphertext;
    int plaintext_len = strlen(plaintext);

    // Generate random key and IV
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    // Create encrypt context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    // Calculate encrypt size
    int ciphertext_len = plaintext_len + IV_SIZE;
    ciphertext = (char*) malloc(ciphertext_len);

    // Encrypt plaintext
    int encrypted = 0;
    EVP_EncryptUpdate(ctx, ciphertext, &encrypted, (unsigned char*) plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, &ciphertext[encrypted], &encrypted);

    // Print key, IV, and ciphertext
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%.2x", key[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < IV_SIZE; i++) {
        printf("%.2x", iv[i]);
    }
    printf("\n");

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%.2x", ciphertext[i]);
    }
    printf("\n");

    // Free memory and clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}