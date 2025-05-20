//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a simple XOR cipher
void encryptDecrypt(char *input, char *output, char key) {
    for(int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key; // Perform XOR operation
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

// Function to read the contents of the file into a buffer
char *readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Null-terminate the file content
    fclose(file);
    return buffer;
}

// Function to write the encrypted contents to a file
void writeFile(const char *filename, char *content) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

// Main function demonstrating file encryption and decryption with user interaction
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    char key = argv[3][0]; // Taking only the first character as key

    // Read the contents of the input file
    char *inputContent = readFile(inputFile);
    size_t inputLength = strlen(inputContent);

    // Allocate memory for the output buffer
    char *outputContent = (char *)malloc(inputLength + 1);
    if (!outputContent) {
        perror("Error allocating memory for output");
        free(inputContent);
        exit(EXIT_FAILURE);
    }

    // Encrypt the content
    encryptDecrypt(inputContent, outputContent, key);
    writeFile(outputFile, outputContent); // Write the encrypted content to output file

    printf("Encryption complete! Encrypted content written to %s\n", outputFile);

    // To demonstrate decryption
    // Re-initialize outputContent for decryption
    char *decryptedContent = (char *)malloc(inputLength + 1);
    if (!decryptedContent) {
        perror("Error allocating memory for decrypted output");
        free(inputContent);
        free(outputContent);
        exit(EXIT_FAILURE);
    }

    encryptDecrypt(outputContent, decryptedContent, key); // Decrypting using the same function

    const char *decryptedFile = "decrypted.txt";
    writeFile(decryptedFile, decryptedContent); // Write the decrypted content to a new file
    printf("Decryption complete! Decrypted content written to %s\n", decryptedFile);

    // Free allocated memory
    free(inputContent);
    free(outputContent);
    free(decryptedContent);

    return 0;
}