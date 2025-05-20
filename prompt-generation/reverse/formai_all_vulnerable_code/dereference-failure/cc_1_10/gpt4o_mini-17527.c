//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(const char *input_filename, const char *output_filename, char key) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fclose(input_file);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Buffer to hold data read from the file
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read, encrypt/decrypt, and write in chunks
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR operation for encryption/decryption
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, output_file);
    }

    // Clean up
    fclose(input_file);
    fclose(output_file);
}

void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input file> <output file> <key>\n", program_name);
    fprintf(stderr, "Example: %s encrypt secret.txt secret.enc 'K'\n", program_name);
    fprintf(stderr, "         %s decrypt secret.enc decrypted.txt 'K'\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        usage(argv[0]);
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    char key = argv[4][0]; // Get the first character of the key

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting file...\n");
        encrypt_decrypt(input_file, output_file, key);
        printf("File encrypted successfully: %s\n", output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting file...\n");
        encrypt_decrypt(input_file, output_file, key);
        printf("File decrypted successfully: %s\n", output_file);
    } else {
        fprintf(stderr, "Invalid operation: %s. Use 'encrypt' or 'decrypt'.\n", operation);
        usage(argv[0]);
    }

    return EXIT_SUCCESS;
}