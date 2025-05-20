//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the data
void xorEncryptDecrypt(char *input, char *output, char key) {
    while (*input) {
        *output = *input ^ key; // XOR operation
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

// Function to read data from a file
char *readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(length + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string
    
    fclose(file);
    return buffer;
}

// Function to write encrypted data to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    char key = 'K'; // Simple key for XOR operation

    char *fileData = readFile(inputFileName);
    if (!fileData) {
        return 1;
    }

    char *resultData = (char *)malloc(strlen(fileData) + 1);
    if (!resultData) {
        perror("Memory allocation failed for result data");
        free(fileData);
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        xorEncryptDecrypt(fileData, resultData, key);
        printf("File encrypted successfully!\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        xorEncryptDecrypt(fileData, resultData, key);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid operation! Use 'encrypt' or 'decrypt'.\n");
        free(fileData);
        free(resultData);
        return 1;
    }

    writeFile(outputFileName, resultData);

    free(fileData);
    free(resultData);

    return 0;
}