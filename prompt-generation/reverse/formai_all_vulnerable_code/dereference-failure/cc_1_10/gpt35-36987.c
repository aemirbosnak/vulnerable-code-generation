//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    // Initialize OpenSSL EVP library
    EVP_add_cipher(EVP_aes_256_cbc());
    EVP_add_digest(EVP_sha256());

    // Define variables for key and IV
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    // Create plaintext message to encrypt
    char message[] = "This is a secret message.";

    // Determine size of ciphertext buffer
    int ciphertext_size = strlen(message) + EVP_CIPHER_block_size(EVP_aes_256_cbc());

    // Allocate memory for ciphertext buffer
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_size);

    // Create context for encryption
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt plaintext message
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char *)message, strlen(message));
    int ciphertext_len = len;

    // Finalize encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    // Print ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // Create context for decryption
    EVP_CIPHER_CTX_reset(ctx);
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Determine size of plaintext buffer
    int plaintext_size = ciphertext_len;

    // Allocate memory for plaintext buffer
    unsigned char *plaintext = (unsigned char *)malloc(plaintext_size);

    // Decrypt ciphertext message
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    int plaintext_len = len;

    // Finalize decryption
    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;

    // Print decrypted message
    printf("Decrypted message: %s\n", plaintext);

    // Clean up
    EVP_CIPHER_CTX_cleanup(ctx);
    free(ciphertext);
    free(plaintext);

    return 0;
}