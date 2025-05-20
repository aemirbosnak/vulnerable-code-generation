//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to apply the XOR cipher encryption/decryption
void xorCipher(char *input, char *output, char *key, int length) {
    int keyLength = strlen(key);
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }
}

// Function to read input from a file
void readFile(const char *filename, char **content, int *length) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    *content = (char *)malloc(*length + 1);
    if (*content == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fread(*content, sizeof(char), *length, file);
    (*content)[*length] = '\0'; // Null terminate the string
    fclose(file);
}

// Function to write output to a file
void writeFile(const char *filename, char *content, int length) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    
    fwrite(content, sizeof(char), length, file);
    fclose(file);
}

// Main function to perform encryption and decryption
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *key = argv[3];

    char *inputContent;
    int inputLength;

    // Read the input file content
    readFile(inputFile, &inputContent, &inputLength);
    
    // Allocate memory for output content
    char *outputContent = (char *)malloc(inputLength);
    if (outputContent == NULL) {
        perror("Memory allocation failed");
        free(inputContent);
        exit(EXIT_FAILURE);
    }

    // Perform encryption using XOR cipher
    xorCipher(inputContent, outputContent, key, inputLength);

    // Write the encrypted content to the output file
    writeFile(outputFile, outputContent, inputLength);

    // Cleanup
    free(inputContent);
    free(outputContent);

    printf("Encryption completed. Encrypted data written to %s\n", outputFile);
    return EXIT_SUCCESS;
}