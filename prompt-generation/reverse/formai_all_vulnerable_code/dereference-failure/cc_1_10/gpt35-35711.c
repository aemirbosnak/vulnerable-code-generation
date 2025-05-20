//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C File Encryptor!\n");

    // Get input file name
    char inputFileName[100];
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file for reading
    FILE* inputFile;
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return -1;
    }

    // Get output file name
    char outputFileName[100];
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open output file for writing
    FILE* outputFile;
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return -1;
    }

    // Generate encryption key
    int key = rand() % 256;

    // Write key to output file
    fputc(key, outputFile);

    // Encrypt input file and write to output file
    int inputByte = fgetc(inputFile);
    while (inputByte != EOF) {
        int encryptedByte = inputByte ^ key;
        fputc(encryptedByte, outputFile);
        inputByte = fgetc(inputFile);
    }

    // Close files and print success message
    fclose(inputFile);
    fclose(outputFile);
    printf("File encryption complete! Key: %d\n", key);
    return 0;
}