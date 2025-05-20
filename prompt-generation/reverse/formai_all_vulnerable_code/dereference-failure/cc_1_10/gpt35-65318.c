//FormAI DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encryptFile(char* inFile, char* keyFile, char* outFile) {
    FILE *fpIn, *fpKey, *fpOut;
    char inputChar, keyChar;
    int i = 0;

    // Open the input file for reading
    fpIn = fopen(inFile, "r");
    if(fpIn == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the key file for reading
    fpKey = fopen(keyFile, "r");
    if(fpKey == NULL) {
        printf("Error opening key file.\n");
        exit(1);
    }

    // Open the output file for writing
    fpOut = fopen(outFile, "w");
    if(fpOut == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read and encrypt the data
    while((inputChar = fgetc(fpIn)) != EOF) {
        keyChar = fgetc(fpKey);
        if(keyChar == EOF) {
            // If the end of key file has been reached, start from the beginning
            fseek(fpKey, 0, SEEK_SET);
            keyChar = fgetc(fpKey);
        }
        fputc(inputChar ^ keyChar, fpOut);
    }

    // Close files
    fclose(fpIn);
    fclose(fpKey);
    fclose(fpOut);

    printf("Encryption successful!\n");
}

int main() {
    char inFile[MAX_LEN], keyFile[MAX_LEN], outFile[MAX_LEN];

    // Prompt user for input file
    printf("Enter the name of the file to be encrypted: ");
    fgets(inFile, MAX_LEN, stdin);
    strtok(inFile, "\n");

    // Prompt user for key file
    printf("Enter the name of the key file: ");
    fgets(keyFile, MAX_LEN, stdin);
    strtok(keyFile, "\n");

    // Prompt user for output file
    printf("Enter the name of the output file: ");
    fgets(outFile, MAX_LEN, stdin);
    strtok(outFile, "\n");

    // Encrypt the file
    encryptFile(inFile, keyFile, outFile);

    return 0;
}