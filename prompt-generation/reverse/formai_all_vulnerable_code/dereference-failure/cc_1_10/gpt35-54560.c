//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get input file path
    char *input_file = argv[1];

    // Get output file path
    char *output_file = argv[2];

    // Get key
    char *key = argv[3];

    // Check key length
    size_t keylen = strlen(key);
    if (keylen != 16 && keylen != 24 && keylen != 32) {
        fprintf(stderr, "Key length must be 16, 24, or 32 bytes\n");
        return EXIT_FAILURE;
    }

    // Open input file for reading
    FILE *in_fp = fopen(input_file, "rb");
    if (!in_fp) {
        fprintf(stderr, "Error opening input file\n");
        return EXIT_FAILURE;
    }

    // Open output file for writing
    FILE *out_fp = fopen(output_file, "wb");
    if (!out_fp) {
        fprintf(stderr, "Error opening output file\n");
        return EXIT_FAILURE;
    }

    // Initialize AES context with key
    AES_KEY aes_key;
    if (AES_set_encrypt_key((unsigned char *)key, keylen * 8, &aes_key) < 0) {
        fprintf(stderr, "Error initializing AES context\n");
        return EXIT_FAILURE;
    }

    // Encrypt input file in chunks and write to output file
    unsigned char in_buf[BUFSIZE];
    unsigned char out_buf[BUFSIZE];
    int num_bytes_read, num_bytes_written;
    while ((num_bytes_read = fread(in_buf, 1, BUFSIZE, in_fp)) > 0) {
        AES_encrypt(in_buf, out_buf, &aes_key);
        num_bytes_written = fwrite(out_buf, 1, num_bytes_read, out_fp);
        if (num_bytes_written != num_bytes_read) {
            fprintf(stderr, "Error writing to output file\n");
            return EXIT_FAILURE;
        }
    }

    // Close files
    fclose(in_fp);
    fclose(out_fp);

    return EXIT_SUCCESS;
}