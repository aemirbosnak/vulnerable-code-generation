//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character using a Caesar cipher
char encryptChar(char ch, int key) {
    // Convert the character to its ASCII value
    int ascii = (int)ch;

    // Encrypt the character by adding the key
    ascii += key;

    // Check if the character has wrapped around
    if (ascii > 126) {
        ascii -= 94;
    }

    // Convert the encrypted ASCII value back to a character
    ch = (char)ascii;

    // Return the encrypted character
    return ch;
}

// Function to encrypt a string using a Caesar cipher
char *encryptString(char *str, int key) {
    // Create a buffer to store the encrypted string
    char *encryptedStr = malloc(strlen(str) + 1);

    // Encrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        encryptedStr[i] = encryptChar(str[i], key);
    }

    // Add the null terminator to the end of the string
    encryptedStr[strlen(str)] = '\0';

    // Return the encrypted string
    return encryptedStr;
}

// Function to decrypt a character using a Caesar cipher
char decryptChar(char ch, int key) {
    // Convert the character to its ASCII value
    int ascii = (int)ch;

    // Decrypt the character by subtracting the key
    ascii -= key;

    // Check if the character has wrapped around
    if (ascii < 32) {
        ascii += 94;
    }

    // Convert the decrypted ASCII value back to a character
    ch = (char)ascii;

    // Return the decrypted character
    return ch;
}

// Function to decrypt a string using a Caesar cipher
char *decryptString(char *str, int key) {
    // Create a buffer to store the decrypted string
    char *decryptedStr = malloc(strlen(str) + 1);

    // Decrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        decryptedStr[i] = decryptChar(str[i], key);
    }

    // Add the null terminator to the end of the string
    decryptedStr[strlen(str)] = '\0';

    // Return the decrypted string
    return decryptedStr;
}

// Print the usage message
void printUsage() {
    printf("Usage: file_encrypt [-e|-d] <key> <input_file> <output_file>\n");
    printf("Options:\n");
    printf("  -e      Encrypt the file\n");
    printf("  -d      Decrypt the file\n");
    printf("Arguments:\n");
    printf("  key          The encryption/decryption key\n");
    printf("  input_file   The file to encrypt/decrypt\n");
    printf("  output_file  The file to save the encrypted/decrypted data to\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments has been provided
    if (argc != 5) {
        printUsage();
        return 1;
    }

    // Get the encryption/decryption option
    char *option = argv[1];

    // Get the encryption/decryption key
    int key = atoi(argv[2]);

    // Get the input file name
    char *inputFileName = argv[3];

    // Get the output file name
    char *outputFileName = argv[4];

    // Check if the encryption/decryption option is valid
    if (strcmp(option, "-e") != 0 && strcmp(option, "-d") != 0) {
        printf("Invalid encryption/decryption option: %s\n", option);
        printUsage();
        return 1;
    }

    // Check if the input file exists
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Input file %s does not exist.\n", inputFileName);
        return 1;
    }

    // Create the output file
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not create output file %s.\n", outputFileName);
        return 1;
    }

    // Read the input file into a buffer
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);
    char *buffer = malloc(fileSize + 1);
    if (fread(buffer, fileSize, 1, inputFile) != 1) {
        printf("Error: Could not read input file %s.\n", inputFileName);
        return 1;
    }
    buffer[fileSize] = '\0';

    // Encrypt or decrypt the buffer
    char *encryptedDecryptedBuffer;
    if (strcmp(option, "-e") == 0) {
        encryptedDecryptedBuffer = encryptString(buffer, key);
    } else {
        encryptedDecryptedBuffer = decryptString(buffer, key);
    }

    // Write the encrypted or decrypted buffer to the output file
    if (fwrite(encryptedDecryptedBuffer, strlen(encryptedDecryptedBuffer), 1, outputFile) != 1) {
        printf("Error: Could not write to output file %s.\n", outputFileName);
        return 1;
    }

    // Free the buffers
    free(buffer);
    free(encryptedDecryptedBuffer);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}