//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 5

void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);
char shiftCharacter(char c, int shift);

int main() {
    char *inputFileName = "verona.txt"; // The text from which lovers' words shall dance
    char *outputFileName = "hidden_love.txt"; // A starlit chamber for secrets untold
    
    // Whisper to the winds of fortune
    printf("Alas, let us encrypt the sweet words of love...\n");
    encryptFile(inputFileName, outputFileName);
    
    printf("The words have been cloaked in shadows...\n");
    
    // A chance for their revelation
    printf("Shall we unmask their beauty?...\n");
    decryptFile(outputFileName, "revealed_love.txt"); 

    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (!inFile) {
        fprintf(stderr, "Oh, what melancholy! Could not open the input file.\n");
        exit(EXIT_FAILURE);
    }
    if (!outFile) {
        fprintf(stderr, "Alas, the output chamber could not be formed.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        char encryptedChar = shiftCharacter(c, SHIFT);
        fputc(encryptedChar, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (!inFile) {
        fprintf(stderr, "Oh, what a tragedy! Could not open the input file.\n");
        exit(EXIT_FAILURE);
    }
    if (!outFile) {
        fprintf(stderr, "Alas, the output chamber could not be formed.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        char decryptedChar = shiftCharacter(c, -SHIFT);
        fputc(decryptedChar, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

char shiftCharacter(char c, int shift) {
    // For letters only, leave all other characters unscathed
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + shift + 26) % 26 + 'A';
    } 
    else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + shift + 26) % 26 + 'a';
    }
    // Return the original character for non-alphabetic characters
    return c;
}