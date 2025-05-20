//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(char *buffer, int length, char key) {
    for (int i = 0; i < length; i++) {
        buffer[i] ^= key;  // XOR encryption
    }
}

void process_file(const char *input_filename, const char *output_filename, char key) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return;
    }
    
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file);
    
    if (bytes_read > 0) {
        encrypt_decrypt(buffer, bytes_read, key);
        fwrite(buffer, 1, bytes_read, output_file);
        
        // Recursive call for the remaining bytes
        process_file(input_filename, output_filename, key);
    }

    fclose(input_file);
    fclose(output_file);
}

void encrypt(const char *input_filename, const char *output_filename, char key) {
    process_file(input_filename, output_filename, key);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    char key = argv[3][0];

    encrypt(input_file, output_file, key);

    printf("File encryption completed. Encrypted file: %s\n", output_file);
    return EXIT_SUCCESS;
}