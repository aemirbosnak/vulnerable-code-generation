//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <openssl/aes.h>

// Define the key and initialization vector (IV)
const uint8_t key[] = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
};
const uint8_t iv[] = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
};

// Define the input and output file names
const char *input_file_name = "input.txt";
const char *output_file_name = "output.enc";

// Encrypt a file using the specified key and IV
int encrypt_file(const char *input_file_name, const char *output_file_name) {
    // Open the input and output files
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file: %s\n", input_file_name);
        return -1;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file: %s\n", output_file_name);
        return -1;
    }

    // Create an AES-256 CBC cipher context
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, 256, &enc_key) != 0) {
        fprintf(stderr, "Error: Could not set encryption key\n");
        return -1;
    }

    // Allocate a buffer for the input and output data
    unsigned char in_buf[AES_BLOCK_SIZE];
    unsigned char out_buf[AES_BLOCK_SIZE];

    // Read input data in blocks and encrypt it
    size_t bytes_read;
    while ((bytes_read = fread(in_buf, 1, AES_BLOCK_SIZE, input_file)) > 0) {
        AES_cbc_encrypt(in_buf, out_buf, bytes_read, &enc_key, iv, AES_ENCRYPT);
        fwrite(out_buf, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Decrypt a file using the specified key and IV
int decrypt_file(const char *input_file_name, const char *output_file_name) {
    // Open the input and output files
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file: %s\n", input_file_name);
        return -1;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file: %s\n", output_file_name);
        return -1;
    }

    // Create an AES-256 CBC cipher context
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, 256, &dec_key) != 0) {
        fprintf(stderr, "Error: Could not set decryption key\n");
        return -1;
    }

    // Allocate a buffer for the input and output data
    unsigned char in_buf[AES_BLOCK_SIZE];
    unsigned char out_buf[AES_BLOCK_SIZE];

    // Read input data in blocks and decrypt it
    size_t bytes_read;
    while ((bytes_read = fread(in_buf, 1, AES_BLOCK_SIZE, input_file)) > 0) {
        AES_cbc_encrypt(in_buf, out_buf, bytes_read, &dec_key, iv, AES_DECRYPT);
        fwrite(out_buf, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        return -1;
    }

    // Check the operation type
    if (strcmp(argv[1], "encrypt") == 0) {
        // Encrypt the file
        if (encrypt_file(argv[2], argv[3]) != 0) {
            fprintf(stderr, "Error: Could not encrypt file\n");
            return -1;
        }
    } else if (strcmp(argv[1], "decrypt") == 0) {
        // Decrypt the file
        if (decrypt_file(argv[2], argv[3]) != 0) {
            fprintf(stderr, "Error: Could not decrypt file\n");
            return -1;
        }
    } else {
        fprintf(stderr, "Error: Invalid operation type: %s\n", argv[1]);
        return -1;
    }

    return 0;
}