//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption key
unsigned char key[] = "mysecretkey";

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
        // Encrypt the byte using XOR operation with the encryption key
        c ^= key[0];

        // Write the encrypted byte to the output file
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
        // Decrypt the byte using XOR operation with the encryption key
        c ^= key[0];

        // Write the decrypted byte to the output file
        fputc(c, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main() {
    // Get the input and output file names from the user
    char input_file[100], output_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Choose the encryption or decryption operation
    int choice;
    printf("Choose an operation:\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);

    // Perform the encryption or decryption operation based on the user's choice
    switch (choice) {
        case 1:
            encrypt_file(input_file, output_file);
            printf("File encrypted successfully.\n");
            break;
        case 2:
            decrypt_file(input_file, output_file);
            printf("File decrypted successfully.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}