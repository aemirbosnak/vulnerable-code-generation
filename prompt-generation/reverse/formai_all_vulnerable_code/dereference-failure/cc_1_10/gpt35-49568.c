//FormAI DATASET v1.0 Category: File Encyptor ; Style: innovative
/*
* C File Encryptor
* By [Your Name]
* Encrypts the contents of a file using a simple Caesar Cipher
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *inputFile, char *outputFile, int key);
char encryptChar(char c, int key);
void printUsage(char *progName);

int main(int argc, char *argv[]) {
    // check if the correct number of arguments were passed
    if (argc != 4) {
        printUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // read the key from command arguments and convert to integer
    int key = atoi(argv[1]);

    // get file names from command arguments
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    // encrypt the file
    encrypt(inputFile, outputFile, key);

    printf("File encryption completed successfully.\n");

    return 0;
}

void encrypt(char *inputFile, char *outputFile, int key) {
    // open input and output files
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    // check if files were successfully opened
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return;
    }
    if (outFile == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    // read and encrypt each character in the input file
    char c;
    while ((c = fgetc(inFile)) != EOF) {
        char encrypted = encryptChar(c, key);
        fputc(encrypted, outFile);
    }

    // close files
    fclose(inFile);
    fclose(outFile);
}

char encryptChar(char c, int key) {
    if (c >= 'a' && c <= 'z') {
        c = ((c - 'a' + key) % 26) + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        c = ((c - 'A' + key) % 26) + 'A';
    }
    return c;
}

void printUsage(char *progName) {
    printf("Usage: %s <key> <input-file> <output-file>\n", progName);
    printf("Key is an integer between 0 and 25.\n");
}