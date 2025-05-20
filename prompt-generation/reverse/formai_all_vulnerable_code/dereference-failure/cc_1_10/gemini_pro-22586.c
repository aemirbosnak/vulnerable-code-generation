//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a key
int encrypt_file(char *input_file, char *output_file, char *key) {
    FILE *input, *output;
    char ch;
    int key_len, i;

    // Open the input and output files
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Get the length of the key
    key_len = strlen(key);

    // Encrypt the file byte by byte
    while ((ch = fgetc(input)) != EOF) {
        // XOR each byte of the file with the corresponding byte of the key
        for (i = 0; i < key_len; i++) {
            ch ^= key[i];
        }
        // Write the encrypted byte to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to decrypt a file using a key
int decrypt_file(char *input_file, char *output_file, char *key) {
    FILE *input, *output;
    char ch;
    int key_len, i;

    // Open the input and output files
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Get the length of the key
    key_len = strlen(key);

    // Decrypt the file byte by byte
    while ((ch = fgetc(input)) != EOF) {
        // XOR each byte of the file with the corresponding byte of the key
        for (i = 0; i < key_len; i++) {
            ch ^= key[i];
        }
        // Write the decrypted byte to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

int main() {
    // Define the input file, output file, and key
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char key[] = "secretkey";

    // Encrypt the file
    if (encrypt_file(input_file, output_file, key) != 0) {
        printf("Error encrypting the file.\n");
        return 1;
    }

    // Decrypt the file
    if (decrypt_file(output_file, input_file, key) != 0) {
        printf("Error decrypting the file.\n");
        return 1;
    }

    printf("File encrypted and decrypted successfully.\n");
    return 0;
}