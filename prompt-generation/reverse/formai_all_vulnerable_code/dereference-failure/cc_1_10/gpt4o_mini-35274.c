//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define KEY_SIZE 16

void print_usage() {
    printf("Usage: file_encryptor <encrypt/decrypt> <input_file> <output_file> <key>\n");
    printf("Example: file_encryptor encrypt input.txt output.enc secretkey123456\n");
}

void encrypt_decrypt(FILE *input_file, FILE *output_file, const char *key, int encrypt) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    // Initialize key for encryption/decryption
    size_t key_length = strlen(key);
    if (key_length < KEY_SIZE) {
        printf("Key must be at least 16 characters long!\n");
        return;
    }

    printf("Starting %s process...\n", encrypt ? "encryption" : "decryption");

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            buffer[i] ^= key[i % key_length]; // Simple XOR encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, output_file);
    }

    printf("%s process completed successfully!\n", encrypt ? "Encryption" : "Decryption");
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
    
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key, 1);
    } else if (strcmp(operation, "decrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key, 0);
    } else {
        printf("Invalid operation. Choose 'encrypt' or 'decrypt'.\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}