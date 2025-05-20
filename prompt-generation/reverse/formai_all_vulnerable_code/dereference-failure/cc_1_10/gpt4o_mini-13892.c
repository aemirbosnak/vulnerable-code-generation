//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void encryptDecryptFile(const char *inputFileName, const char *outputFileName, char key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    int byte;
    while ((byte = fgetc(inputFile)) != EOF) {
        fputc(byte ^ key, outputFile); // XOR operation for encryption/decryption
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File %s processed and saved as %s\n", inputFileName, outputFileName);
}

char getChoice() {
    char choice;
    printf("Do you want to (e)ncrypt or (d)ecrypt a file? ");
    scanf(" %c", &choice);
    return choice;
}

void getFileNames(char *inputFileName, char *outputFileName) {
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);
}

int main() {
    char choice;
    char inputFileName[MAX_FILENAME_LENGTH];
    char outputFileName[MAX_FILENAME_LENGTH];
    char key;

    choice = getChoice();

    if (choice == 'e' || choice == 'd') {
        getFileNames(inputFileName, outputFileName);
        printf("Enter the encryption/decryption key (single character): ");
        scanf(" %c", &key);

        if (choice == 'e') {
            encryptDecryptFile(inputFileName, outputFileName, key);
        } else {
            encryptDecryptFile(inputFileName, outputFileName, key);
        }
    } else {
        printf("Invalid choice! Please run the program again and select either 'e' or 'd'.\n");
    }

    return 0;
}