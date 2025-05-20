//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BUFFER_SIZE 256

// Function to generate a random key
void generate_key(unsigned char *key, int key_length) {
    RAND_bytes(key, key_length);
}

// Asynchronous function to encrypt a file using AES-256-CBC with a randomly generated key
void encrypt_file(const char *file_in_name, const char *file_out_name, unsigned char *key, int key_length) {
    EVP_CIPHER_CTX *ctx;
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char in_buffer[BUFFER_SIZE], out_buffer[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH];
    int bytes_read, bytes_written, key_size, iv_size, out_len;
    bool success = false;

    // Initialize the encryption context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error initializing encryption context\n");
        return;
    }

    // Choose the cipher algorithm and mode, and set the key and IV
    key_size = EVP_CIPHER_key_length(EVP_aes_256_cbc());
    iv_size = EVP_CIPHER_iv_length(EVP_aes_256_cbc());

    if (key_size != key_length) {
        fprintf(stderr, "Key length does not match algorithm requirements\n");
        goto cleanup;
    }

    generate_key(iv, iv_size);

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error setting up encryption\n");
        goto cleanup;
    }

    // Open the input and output files
    FILE *file_in = fopen(file_in_name, "rb");
    FILE *file_out = fopen(file_out_name, "wb");

    if (file_in == NULL || file_out == NULL) {
        fprintf(stderr, "Error opening input or output file\n");
        goto cleanup;
    }

    // Write the IV to the output file
    fwrite(iv, sizeof(unsigned char), iv_size, file_out);

    // Read the input file, encrypt the data, and write to output file
    while ((bytes_read = fread(in_buffer, sizeof(unsigned char), BUFFER_SIZE, file_in)) > 0) {
        if (!EVP_EncryptUpdate(ctx, out_buffer, &out_len, in_buffer, bytes_read)) {
            fprintf(stderr, "Error encrypting data\n");
            goto cleanup;
        }

        bytes_written = fwrite(out_buffer, sizeof(unsigned char), out_len, file_out);
        if (bytes_written != out_len) {
            fprintf(stderr, "Error writing encrypted data to file\n");
            goto cleanup;
        }
    }

    if (bytes_read < 0) {
        fprintf(stderr, "Error reading input file\n");
        goto cleanup;
    }

    // Finalize the encryption process
    if (!EVP_EncryptFinal_ex(ctx, out_buffer, &out_len)) {
        fprintf(stderr, "Error finalizing encryption\n");
        goto cleanup;
    }

    bytes_written = fwrite(out_buffer, sizeof(unsigned char), out_len, file_out);
    if (bytes_written != out_len) {
        fprintf(stderr, "Error writing encrypted data to file\n");
        goto cleanup;
    }

    success = true;

    cleanup:
        EVP_CIPHER_CTX_free(ctx);
        fclose(file_in);
        fclose(file_out);
        if (!success) {
            remove(file_out_name);
        }
}

// Asynchronous function to decrypt a file using AES-256-CBC with a user-provided key
void decrypt_file(const char *file_in_name, const char *file_out_name, unsigned char *key, int key_length) {
    EVP_CIPHER_CTX *ctx;
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char in_buffer[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH], out_buffer[BUFFER_SIZE];
    int bytes_read, bytes_written, key_size, iv_size, out_len;
    bool success = false;

    // Initialize the decryption context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error initializing decryption context\n");
        return;
    }

    // Choose the cipher algorithm and mode, and set the key and IV
    key_size = EVP_CIPHER_key_length(EVP_aes_256_cbc());
    iv_size = EVP_CIPHER_iv_length(EVP_aes_256_cbc());

    if (key_size != key_length) {
        fprintf(stderr, "Key length does not match algorithm requirements\n");
        goto cleanup;
    }

    // Open the input and output files
    FILE *file_in = fopen(file_in_name, "rb");
    FILE *file_out = fopen(file_out_name, "wb");

    if (file_in == NULL || file_out == NULL) {
        fprintf(stderr, "Error opening input or output file\n");
        goto cleanup;
    }

    // Read the IV from the input file
    if (fread(iv, sizeof(unsigned char), iv_size, file_in) != iv_size) {
        fprintf(stderr, "Error reading IV from input file\n");
        goto cleanup;
    }

    // Initialize the decryption process
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error setting up decryption\n");
        goto cleanup;
    }

    // Read the input file, decrypt the data, and write to output file
    while ((bytes_read = fread(in_buffer, sizeof(unsigned char), BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH, file_in)) > 0) {
        if (!EVP_DecryptUpdate(ctx, out_buffer, &out_len, in_buffer, bytes_read)) {
            fprintf(stderr, "Error decrypting data\n");
            goto cleanup;
        }

        bytes_written = fwrite(out_buffer, sizeof(unsigned char), out_len, file_out);
        if (bytes_written != out_len) {
            fprintf(stderr, "Error writing decrypted data to file\n");
            goto cleanup;
        }
    }

    if (bytes_read < 0) {
        fprintf(stderr, "Error reading input file\n");
        goto cleanup;
    }

    // Finalize the decryption process
    if (!EVP_DecryptFinal_ex(ctx, out_buffer, &out_len)) {
        fprintf(stderr, "Error finalizing decryption\n");
        goto cleanup;
    }

    bytes_written = fwrite(out_buffer, sizeof(unsigned char), out_len, file_out);
    if (bytes_written != out_len) {
        fprintf(stderr, "Error writing decrypted data to file\n");
        goto cleanup;
    }

    success = true;

    cleanup:
        EVP_CIPHER_CTX_free(ctx);
        fclose(file_in);
        fclose(file_out);
        if (!success) {
            remove(file_out_name);
        }
}

int main(int argc, char *argv[]) {

    // Generate a random key
    unsigned char key[EVP_MAX_KEY_LENGTH];
    int key_length = EVP_MAX_KEY_LENGTH;
    generate_key(key, key_length);

    // Encrypt a file asynchronously
    const char *file_in_name = "input.txt";
    const char *file_out_name = "output.txt";
    encrypt_file(file_in_name, file_out_name, key, key_length);

    // Decrypt the file using the same key asynchronously
    const char *file_in_name2 = "output.txt";
    const char *file_out_name2 = "input2.txt";
    decrypt_file(file_in_name2, file_out_name2, key, key_length);

    return 0;
}