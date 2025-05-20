//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Key function to encrypt or decrypt the file
void encryptDecrypt(FILE *inputFile, FILE *outputFile, char *key) {
    char ch;
    int i = 0;
    int keyLength = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {
        // XOR operation between the key and the input file character
        ch = ch ^ key[i];
        fputc(ch, outputFile);

        // Reset index if key has been fully used
        i++;
        if (i == keyLength) {
            i = 0;
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50], key[50];
    int choice;

    printf("Welcome to the C File Encryption program!\n\n");

    // Get input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    // Attempt to open input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file. Please check the file name and try again.\n");
        return 1;
    }

    // Get output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // Attempt to open output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file. Please check the file name and try again.\n");
        return 1;
    }

    // Get encryption/decryption key from user
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Ask user whether to encrypt or decrypt the file
    printf("Do you want to encrypt or decrypt the file? (Enter 1 for encrypt or 2 for decrypt): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Encrypt the input file
            encryptDecrypt(inputFile, outputFile, key);
            printf("File encryption completed successfully!\n");
            break;
        case 2:
            // Decrypt the input file
            encryptDecrypt(inputFile, outputFile, key);
            printf("File decryption completed successfully!\n");
            break;
        default:
            printf("Invalid choice. Please enter 1 to encrypt or 2 to decrypt.\n");
            break;
    }

    // Close file pointers
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}