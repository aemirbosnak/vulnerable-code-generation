//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile, char key);
void decryptFile(const char *inputFile, const char *outputFile, char key);
void displayUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    char key = argv[4][0];

    if (strcmp(mode, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, key);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void displayUsage(const char *programName) {
    printf("Usage: %s <mode> <input_file> <output_file> <key>\n", programName);
    printf("<mode> can be either 'encrypt' or 'decrypt'.\n");
    printf("Example: %s encrypt myfile.txt myfile.enc A\n", programName);
}

void encryptFile(const char *inputFile, const char *outputFile, char key) {
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
        fputc(ch ^ key, outFile); // XOR encryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("File encrypted as %s\n", outputFile);
}

void decryptFile(const char *inputFile, const char *outputFile, char key) {
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
        fputc(ch ^ key, outFile); // XOR decryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("File decrypted as %s\n", outputFile);
}