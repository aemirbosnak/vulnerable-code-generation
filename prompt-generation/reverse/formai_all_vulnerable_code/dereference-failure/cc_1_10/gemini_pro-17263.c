//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption/decryption
#define KEY "MySuperSecretKey"

// Function to encrypt a file
void encryptFile(char *fileName) {
    // Open the input file
    FILE *inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for the encrypted data
    unsigned char *encryptedData = malloc(fileSize + 1);
    if (encryptedData == NULL) {
        perror("Error allocating memory for encrypted data");
        exit(1);
    }

    // Read the input file into the buffer
    size_t bytesRead = fread(encryptedData, 1, fileSize, inputFile);
    if (bytesRead != fileSize) {
        perror("Error reading input file");
        exit(1);
    }

    // Encrypt the data using the key
    for (int i = 0; i < fileSize; i++) {
        encryptedData[i] ^= KEY[i % strlen(KEY)];
    }

    // Close the input file
    fclose(inputFile);

    // Open the output file
    FILE *outputFile = fopen("encrypted.txt", "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Write the encrypted data to the output file
    fwrite(encryptedData, 1, fileSize, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the allocated memory
    free(encryptedData);

    printf("File encrypted successfully!\n");
}

// Function to decrypt a file
void decryptFile(char *fileName) {
    // Open the input file
    FILE *inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for the decrypted data
    unsigned char *decryptedData = malloc(fileSize + 1);
    if (decryptedData == NULL) {
        perror("Error allocating memory for decrypted data");
        exit(1);
    }

    // Read the input file into the buffer
    size_t bytesRead = fread(decryptedData, 1, fileSize, inputFile);
    if (bytesRead != fileSize) {
        perror("Error reading input file");
        exit(1);
    }

    // Decrypt the data using the key
    for (int i = 0; i < fileSize; i++) {
        decryptedData[i] ^= KEY[i % strlen(KEY)];
    }

    // Close the input file
    fclose(inputFile);

    // Open the output file
    FILE *outputFile = fopen("decrypted.txt", "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Write the decrypted data to the output file
    fwrite(decryptedData, 1, fileSize, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the allocated memory
    free(decryptedData);

    printf("File decrypted successfully!\n");
}

// Function to print usage information
void usage(char *programName) {
    printf("Usage: %s <encrypt|decrypt> <file name>\n", programName);
    printf("Example: %s encrypt input.txt\n", programName);
    printf("Example: %s decrypt encrypted.txt\n", programName);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided enough arguments
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Get the operation (encrypt or decrypt)
    char *operation = argv[1];

    // Get the file name
    char *fileName = argv[2];

    // Call the appropriate function based on the operation
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(fileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(fileName);
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}