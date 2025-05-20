//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(FILE *input, FILE *output, const char *key) {
    int key_length = strlen(key);
    int i = 0;
    unsigned char buffer[BUFFER_SIZE];

    while (!feof(input)) {
        size_t bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input);
        for (size_t j = 0; j < bytesRead; j++) {
            buffer[j] ^= key[i % key_length]; // XOR operation
            i++;
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, output);
    }
}

void print_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key = argv[4];

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fclose(input);
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_decrypt(input, output, key);
        printf("Encryption complete: '%s' -> '%s'\n", input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        encrypt_decrypt(input, output, key);
        printf("Decryption complete: '%s' -> '%s'\n", input_file, output_file);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        fclose(input);
        fclose(output);
        return EXIT_FAILURE;
    }

    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}