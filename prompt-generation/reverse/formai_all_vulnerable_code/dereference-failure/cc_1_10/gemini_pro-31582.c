//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define ENCRYPTION_KEY "The quick brown fox jumps over the lazy dog"

// Encrypt a file using the XOR cipher.
void encrypt_file(char *input_file, char *output_file) {
    // Open the input and output files.
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the encryption key.
    int key_length = strlen(ENCRYPTION_KEY);

    // Read the input file byte by byte.
    int ch;
    int index = 0;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the byte with the encryption key.
        ch ^= ENCRYPTION_KEY[index];

        // Increment the index of the encryption key.
        index = (index + 1) % key_length;

        // Write the encrypted byte to the output file.
        fputc(ch, output);
    }

    // Close the input and output files.
    fclose(input);
    fclose(output);
}

// Decrypt a file using the XOR cipher.
void decrypt_file(char *input_file, char *output_file) {
    // Open the input and output files.
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the encryption key.
    int key_length = strlen(ENCRYPTION_KEY);

    // Read the input file byte by byte.
    int ch;
    int index = 0;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the byte with the encryption key.
        ch ^= ENCRYPTION_KEY[index];

        // Increment the index of the encryption key.
        index = (index + 1) % key_length;

        // Write the decrypted byte to the output file.
        fputc(ch, output);
    }

    // Close the input and output files.
    fclose(input);
    fclose(output);
}

// Print the usage information.
void usage(char *program_name) {
    printf("Usage: %s <command> <input_file> <output_file>\n", program_name);
    printf("Commands:\n");
    printf("    encrypt: Encrypt a file using the XOR cipher.\n");
    printf("    decrypt: Decrypt a file using the XOR cipher.\n");
}

// Main function.
int main(int argc, char *argv[]) {
    // Check the number of arguments.
    if (argc != 4) {
        usage(argv[0]);
        exit(1);
    }

    // Get the command.
    char *command = argv[1];

    // Get the input file name.
    char *input_file = argv[2];

    // Get the output file name.
    char *output_file = argv[3];

    // Encrypt or decrypt the file.
    if (strcmp(command, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(command, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        usage(argv[0]);
        exit(1);
    }

    return 0;
}