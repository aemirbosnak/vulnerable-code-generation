//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "SherlockHolmes"

void encrypt(FILE *inputFile, FILE *outputFile) {
    char ch;
    int flag = 0;

    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            if (flag == 0) {
                ch = toupper(ch);
                flag = 1;
            } else {
                ch = tolower(ch);
                flag = 0;
            }
        } else {
            flag = 0;
        }
        fputc(ch, outputFile);
    }
}

void decrypt(FILE *inputFile, FILE *outputFile) {
    char ch;
    int flag = 0;

    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            if (flag == 0) {
                ch = tolower(ch);
                flag = 1;
            } else {
                ch = toupper(ch);
                flag = 0;
            }
        } else {
            flag = 0;
        }
        fputc(ch, outputFile);
    }
}

int main() {
    char inputFileName[100], outputFileName[100];
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    printf("Enter the encryption/decryption mode (e/d): ");
    char mode;
    scanf("%c", &mode);

    if (mode == 'e' || mode == 'E') {
        encrypt(inputFile, outputFile);
        printf("File encrypted successfully.\n");
    } else if (mode == 'd' || mode == 'D') {
        decrypt(inputFile, outputFile);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode.\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}