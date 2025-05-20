//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function to encrypt the data using Caesar cipher
void encryptData(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = (data[i] - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = (data[i] - 'a' + key) % 26 + 'a';
        }
    }
}

// Function to decrypt the data using Caesar cipher
void decryptData(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = (data[i] - 'A' - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = (data[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

// Function to read a file and return its content
char* readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    char *buffer = (char *)malloc(MAX_BUFFER);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, sizeof(char), MAX_BUFFER, file);
    fclose(file);
    return buffer;
}

// Function to write data to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "%s", data);
    fclose(file);
}

// Main function to handle encryption and decryption
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    int key = atoi(argv[4]);

    char *data = readFile(inputFile);
    if (!data) {
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encryptData(data, key);
        writeFile(outputFile, data);
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptData(data, key);
        writeFile(outputFile, data);
        printf("File decrypted successfully.\n");
    } else {
        fprintf(stderr, "Invalid operation. Please use 'encrypt' or 'decrypt'\n");
        free(data);
        return EXIT_FAILURE;
    }

    free(data);
    return EXIT_SUCCESS;
}