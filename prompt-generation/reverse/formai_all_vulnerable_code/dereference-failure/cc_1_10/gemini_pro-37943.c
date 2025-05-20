//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

// Custom XOR-based encryption/decryption function
int xor_crypt(uint8_t *data, size_t data_len, uint8_t key) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key> [encrypt/decrypt]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open input and output files
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("fopen(input_file)");
        return EXIT_FAILURE;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("fopen(output_file)");
        return EXIT_FAILURE;
    }

    // Read the key
    uint8_t key = (uint8_t)atoi(argv[3]);

    // Determine the encryption/decryption mode
    int mode = ENCRYPT;
    if (argc > 4) {
        if (strcmp(argv[4], "decrypt") == 0) {
            mode = DECRYPT;
        }
    }

    // Read the input file and encrypt/decrypt it
    size_t bytes_read;
    uint8_t buffer[1024];
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        if (mode == ENCRYPT) {
            xor_crypt(buffer, bytes_read, key);
        } else {
            xor_crypt(buffer, bytes_read, key);
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}