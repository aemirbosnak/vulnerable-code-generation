//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Custom error handling function
static void handle_error(const char *err)
{
    fprintf(stderr, "Error: %s\n", err);
    exit(EXIT_FAILURE);
}

// Function to generate a random key
static unsigned char *generate_key(int key_length)
{
    unsigned char *key = malloc(key_length);
    if (key == NULL) {
        handle_error("Failed to allocate memory for key");
    }

    if (RAND_bytes(key, key_length) != 1) {
        handle_error("Failed to generate random key");
    }

    return key;
}

// Function to encrypt data
static unsigned char *encrypt(unsigned char *plaintext, int plaintext_length,
                             unsigned char *key, int key_length)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        handle_error("Failed to create encryption context");
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        handle_error("Failed to initialize encryption context");
    }

    unsigned char *ciphertext = malloc(plaintext_length + EVP_CIPHER_CTX_block_size(ctx));
    if (ciphertext == NULL) {
        handle_error("Failed to allocate memory for ciphertext");
    }

    int ciphertext_length;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_length, plaintext, plaintext_length) != 1) {
        handle_error("Failed to encrypt data");
    }

    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &ciphertext_length) != 1) {
        handle_error("Failed to finalize encryption");
    }

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

// Function to decrypt data
static unsigned char *decrypt(unsigned char *ciphertext, int ciphertext_length,
                             unsigned char *key, int key_length)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        handle_error("Failed to create decryption context");
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        handle_error("Failed to initialize decryption context");
    }

    unsigned char *plaintext = malloc(ciphertext_length);
    if (plaintext == NULL) {
        handle_error("Failed to allocate memory for plaintext");
    }

    int plaintext_length;
    if (EVP_DecryptUpdate(ctx, plaintext, &plaintext_length, ciphertext, ciphertext_length) != 1) {
        handle_error("Failed to decrypt data");
    }

    if (EVP_DecryptFinal_ex(ctx, plaintext + plaintext_length, &plaintext_length) != 1) {
        handle_error("Failed to finalize decryption");
    }

    EVP_CIPHER_CTX_free(ctx);

    return plaintext;
}

int main()
{
    // Generate a random key
    unsigned char *key = generate_key(32);

    // Plaintext to be encrypted
    unsigned char *plaintext = "Hello, world!";
    int plaintext_length = strlen(plaintext);

    // Encrypt the data
    unsigned char *ciphertext = encrypt(plaintext, plaintext_length, key, 32);
    int ciphertext_length = strlen(ciphertext);

    // Decrypt the data
    unsigned char *decrypted_plaintext = decrypt(ciphertext, ciphertext_length, key, 32);
    int decrypted_plaintext_length = strlen(decrypted_plaintext);

    // Print the original plaintext, the ciphertext, and the decrypted plaintext
    printf("Original plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}