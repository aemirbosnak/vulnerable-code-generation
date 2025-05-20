//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file data using a simple substitution cipher
void encryptData(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] = data[i] + key; // Shift character by 'key' positions
    }
}

// Function to decrypt the file data
void decryptData(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] = data[i] - key; // Shift character back by 'key' positions
    }
}

// Function to read content from a file
char* readFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = malloc(filesize + 1);
    if (!buffer) {
        perror("Unable to allocate memory");
        fclose(file);
        return NULL;
    }
    
    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0'; // Null-terminate the string
    fclose(file);
    
    return buffer;
}

// Function to write content to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open the file for writing");
        return;
    }

    fprintf(file, "%s", data);
    fclose(file);
}

// Main function demonstrating file encryption and decryption
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];

    // Define a key for the encryption
    int key = 3; // Simple Caesar Cipher shift

    // Read content from the input file
    char *fileContent = readFile(inputFile);
    if (!fileContent) {
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        // Encrypt the file content
        encryptData(fileContent, key);
        writeFile(outputFile, fileContent);
        printf("File encrypted successfully and saved as %s\n", outputFile);
    } else if (strcmp(operation, "decrypt") == 0) {
        // Decrypt the file content
        decryptData(fileContent, key);
        writeFile(outputFile, fileContent);
        printf("File decrypted successfully and saved as %s\n", outputFile);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        free(fileContent);
        return EXIT_FAILURE;
    }

    free(fileContent);
    return EXIT_SUCCESS;
}