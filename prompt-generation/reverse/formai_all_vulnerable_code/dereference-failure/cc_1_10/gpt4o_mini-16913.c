//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the file using XOR cipher
void process_file(const char *input_filename, const char *output_filename, const char *key) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file %s\n", input_filename);
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fclose(input_file);
        fprintf(stderr, "Could not open output file %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    size_t key_length = strlen(key);
    int char_read;
    int i = 0;

    // Process each byte of the input file
    while ((char_read = fgetc(input_file)) != EOF) {
        // XOR operation with the key
        char encrypted_char = char_read ^ key[i % key_length];
        fputc(encrypted_char, output_file);
        i++;
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to print usage information
void print_usage() {
    printf("Usage:\n");
    printf("  encrypt <input_file> <output_file> <key>\n");
    printf("  decrypt <input_file> <output_file> <key>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *input_filename = argv[2];
    const char *output_filename = argv[3];
    const char *key = argv[4];

    if (strcmp(operation, "encrypt") == 0) {
        process_file(input_filename, output_filename, key);
        printf("File encrypted successfully!\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        process_file(input_filename, output_filename, key);
        printf("File decrypted successfully!\n");
    } else {
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}