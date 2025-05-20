//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // XOR key for encryption/decryption
#define BUFFER_SIZE 1024

void encrypt_decrypt_file(const char *input_file, const char *output_file) {
    FILE *input_fp = fopen(input_file, "rb");
    if (!input_fp) {
        perror("Could not open input file for reading");
        exit(EXIT_FAILURE);
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (!output_fp) {
        perror("Could not open output file for writing");
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_fp)) > 0) {
        // Encrypt/Decrypt using XOR operation
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY;
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", program_name);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(action, "encrypt") == 0) {
        printf("Encrypting '%s' to '%s'...\n", input_file, output_file);
        encrypt_decrypt_file(input_file, output_file);
        printf("Encryption complete!\n");
    } else if (strcmp(action, "decrypt") == 0) {
        printf("Decrypting '%s' to '%s'...\n", input_file, output_file);
        encrypt_decrypt_file(input_file, output_file);
        printf("Decryption complete!\n");
    } else {
        printf("Invalid action: '%s'. Choose 'encrypt' or 'decrypt'.\n", action);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}