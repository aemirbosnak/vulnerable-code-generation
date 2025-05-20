//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt or decrypt the file using XOR operation
void processFile(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR encryption/decryption
    }

    fclose(inFile);
    fclose(outFile);
}

// Function to display usage instructions
void displayUsage() {
    printf("File Encryptor/Decryptor\n");
    printf("Usage:\n");
    printf("  encrypt <input_file> <output_file> <key>\n");
    printf("  decrypt <input_file> <output_file> <key>\n");
    printf("  <key> should be a single character.\n");
}

// Main function to handle command line arguments and process files
int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    char key = argv[4][0]; // Take the first character as the key

    if (operation[0] == 'e') {
        // Encrypting the file
        processFile(inputFile, outputFile, key);
        printf("File encrypted successfully.\n");
    } else if (operation[0] == 'd') {
        // Decrypting the file
        processFile(inputFile, outputFile, key);
        printf("File decrypted successfully.\n");
    } else {
        displayUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}