//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the encryption function
unsigned char encrypt(unsigned char c, unsigned char k) {
    return (c + k) % 256;
}

// Define the decryption function
unsigned char decrypt(unsigned char c, unsigned char k) {
    return (c - k) % 256;
}

// Define the main function
int main() {
    // Declare the variables
    char filename[100];
    char key[100];
    FILE *inputFile;
    FILE *outputFile;
    int i;

    // Get the filename
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    // Get the key
    printf("Enter the key: ");
    scanf("%s", key);

    // Open the input file
    inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    // Open the output file
    outputFile = fopen("encrypted.txt", "wb");
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Read the input file and encrypt the data
    while ((i = fgetc(inputFile)) != EOF) {
        fputc(encrypt(i, key[i % strlen(key)]), outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    // Print a success message
    printf("File encrypted successfully.\n");

    return 0;
}