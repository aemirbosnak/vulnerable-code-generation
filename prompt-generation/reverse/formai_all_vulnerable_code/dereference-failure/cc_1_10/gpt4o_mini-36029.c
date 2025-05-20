//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void compress(char *input, char *output) {
    FILE *inputFile = fopen(input, "r");
    FILE *outputFile = fopen(output, "w");
    
    if (!inputFile || !outputFile) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    char currentChar;
    int count;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        count = 1;
        
        // Count occurrences of currentChar
        while ((currentChar == fgetc(inputFile)) && (count < 99)) {
            count++;
        }
        fseek(inputFile, -1, SEEK_CUR);  // Rewind to last read character
        
        // Write to output file
        fprintf(outputFile, "%c%d", currentChar, count);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decompress(char *input, char *output) {
    FILE *inputFile = fopen(input, "r");
    FILE *outputFile = fopen(output, "w");
    
    if (!inputFile || !outputFile) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    char currentChar;
    int count;

    while (fscanf(inputFile, "%c%d", &currentChar, &count) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(currentChar, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
        printf("File compressed successfully: %s -> %s\n", argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
        printf("File decompressed successfully: %s -> %s\n", argv[2], argv[3]);
    } else {
        fprintf(stderr, "The first argument must be either 'compress' or 'decompress'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}