//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

/*
 * This program demonstrates the use of the EVP interface to encrypt and decrypt data.
 */

int main(int argc, char **argv)
{
    int len;
    unsigned char *ciphertext, *decryptedtext;
    EVP_CIPHER_CTX *ctx;

    /*
     * Check the command line arguments.
     */

    if (argc != 4) {
        fprintf(stderr, "Usage: %s key plaintext ciphertext\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
     * Create the EVP context.
     */

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error creating EVP context\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Initialize the EVP context for encryption.
     */

    if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)argv[1], NULL, 1) != 1) {
        fprintf(stderr, "Error initializing EVP context for encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    /*
     * Calculate the length of the ciphertext.
     */

    len = strlen(argv[2]) + EVP_CIPHER_CTX_block_size(ctx);

    /*
     * Allocate memory for the ciphertext.
     */

    ciphertext = malloc(len);
    if (ciphertext == NULL) {
        fprintf(stderr, "Error allocating memory for ciphertext\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    /*
     * Encrypt the plaintext.
     */

    if (EVP_CipherUpdate(ctx, ciphertext, &len, (unsigned char *)argv[2], strlen(argv[2])) != 1) {
        fprintf(stderr, "Error encrypting plaintext\n");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        exit(EXIT_FAILURE);
    }

    /*
     * Finalize the encryption.
     */

    if (EVP_CipherFinal_ex(ctx, ciphertext + len, &len) != 1) {
        fprintf(stderr, "Error finalizing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        exit(EXIT_FAILURE);
    }

    /*
     * Clean up the EVP context.
     */

    EVP_CIPHER_CTX_free(ctx);

    /*
     * Write the ciphertext to the file.
     */

    if (freopen(argv[3], "w", stdout) == NULL) {
        fprintf(stderr, "Error opening ciphertext file\n");
        free(ciphertext);
        exit(EXIT_FAILURE);
    }

    fwrite(ciphertext, len, 1, stdout);
    fclose(stdout);

    /*
     * Free the ciphertext.
     */

    free(ciphertext);

    return EXIT_SUCCESS;
}