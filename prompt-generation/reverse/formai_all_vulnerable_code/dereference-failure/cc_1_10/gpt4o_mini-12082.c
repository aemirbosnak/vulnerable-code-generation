//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt/decrypt the file using XOR cipher
void xorCipher(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile, *outFile;
    int ch;

    // Open the input file in binary read mode
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in binary write mode
    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Read each byte from the input file, apply XOR with key, and write to the output file
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile);
    }

    // Clean up the file pointers
    fclose(inFile);
    fclose(outFile);
    printf("Process completed successfully. Output written to %s\n", outputFile);
}

// Function to display the program usage
void displayUsage() {
    printf("File Encryptor/Decryptor\n");
    printf("Usage: program_name <encrypt/decrypt> <input_file> <output_file> <key>\n");
    printf("Example: ./program_name encrypt input.txt output.enc x\n");
}

int main(int argc, char *argv[]) {
    // Check whether the correct number of arguments are provided
    if (argc != 5) {
        displayUsage();
        return EXIT_FAILURE;
    }

    // Validate operation type and determine the action
    if (strcmp(argv[1], "encrypt") == 0) {
        // Encrypt the file
        xorCipher(argv[2], argv[3], argv[4][0]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        // Decrypt the file
        xorCipher(argv[2], argv[3], argv[4][0]);
    } else {
        printf("Invalid operation. Please use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}