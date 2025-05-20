//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "mysecretkey"

// Function to encrypt the file
void encryptFile(FILE* inputFile, FILE* outputFile) {
    char inputBuffer[1024];
    char outputBuffer[1024];
    int i = 0;

    // Read the input file in chunks
    while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
        // Encrypt each line of the file using the key
        for (int j = 0; j < strlen(inputBuffer); j++) {
            outputBuffer[i++] = inputBuffer[j] ^ KEY[j % strlen(KEY)];
        }
        outputBuffer[i++] = '\n';
    }

    // Write the encrypted data to the output file
    fwrite(outputBuffer, sizeof(char), i, outputFile);
}

// Function to decrypt the file
void decryptFile(FILE* inputFile, FILE* outputFile) {
    char inputBuffer[1024];
    char outputBuffer[1024];
    int i = 0;

    // Read the input file in chunks
    while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
        // Decrypt each line of the file using the key
        for (int j = 0; j < strlen(inputBuffer); j++) {
            outputBuffer[i++] = inputBuffer[j] ^ KEY[j % strlen(KEY)];
        }
        outputBuffer[i++] = '\n';
    }

    // Write the decrypted data to the output file
    fwrite(outputBuffer, sizeof(char), i, outputFile);
}

int main() {
    // Open the input and output files
    FILE* inputFile = fopen("input.txt", "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* outputFile = fopen("output.txt", "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt the input file
    encryptFile(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}