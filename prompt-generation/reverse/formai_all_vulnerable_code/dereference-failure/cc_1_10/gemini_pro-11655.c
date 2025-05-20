//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file using XOR encryption
void encrypt_file(const char *input_file, const char *output_file, unsigned char key) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read the input file byte by byte and encrypt it
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the byte with the key
        ch ^= key;

        // Write the encrypted byte to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file using XOR encryption
void decrypt_file(const char *input_file, const char *output_file, unsigned char key) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read the input file byte by byte and decrypt it
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the byte with the key again to decrypt it
        ch ^= key;

        // Write the decrypted byte to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    // Check if the correct number of arguments are provided
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <operation> <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the operation (encrypt or decrypt)
    char *operation = argv[1];

    // Get the input and output file names
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Get the encryption/decryption key
    unsigned char key = atoi(argv[4]);

    // Encrypt or decrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}