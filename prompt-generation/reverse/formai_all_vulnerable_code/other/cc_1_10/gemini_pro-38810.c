//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// Modern encryption using AES-256 in CBC mode
#include <openssl/aes.h>

// Error handling
#define CHECK(expr) assert(expr)

// Read a file into a buffer
char* read_file(const char* filename, size_t* size) {
    FILE* fp = fopen(filename, "rb");
    CHECK(fp != NULL);

    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    char* buffer = malloc(*size + 1);
    CHECK(buffer != NULL);

    size_t nread = fread(buffer, 1, *size, fp);
    CHECK(nread == *size);

    fclose(fp);

    buffer[*size] = '\0';
    return buffer;
}

// Write a buffer to a file
int write_file(const char* filename, const void* buffer, size_t size) {
    FILE* fp = fopen(filename, "wb");
    CHECK(fp != NULL);

    size_t nwritten = fwrite(buffer, 1, size, fp);
    CHECK(nwritten == size);

    fclose(fp);

    return 0;
}

// Encrypt a file using AES-256 in CBC mode
int encrypt_file(const char* input_filename, const char* output_filename, const char* key) {
    size_t input_size;
    char* input_buffer = read_file(input_filename, &input_size);

    // Generate a random IV
    uint8_t iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Create an AES-256 CBC context
    AES_KEY enc_key;
    CHECK(AES_set_encrypt_key((const unsigned char*)key, 256, &enc_key) == 0);

    // Encrypt the file
    size_t output_size = input_size + AES_BLOCK_SIZE;
    char* output_buffer = malloc(output_size);
    CHECK(output_buffer != NULL);

    memcpy(output_buffer, iv, AES_BLOCK_SIZE);

    for (size_t i = 0; i < input_size; i += AES_BLOCK_SIZE) {
        AES_cbc_encrypt((const unsigned char*)input_buffer + i, (unsigned char*)output_buffer + i + AES_BLOCK_SIZE, AES_BLOCK_SIZE, &enc_key, iv, AES_ENCRYPT);
    }

    // Write the encrypted file to disk
    int status = write_file(output_filename, output_buffer, output_size);

    free(input_buffer);
    free(output_buffer);

    return status;
}

// Decrypt a file using AES-256 in CBC mode
int decrypt_file(const char* input_filename, const char* output_filename, const char* key) {
    size_t input_size;
    char* input_buffer = read_file(input_filename, &input_size);

    if (input_size < AES_BLOCK_SIZE) {
        fprintf(stderr, "Invalid file format\n");
        return -1;
    }

    // Extract the IV from the encrypted file
    uint8_t iv[AES_BLOCK_SIZE];
    memcpy(iv, input_buffer, AES_BLOCK_SIZE);

    // Create an AES-256 CBC context
    AES_KEY dec_key;
    CHECK(AES_set_decrypt_key((const unsigned char*)key, 256, &dec_key) == 0);

    // Decrypt the file
    size_t output_size = input_size - AES_BLOCK_SIZE;
    char* output_buffer = malloc(output_size);
    CHECK(output_buffer != NULL);

    for (size_t i = AES_BLOCK_SIZE; i < input_size; i += AES_BLOCK_SIZE) {
        AES_cbc_encrypt((const unsigned char*)input_buffer + i, (unsigned char*)output_buffer + i - AES_BLOCK_SIZE, AES_BLOCK_SIZE, &dec_key, iv, AES_DECRYPT);
    }

    // Write the decrypted file to disk
    int status = write_file(output_filename, output_buffer, output_size);

    free(input_buffer);
    free(output_buffer);

    return status;
}

// Usage:
// ./encrypt input.txt output.enc key.txt
// ./decrypt output.enc output.txt key.txt
int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.txt output.enc key.txt\n", argv[0]);
        return -1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* key_filename = argv[3];

    size_t key_size;
    char* key_buffer = read_file(key_filename, &key_size);

    if (strlen(key_buffer) != 64) {
        fprintf(stderr, "Invalid key format\n");
        free(key_buffer);
        return -1;
    }

    int status;
    if (strcmp(output_filename, "-") == 0) {
        status = encrypt_file(input_filename, NULL, key_buffer);
    } else {
        status = encrypt_file(input_filename, output_filename, key_buffer);
    }

    free(key_buffer);

    return status;
}