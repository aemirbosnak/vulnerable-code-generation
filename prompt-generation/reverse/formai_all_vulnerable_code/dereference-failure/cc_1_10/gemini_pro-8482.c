//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define ENCRYPT 1
#define DECRYPT 0

void printUsage(char *programName) {
    printf("Usage: %s <mode> <filename>\n", programName);
    printf("Mode can be either 'encrypt' or 'decrypt'\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
    }

    FILE *inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int mode;
    if (strcmp(argv[1], "encrypt") == 0) {
        mode = ENCRYPT;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        mode = DECRYPT;
    } else {
        printUsage(argv[0]);
    }

    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (mode == ENCRYPT) {
            c += 5;
        } else {
            c -= 5;
        }
        fputc(c, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File %s successfully %s\n", argv[2], mode == ENCRYPT ? "encrypted" : "decrypted");

    return EXIT_SUCCESS;
}