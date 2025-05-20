//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 8

// Function to encrypt the file contents
void encrypt(FILE *inputFile, FILE *outputFile) {
    char buffer[BLOCK_SIZE];
    int i;

    while (fread(buffer, 1, BLOCK_SIZE, inputFile) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(buffer, 1, BLOCK_SIZE, outputFile);
    }
}

// Function to decrypt the file contents
void decrypt(FILE *inputFile, FILE *outputFile) {
    char buffer[BLOCK_SIZE];
    int i;

    while (fread(buffer, 1, BLOCK_SIZE, inputFile) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(buffer, 1, BLOCK_SIZE, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inFileName[100], outFileName[100];

    // Get the input and output file names from the user
    printf("Enter the input file name: ");
    scanf("%s", inFileName);
    printf("Enter the output file name: ");
    scanf("%s", outFileName);

    // Open the input and output files
    inputFile = fopen(inFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt the file contents
    encrypt(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption completed successfully.\n");

    return 0;
}