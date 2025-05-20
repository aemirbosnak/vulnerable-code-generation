//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum size of the file to be encrypted

void encrypt(FILE *inputFile, FILE *outputFile, char *password) {
    int i = 0;
    char ch;

    while ((ch = fgetc(inputFile)) != EOF && i < MAX_FILE_SIZE) {
        ch = ch ^ password[i % strlen(password)]; // encrypt using XOR operator
        fputc(ch, outputFile);
        i++;
    }

    printf("Encryption Successful!\n");
}

void decrypt(FILE *inputFile, FILE *outputFile, char *password) {
    int i = 0;
    char ch;

    while ((ch = fgetc(inputFile)) != EOF && i < MAX_FILE_SIZE) {
        ch = ch ^ password[i % strlen(password)]; // decrypt using XOR operator
        fputc(ch, outputFile);
        i++;
    }

    printf("Decryption Successful!\n");
}

int main() {
    FILE *inputFile, *outputFile;
    char password[100], inputFileName[100], outputFileName[100];

    // get the input file name from the user
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    // open the input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open %s\n", inputFileName);
        exit(1);
    }

    // get the output file name from the user
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // open the output file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open %s\n", outputFileName);
        exit(1);
    }

    // get the password from the user
    printf("Enter the password: ");
    scanf("%s", password);

    // encrypt the file
    encrypt(inputFile, outputFile, password);

    // close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // open the encrypted file for decryption
    inputFile = fopen(outputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open %s\n", outputFileName);
        exit(1);
    }

    // get the decrypted file name from the user
    printf("Enter the name of the decrypted file: ");
    scanf("%s", outputFileName);

    // open the decrypted file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open %s\n", outputFileName);
        exit(1);
    }

    // decrypt the file
    decrypt(inputFile, outputFile, password);

    // close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}