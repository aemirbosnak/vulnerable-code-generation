//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define OFFSET 3  // Simple shift for encryption/decryption

void encrypt_decrypt(FILE *input_file, FILE *output_file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            // Simple Caesar cipher for encryption and decryption
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (buffer[i] - 'a' + OFFSET) % 26 + 'a';
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (buffer[i] - 'A' + OFFSET) % 26 + 'A';
            }
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

void process_file(const char *input_filename, const char *output_filename, int mode) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fclose(input_file);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    if (mode == 1) {
        printf("Encrypting file: %s\n", input_filename);
    } else {
        printf("Decrypting file: %s\n", input_filename);
    }

    encrypt_decrypt(input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    printf("Operation completed. Output saved in: %s\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <mode>\n", argv[0]);
        fprintf(stderr, "Mode: 1 for encrypt, 0 for decrypt\n");
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int mode = atoi(argv[3]);

    if (mode != 0 && mode != 1) {
        fprintf(stderr, "Invalid mode. Use 1 for encrypt or 0 for decrypt.\n");
        exit(EXIT_FAILURE);
    }

    process_file(input_file, output_file, mode);

    return 0;
}