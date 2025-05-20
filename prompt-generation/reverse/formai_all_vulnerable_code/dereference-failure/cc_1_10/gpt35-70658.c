//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// encrypt function
void encrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLen = strlen(key);
    int index = 0;
    char currentChar;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        char encrypted = (char)(currentChar ^ key[index++ % keyLen]);
        fputc(encrypted, outputFile);
    }
}

int main() {
    char *key = "mysecretkey1234";
    char *inputFilePath = "test.txt";
    char *encryptedFilePath = "test_encrypted.txt";
    char *decryptedFilePath = "test_decrypted.txt";

    FILE *inputFile = fopen(inputFilePath, "r");
    FILE *encryptedFile = fopen(encryptedFilePath, "w");
    FILE *decryptedFile = fopen(decryptedFilePath, "w");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    if (encryptedFile == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    if (decryptedFile == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // encrypt file
    encrypt(inputFile, encryptedFile, key);
    printf("File encrypted successfully.\n");

    // decrypt file
    fclose(encryptedFile);
    encryptedFile = fopen(encryptedFilePath, "r"); // reopen file for reading
    encrypt(encryptedFile, decryptedFile, key);
    printf("File decrypted successfully.\n");

    // close files
    fclose(inputFile);
    fclose(encryptedFile);
    fclose(decryptedFile);

    return 0;
}