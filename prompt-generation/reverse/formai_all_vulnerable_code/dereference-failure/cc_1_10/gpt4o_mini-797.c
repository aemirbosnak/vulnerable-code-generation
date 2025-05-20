//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function to encrypt a string using Caesar cipher
void encrypt(char *input, char *output, int shift) {
    for(int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Encrypting uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypting lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        output[i] = ch;
    }
}

// Main function to handle file operations
int main(int argc, char *argv[]) {
    // Ensure correct usage
    if(argc != 4) {
        printf("Usage: %s <input file> <output file> <shift>\n", argv[0]);
        return 1;
    }

    // File pointers for input and output
    FILE *inputFile, *outputFile;
    char buffer[MAX_BUFFER];
    int shift = atoi(argv[3]);

    // Open the input file for reading
    inputFile = fopen(argv[1], "r");
    if(inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen(argv[2], "w");
    if(outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Read the input file and encrypt its content
    while(fgets(buffer, MAX_BUFFER, inputFile) != NULL) {
        char encryptedBuffer[MAX_BUFFER];
        encrypt(buffer, encryptedBuffer, shift);
        
        // Write the encrypted content to output file
        fputs(encryptedBuffer, outputFile);
    }

    // Clean up and close files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption completed successfully!\n");
    return 0;
}