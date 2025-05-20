//FormAI DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(FILE *fpIn, FILE *fpOut, char *key) {
    int i = 0;
    char ch;
    long keyLen = strlen(key);

    while ((ch = fgetc(fpIn)) != EOF) {
        ch = ch ^ key[i % keyLen];
        fputc(ch, fpOut);
        i++;
    }
}

void decryptFile(FILE *fpIn, FILE *fpOut, char *key) {
    int i = 0;
    char ch;
    long keyLen = strlen(key);

    while ((ch = fgetc(fpIn)) != EOF) {
        ch = ch ^ key[i % keyLen];
        fputc(ch, fpOut);
        i++;
    }
}

int main() {
    char fileName[100], newFileName[100], key[100], choice;
    FILE *fpIn, *fpOut;
    
    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", fileName);

    printf("Enter the key to use for encryption/decryption: ");
    scanf("%s", key);

    fpIn = fopen(fileName, "rb");

    if (fpIn == NULL) {
        printf("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    printf("Do you want to encrypt or decrypt the file? (E/D): ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        printf("Enter the new file name for encrypted file: ");
        scanf("%s", newFileName);

        fpOut = fopen(newFileName, "wb");

        if (fpOut == NULL) {
            printf("Unable to create output file!");
            exit(EXIT_FAILURE);
        }

        encryptFile(fpIn, fpOut, key);
        printf("File encrypted successfully!");
    }
    else if (choice == 'D' || choice == 'd') {
        printf("Enter the new file name for decrypted file: ");
        scanf("%s", newFileName);

        fpOut = fopen(newFileName, "wb");

        if (fpOut == NULL) {
            printf("Unable to create output file!");
            exit(EXIT_FAILURE);
        }

        decryptFile(fpIn, fpOut, key);
        printf("File decrypted successfully!");
    }
    else {
        printf("Invalid option!");
        exit(EXIT_FAILURE);
    }

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}