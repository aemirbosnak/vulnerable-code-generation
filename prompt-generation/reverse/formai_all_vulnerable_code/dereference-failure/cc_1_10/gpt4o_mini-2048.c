//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

// Function to transform a byte with a given key
unsigned char transform_byte(unsigned char byte, unsigned char key) {
    // Apply a simple transformation using XOR operation
    return byte ^ key;
}

// Function to encrypt a file
void encrypt_file(const char *input_file, const char *output_file, unsigned char key) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    if (!infile || !outfile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Process the file in chunks
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, infile)) > 0) {
        // Transform each byte in the buffer
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = transform_byte(buffer[i], key);
        }
        // Write the transformed bytes to the output file
        fwrite(buffer, sizeof(unsigned char), bytes_read, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

// Function to decrypt a file (same method as encryption)
void decrypt_file(const char *input_file, const char *output_file, unsigned char key) {
    // Encryption and decryption are symmetric
    encrypt_file(input_file, output_file, key);
}

// Main function to test the file encryption and decryption
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    unsigned char key = (unsigned char)atoi(argv[4]); // Convert key to unsigned char

    // Check for the operation type
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
        printf("File encrypted successfully: %s\n", output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
        printf("File decrypted successfully: %s\n", output_file);
    } else {
        fprintf(stderr, "Invalid operation: use 'encrypt' or 'decrypt'\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}