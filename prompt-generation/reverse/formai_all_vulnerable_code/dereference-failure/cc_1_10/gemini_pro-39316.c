//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 32
#define IV_SIZE 16

int encrypt_file(const char *input_file, const char *output_file, const char *key, const char *iv) {
    FILE *infile, *outfile;
    EVP_CIPHER_CTX *ctx;
    int len;
    unsigned char buffer[1024];
    unsigned char outbuffer[1024 + EVP_MAX_BLOCK_LENGTH];

    // Open input and output files
    infile = fopen(input_file, "rb");
    if (infile == NULL) {
        perror("fopen(input_file)");
        return EXIT_FAILURE;
    }
    outfile = fopen(output_file, "wb");
    if (outfile == NULL) {
        perror("fopen(output_file)");
        return EXIT_FAILURE;
    }

    // Initialize OpenSSL context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        perror("EVP_CIPHER_CTX_new()");
        return EXIT_FAILURE;
    }

    // Set up encryption parameters
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, (unsigned char *)iv) != 1) {
        perror("EVP_EncryptInit_ex()");
        return EXIT_FAILURE;
    }

    // Encrypt data
    while ((len = fread(buffer, 1, sizeof(buffer), infile)) > 0) {
        // Encrypt buffer
        if (EVP_EncryptUpdate(ctx, outbuffer, &len, buffer, len) != 1) {
            perror("EVP_EncryptUpdate()");
            return EXIT_FAILURE;
        }

        // Write encrypted data to output file
        if (fwrite(outbuffer, 1, len, outfile) != len) {
            perror("fwrite(outbuffer)");
            return EXIT_FAILURE;
        }
    }

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, outbuffer, &len) != 1) {
        perror("EVP_EncryptFinal_ex()");
        return EXIT_FAILURE;
    }

    // Write remaining encrypted data to output file
    if (fwrite(outbuffer, 1, len, outfile) != len) {
        perror("fwrite(outbuffer)");
        return EXIT_FAILURE;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key> <iv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Key and IV must be hexadecimal strings
    if (strlen(argv[3]) != KEY_SIZE * 2 || strlen(argv[4]) != IV_SIZE * 2) {
        fprintf(stderr, "Key and IV must be hexadecimal strings of length %d and %d respectively.\n", KEY_SIZE * 2, IV_SIZE * 2);
        return EXIT_FAILURE;
    }

    // Convert key and IV to binary
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        sscanf(argv[3] + i * 2, "%02hhx", &key[i]);
    }
    for (int i = 0; i < IV_SIZE; i++) {
        sscanf(argv[4] + i * 2, "%02hhx", &iv[i]);
    }

    // Encrypt file
    if (encrypt_file(argv[1], argv[2], (char *)key, (char *)iv) != EXIT_SUCCESS) {
        fprintf(stderr, "Error encrypting file.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}