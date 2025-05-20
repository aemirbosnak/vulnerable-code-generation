//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully to %s\n", outputFileName);
}

void printUsage() {
    printf("Usage: ./file_encryptor <input_file> <output_file> <shift>\n");
    printf("Example: ./file_encryptor plaintext.txt encrypted.txt 3\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    int shift = atoi(argv[3]);

    if (shift < 0 || shift > 25) {
        printf("Shift must be between 0 and 25.\n");
        return EXIT_FAILURE;
    }

    encryptFile(inputFileName, outputFileName, shift);
    return EXIT_SUCCESS;
}