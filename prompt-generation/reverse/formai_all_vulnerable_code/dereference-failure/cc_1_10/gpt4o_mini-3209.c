//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char* inputFile, const char* outputFile, int shift) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    char ch;

    if (inFile == NULL) {
        perror("Error opening input file");
        return;
    }
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    while ((ch = fgetc(inFile)) != EOF) {
        // Encrypt only alphabetic characters
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
        }
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char* inputFile, const char* outputFile, int shift) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    char ch;

    if (inFile == NULL) {
        perror("Error opening input file");
        return;
    }
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    while ((ch = fgetc(inFile)) != EOF) {
        // Decrypt only alphabetic characters
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' - shift + 26) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' - shift + 26) % 26;
        }
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    int choice, shift;
    char inputFile[100], outputFile[100];

    printf("Welcome to the File Encryptor/Decryptor!\n");
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please run the program again.\n");
        return 1;
    }

    printf("Choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the input file to encrypt: ");
            scanf("%s", inputFile);
            printf("Enter the name of the output file: ");
            scanf("%s", outputFile);
            encryptFile(inputFile, outputFile, shift);
            printf("File encrypted successfully!\n");
            break;

        case 2:
            printf("Enter the name of the input file to decrypt: ");
            scanf("%s", inputFile);
            printf("Enter the name of the output file: ");
            scanf("%s", outputFile);
            decryptFile(inputFile, outputFile, shift);
            printf("File decrypted successfully!\n");
            break;

        default:
            printf("Invalid choice. Please run the program again.\n");
            return 1;
    }

    return 0;
}