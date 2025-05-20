//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char encryptedLine[100];
        strcpy(encryptedLine, line);

        char *encryptedLinePtr = encryptedLine;
        char *inputLinePtr = line;
        while (*encryptedLinePtr!= '\0') {
            *encryptedLinePtr = *inputLinePtr + 2;
            ++encryptedLinePtr;
            ++inputLinePtr;
        }

        fprintf(outputFile, "%s", encryptedLine);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char decryptedLine[100];
        strcpy(decryptedLine, line);

        char *decryptedLinePtr = decryptedLine;
        char *inputLinePtr = line;
        while (*decryptedLinePtr!= '\0') {
            *decryptedLinePtr = *inputLinePtr - 2;
            ++decryptedLinePtr;
            ++inputLinePtr;
        }

        fprintf(outputFile, "%s", decryptedLine);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    const char *inputFileName = "input.txt";
    const char *outputFileName = "encrypted.txt";

    encryptFile(inputFileName, outputFileName);

    const char *inputFileNameDecrypted = "encrypted.txt";
    const char *outputFileNameDecrypted = "decrypted.txt";

    decryptFile(inputFileNameDecrypted, outputFileNameDecrypted);

    return 0;
}