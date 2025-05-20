//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128
#define BUFFER_SIZE 1024

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *password) {
    int passwordLength = strlen(password);
    int currentChar;
    int i = 0;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        fputc(currentChar ^ password[i % passwordLength], outputFile);
        i++;
    }
}

void fileCipher(const char *inputFileName, const char *outputFileName, const char *password, int encrypt) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    if (encrypt) {
        printf("Encrypting %s to %s...\n", inputFileName, outputFileName);
    } else {
        printf("Decrypting %s to %s...\n", inputFileName, outputFileName);
    }

    encryptDecrypt(inputFile, outputFile, password);

    fclose(inputFile);
    fclose(outputFile);
}

void promptUser() {
    printf("Welcome to the File Encryptor/Decryptor!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char inputFileName[256];
    char outputFileName[256];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        promptUser();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter the input file name: ");
        fgets(inputFileName, sizeof(inputFileName), stdin);
        strtok(inputFileName, "\n"); // Remove newline character

        printf("Enter the output file name: ");
        fgets(outputFileName, sizeof(outputFileName), stdin);
        strtok(outputFileName, "\n"); // Remove newline character

        printf("Enter the password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
        fgets(password, sizeof(password), stdin);
        strtok(password, "\n"); // Remove newline character

        if (choice == 1) {
            fileCipher(inputFileName, outputFileName, password, 1);
        } else if (choice == 2) {
            fileCipher(inputFileName, outputFileName, password, 0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Thank you for using the File Encryptor/Decryptor!\n");
    return 0;
}