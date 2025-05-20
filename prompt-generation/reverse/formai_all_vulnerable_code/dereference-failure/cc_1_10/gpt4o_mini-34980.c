//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt data using XOR cipher
void encryptDecrypt(char *data, char key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= key; // XOR operation
    }
}

// Function to read a file and return its contents
char* readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file for reading");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fileSize + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Null-terminate the string
    fclose(file);
    
    return buffer;
}

// Function to write data to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    char key = argv[3][0]; // Use the first character of the key

    // Read file
    char *fileData = readFile(inputFile);
    if (!fileData) {
        return EXIT_FAILURE;
    }

    // Encrypt data
    encryptDecrypt(fileData, key);

    // Write encrypted data to output file
    writeFile(outputFile, fileData);

    // Cleanup
    free(fileData);
    printf("File encrypted successfully and saved as '%s'\n", outputFile);
    
    return EXIT_SUCCESS;
}