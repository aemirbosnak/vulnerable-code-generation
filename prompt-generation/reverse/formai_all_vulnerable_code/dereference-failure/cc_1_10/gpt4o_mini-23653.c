//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(char *input, char *output, char key) {
    // Process the input buffer and XOR each byte with the key
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key;
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void encryptFile(const char *inputFileName, const char *outputFileName, char key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");
    
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFileName);
        exit(1);
    }
    if (outputFile == NULL) {
        printf("Error creating output file: %s\n", outputFileName);
        fclose(inputFile);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char encryptedBuffer[BUFFER_SIZE];

    while (fread(buffer, sizeof(char), BUFFER_SIZE, inputFile) > 0) {
        // Perform encryption on the buffer read from the input file
        encryptDecrypt(buffer, encryptedBuffer, key);
        fwrite(encryptedBuffer, sizeof(char), BUFFER_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

void decryptFile(const char *inputFileName, const char *outputFileName, char key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");
    
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFileName);
        exit(1);
    }
    if (outputFile == NULL) {
        printf("Error creating output file: %s\n", outputFileName);
        fclose(inputFile);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char decryptedBuffer[BUFFER_SIZE];

    while (fread(buffer, sizeof(char), BUFFER_SIZE, inputFile) > 0) {
        // Perform decryption on the buffer read from the input file
        encryptDecrypt(buffer, decryptedBuffer, key);
        fwrite(decryptedBuffer, sizeof(char), BUFFER_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File decrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <encrypt|decrypt> <inputfile> <outputfile> <key>\n", argv[0]);
        return 1;
    }

    char *action = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    char key = argv[4][0]; // Get the first character as the key

    if (strcmp(action, "encrypt") == 0) {
        encryptFile(inputFileName, outputFileName, key);
    } else if (strcmp(action, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName, key);
    } else {
        printf("Invalid action specified. Use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}