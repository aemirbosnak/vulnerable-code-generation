//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_NAME 100

// Function to check if a given character is a letter or not
int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

// Function to encrypt the given file
void encryptFile(FILE *inputFile, FILE *outputFile, int key) {
    char ch;
    int i = 0;

    // Read the input file character by character
    while ((ch = fgetc(inputFile))!= EOF) {
        // Encrypt the character using the key
        if (isLetter(ch)) {
            ch = (ch - 'a' + key) % 26 + 'a';
        }

        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }
}

int main() {
    char inputFileName[MAX_FILE_NAME], outputFileName[MAX_FILE_NAME];

    // Get the name of the input file from the user
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    // Get the name of the output file from the user
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // Open the input file for reading
    FILE *inputFile = fopen(inputFileName, "r");

    // Check if the input file was successfully opened
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open the output file for writing
    FILE *outputFile = fopen(outputFileName, "w");

    // Check if the output file was successfully opened
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Get the encryption key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the input file and write the result to the output file
    encryptFile(inputFile, outputFile, key);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Print a success message
    printf("File encrypted successfully.\n");

    return 0;
}