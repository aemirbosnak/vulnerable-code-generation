//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "This is a secret key"

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read the input file character by character
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        // Encrypt the character using the XOR operator with the encryption key
        ch ^= KEY[0];
        for (int i = 1; i < strlen(KEY); i++) {
            ch ^= KEY[i];
        }

        // Write the encrypted character to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read the input file character by character
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        // Decrypt the character using the XOR operator with the encryption key
        ch ^= KEY[0];
        for (int i = 1; i < strlen(KEY); i++) {
            ch ^= KEY[i];
        }

        // Write the decrypted character to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Get input from the user
char *get_input(char *prompt) {
    printf("%s", prompt);
    char *input = malloc(1024);
    scanf("%s", input);
    return input;
}

// Main function
int main() {
    // Get the input file name from the user
    char *input_file_name = get_input("Enter the input file name: ");

    // Get the output file name from the user
    char *output_file_name = get_input("Enter the output file name: ");

    // Encrypt the file
    encrypt_file(input_file_name, output_file_name);

    // Decrypt the file
    decrypt_file(output_file_name, "decrypted.txt");

    // Success message
    printf("File encrypted and decrypted successfully!\n");

    return 0;
}