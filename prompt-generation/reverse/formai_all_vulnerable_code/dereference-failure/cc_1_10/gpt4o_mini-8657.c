//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 16 // AES block size in bytes
#define MAX_FILENAME_LENGTH 256

void print_usage(const char *progname) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", progname);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void xor_block(uint8_t *output, const uint8_t *input, const uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i];
    }
}

void process_file(const char *input_file, const char *output_file, const uint8_t *key, int is_encrypt) {
    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) handle_error("Failed to open input file");

    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) handle_error("Failed to open output file");

    uint8_t block[BLOCK_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(block, 1, BLOCK_SIZE, in_file)) > 0) {
        if (bytes_read < BLOCK_SIZE) {
            memset(block + bytes_read, 0, BLOCK_SIZE - bytes_read); // Pad with zeros
        }
        if (is_encrypt) {
            uint8_t encrypted_block[BLOCK_SIZE];
            xor_block(encrypted_block, block, key);
            fwrite(encrypted_block, 1, BLOCK_SIZE, out_file);
        } else {
            uint8_t decrypted_block[BLOCK_SIZE];
            xor_block(decrypted_block, block, key);
            fwrite(decrypted_block, 1, BLOCK_SIZE, out_file);
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key_str = argv[4];

    if (strlen(key_str) != BLOCK_SIZE) {
        fprintf(stderr, "Key must be exactly %d bytes long.\n", BLOCK_SIZE);
        return EXIT_FAILURE;
    }

    uint8_t key[BLOCK_SIZE];
    memset(key, 0, BLOCK_SIZE);
    strncpy((char *)key, key_str, BLOCK_SIZE);

    if (strcmp(operation, "encrypt") == 0) {
        process_file(input_file, output_file, key, 1);
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        process_file(input_file, output_file, key, 0);
        printf("File decrypted successfully.\n");
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}