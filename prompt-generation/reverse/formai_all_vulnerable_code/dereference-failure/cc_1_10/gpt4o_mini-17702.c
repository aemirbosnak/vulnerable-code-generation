//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the file using XOR cipher
void processFile(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Buffer to hold file data
    unsigned char buffer[256];
    size_t bytesRead;

    // Read the input file, process data, and write to output file
    while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR operation with the key
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, outFile);
    }

    // Clean up
    fclose(inFile);
    fclose(outFile);
}

// Function to generate a simple key based on user input
char generateKey(const char *password) {
    char key = 0;
    for (size_t i = 0; password[i] != '\0'; i++) {
        key ^= password[i]; // XORing passwords characters for simple key generation
    }
    return key;
}

// Function to display usage instructions
void displayUsage() {
    printf("File Encryptor Utility\n");
    printf("Usage:\n");
    printf("  encryptor <input_file> <output_file> <password>\n");
    printf("or \n");
    printf("  encryptor -d <input_file> <output_file> <password>\n");
    printf("The -d flag is for decryption.\n");
    printf("The password can be any string and serves as the encryption key\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        displayUsage();
        return EXIT_FAILURE;
    }

    // Determine if processing is encryption or decryption
    int decryptMode = 0;
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *password = argv[3];

    if (strcmp(argv[1], "-d") == 0) {
        decryptMode = 1;
        inputFile = argv[2];
        outputFile = argv[3];
        password = argv[4];
    }

    // Generate key from password
    char key = generateKey(password);

    // Process the input file based on mode
    if (decryptMode) {
        printf("Decrypting the file...\n");
    } else {
        printf("Encrypting the file...\n");
    }

    processFile(inputFile, outputFile, key);

    printf("File processing completed successfully.\n");

    return EXIT_SUCCESS;
}