//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

// Function to encrypt data using AES-256
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int ciphertext_len, rc;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error creating context\n");
        return -1;
    }

    /* Initialise the encryption operation. */
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initialising encryption\n");
        return -1;
    }

    /* Provide the message to be encrypted, and obtain the encrypted output. */
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1) {
        fprintf(stderr, "Error encrypting\n");
        return -1;
    }

    /* Finalise the encryption. */
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &rc) != 1) {
        fprintf(stderr, "Error finalising encryption\n");
        return -1;
    }

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len + rc;
}

// Function to decrypt data using AES-256
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int plaintext_len, rc;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error creating context\n");
        return -1;
    }

    /* Initialise the decryption operation. */
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initialising decryption\n");
        return -1;
    }

    /* Provide the message to be decrypted, and obtain the decrypted output. */
    if (EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len) != 1) {
        fprintf(stderr, "Error decrypting\n");
        return -1;
    }

    /* Finalise the decryption. */
    if (EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &rc) != 1) {
        fprintf(stderr, "Error finalising decryption\n");
        return -1;
    }

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len + rc;
}

int main(int argc, char **argv)
{
    if (argc != 5) {
        fprintf(stderr, "Usage: %s plaintext key iv ciphertext\n", argv[0]);
        return -1;
    }

    // Read the plaintext from the file
    FILE *plaintext_file = fopen(argv[1], "r");
    if (!plaintext_file) {
        fprintf(stderr, "Error opening plaintext file\n");
        return -1;
    }

    fseek(plaintext_file, 0, SEEK_END);
    long plaintext_len = ftell(plaintext_file);
    rewind(plaintext_file);

    unsigned char *plaintext = (unsigned char *)malloc(plaintext_len);
    if (!plaintext) {
        fprintf(stderr, "Error allocating memory for plaintext\n");
        return -1;
    }

    fread(plaintext, 1, plaintext_len, plaintext_file);
    fclose(plaintext_file);

    // Read the key from the file
    FILE *key_file = fopen(argv[2], "r");
    if (!key_file) {
        fprintf(stderr, "Error opening key file\n");
        return -1;
    }

    unsigned char *key = (unsigned char *)malloc(32);
    if (!key) {
        fprintf(stderr, "Error allocating memory for key\n");
        return -1;
    }

    fread(key, 1, 32, key_file);
    fclose(key_file);

    // Read the IV from the file
    FILE *iv_file = fopen(argv[3], "r");
    if (!iv_file) {
        fprintf(stderr, "Error opening IV file\n");
        return -1;
    }

    unsigned char *iv = (unsigned char *)malloc(16);
    if (!iv) {
        fprintf(stderr, "Error allocating memory for IV\n");
        return -1;
    }

    fread(iv, 1, 16, iv_file);
    fclose(iv_file);

    // Encrypt the plaintext
    unsigned char *ciphertext = (unsigned char *)malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
    if (!ciphertext) {
        fprintf(stderr, "Error allocating memory for ciphertext\n");
        return -1;
    }

    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    if (ciphertext_len < 0) {
        fprintf(stderr, "Error encrypting\n");
        return -1;
    }

    // Write the ciphertext to the file
    FILE *ciphertext_file = fopen(argv[4], "w");
    if (!ciphertext_file) {
        fprintf(stderr, "Error opening ciphertext file\n");
        return -1;
    }

    fwrite(ciphertext, 1, ciphertext_len, ciphertext_file);
    fclose(ciphertext_file);

    // Decrypt the ciphertext
    unsigned char *decryptedtext = (unsigned char *)malloc(ciphertext_len);
    if (!decryptedtext) {
        fprintf(stderr, "Error allocating memory for decryptedtext\n");
        return -1;
    }

    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    if (decryptedtext_len < 0) {
        fprintf(stderr, "Error decrypting\n");
        return -1;
    }

    // Compare the decrypted text to the original plaintext
    if (memcmp(plaintext, decryptedtext, plaintext_len) != 0) {
        fprintf(stderr, "Error: Decrypted text does not match original plaintext\n");
        return -1;
    }

    return 0;
}