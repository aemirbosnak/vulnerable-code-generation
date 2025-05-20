//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to print the usage of the program
void print_usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt> <key> <input_file> <output_file>\n", prog_name);
    printf("  <encrypt|decrypt>: Specify whether to encrypt or decrypt the file\n");
    printf("  <key>: A non-negative integer key for the XOR operation\n");
    printf("  <input_file>: The path to the file that needs to be processed\n");
    printf("  <output_file>: The path where the processed file will be saved\n");
}

// XOR encryption/decryption function
void xor_cipher(const char *input, const char *output, uint8_t key) {
    FILE *input_file = fopen(input, "rb");
    FILE *output_file = fopen(output, "wb");
    
    if (!input_file || !output_file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    uint8_t key = atoi(argv[2]);
    const char *input_file = argv[3];
    const char *output_file = argv[4];

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting %s to %s with key %d...\n", input_file, output_file, key);
        xor_cipher(input_file, output_file, key);
        printf("Encryption complete.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting %s to %s with key %d...\n", input_file, output_file, key);
        xor_cipher(input_file, output_file, key);
        printf("Decryption complete.\n");
    } else {
        fprintf(stderr, "Error: Unknown operation '%s'\n", operation);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}