//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

int main() {
    // Define some sample plaintext
    char *plaintext = "Secret message to encrypt";

    // Create a buffer for the ciphertext
    size_t ciphertext_length = EVP_CIPHER_block_size(EVP_aes_128_cbc());
    unsigned char *ciphertext = malloc(ciphertext_length);

    // Generate a random initialization vector (IV)
    unsigned char *iv = malloc(EVP_CIPHER_iv_length(EVP_aes_128_cbc()));
    RAND_bytes(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()));

    // Create an OpenSSL encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Initialize the encryption context for encryption using AES-128 in CBC mode
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, NULL, iv) != 1) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Update the encryption context with the plaintext
    int ciphertext_len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)plaintext, strlen(plaintext)) != 1) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Finalize the encryption and get any remaining ciphertext
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);

    // Print the ciphertext in hexadecimal format
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_length; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Free the ciphertext buffer
    free(ciphertext);
    free(iv);

    return EXIT_SUCCESS;
}