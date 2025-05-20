//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 10

// Function to encrypt the file
void encrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = ch + key[i];
            if (ch > 'z') {
                ch = ch - 26;
            } else if (ch < 'a') {
                ch = ch + 26;
            }
            fprintf(outputFile, "%c", ch);
        } else {
            fprintf(outputFile, "%c", ch);
        }
        i++;
        if (i == KEY_SIZE) {
            i = 0;
        }
    }
}

// Function to decrypt the file
void decrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = ch - key[i];
            if (ch < 'a') {
                ch = ch + 26;
            } else if (ch > 'z') {
                ch = ch - 26;
            }
            fprintf(outputFile, "%c", ch);
        } else {
            fprintf(outputFile, "%c", ch);
        }
        i++;
        if (i == KEY_SIZE) {
            i = 0;
        }
    }
}

int main() {
    char inputFileName[100], outputFileName[100], key[KEY_SIZE];

    // Get the input file name
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // Get the output file name
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Get the encryption/decryption key
    printf("Enter the key: ");
    scanf("%s", key);

    // Open the input file
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        exit(1);
    }

    // Encrypt the file
    encrypt(inputFile, outputFile, key);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted/decrypted successfully\n");

    return 0;
}