//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key for XOR operation
#define KEY 0xAB

// Function to encrypt a file
void encrypt(char* filename) {
    FILE* file = fopen(filename, "rb+");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    // Find the file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file content
    char* content = (char*)malloc(size);
    if (!content) {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    // Read the file content into memory
    fread(content, 1, size, file);

    // Encrypt the file content with XOR operation
    for (int i = 0; i < size; i++) {
        content[i] = content[i] ^ KEY;
    }

    // Write the encrypted content back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(content, 1, size, file);

    // Free the memory and close the file
    free(content);
    fclose(file);

    printf("File %s encrypted successfully\n", filename);
}

// Function to decrypt a file
void decrypt(char* filename) {
    FILE* file = fopen(filename, "rb+");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    // Find the file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file content
    char* content = (char*)malloc(size);
    if (!content) {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    // Read the file content into memory
    fread(content, 1, size, file);

    // Decrypt the file content with XOR operation
    for (int i = 0; i < size; i++) {
        content[i] = content[i] ^ KEY;
    }

    // Write the decrypted content back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(content, 1, size, file);

    // Free the memory and close the file
    free(content);
    fclose(file);

    printf("File %s decrypted successfully\n", filename);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt/decrypt> <file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2]);
    }
    else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2]);
    }
    else {
        printf("Invalid command %s\n", argv[1]);
        return 1;
    }

    return 0;
}