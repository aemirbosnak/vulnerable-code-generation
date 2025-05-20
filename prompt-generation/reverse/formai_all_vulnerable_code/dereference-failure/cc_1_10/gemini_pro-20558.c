//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
// Encrypt a file using a simple XOR encryption algorithm

#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 0x12345678

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file byte by byte
    int c;
    while ((c = fgetc(input)) != EOF) {
        // XOR the character with the encryption key
        c ^= KEY;

        // Write the encrypted character to the output file
        fputc(c, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file byte by byte
    int c;
    while ((c = fgetc(input)) != EOF) {
        // XOR the character with the encryption key
        c ^= KEY;

        // Write the decrypted character to the output file
        fputc(c, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the required arguments
    if (argc != 4) {
        printf("Usage: %s encrypt|decrypt <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Get the action (encrypt or decrypt)
    char *action = argv[1];

    // Get the input and output file names
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(action, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid action: %s\n", action);
        exit(1);
    }

    printf("File %s successfully.\n", action);

    return 0;
}