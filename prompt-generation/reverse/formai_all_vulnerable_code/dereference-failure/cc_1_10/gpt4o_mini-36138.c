//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3  // Set the shift for encryption

// Function prototypes
void encryptFile(const char *inputFileName, const char *outputFileName);
void decryptFile(const char *inputFileName, const char *outputFileName);
void shiftCipher(char *buffer, int key);
void readFile(const char *fileName, char **buffer);
void writeFile(const char *fileName, const char *buffer);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFileName, outputFileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void encryptFile(const char *inputFileName, const char *outputFileName) {
    char *buffer = NULL;
    readFile(inputFileName, &buffer);
    if (buffer) {
        shiftCipher(buffer, SHIFT);
        writeFile(outputFileName, buffer);
        free(buffer);
        printf("File encrypted successfully: %s\n", outputFileName);
    }
}

void decryptFile(const char *inputFileName, const char *outputFileName) {
    char *buffer = NULL;
    readFile(inputFileName, &buffer);
    if (buffer) {
        shiftCipher(buffer, -SHIFT);
        writeFile(outputFileName, buffer);
        free(buffer);
        printf("File decrypted successfully: %s\n", outputFileName);
    }
}

void shiftCipher(char *buffer, int key) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] = (buffer[i] - 'a' + key + 26) % 26 + 'a';
        } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] = (buffer[i] - 'A' + key + 26) % 26 + 'A';
        }
        // Non-alphabetical characters remain unchanged
    }
}

void readFile(const char *fileName, char **buffer) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(fileSize + 1);
    if (!*buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, fileSize, file);
    (*buffer)[fileSize] = '\0';  // Null-terminate the string
    fclose(file);
}

void writeFile(const char *fileName, const char *buffer) {
    FILE *file = fopen(fileName, "w");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", fileName);
        free((char *)buffer);
        exit(EXIT_FAILURE);
    }
    
    fputs(buffer, file);
    fclose(file);
}