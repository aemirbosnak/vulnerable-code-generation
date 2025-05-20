//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// Function to compress text using Run-Length Encoding (RLE)
void compress(const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    char currentChar;
    int count;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        count = 1;
        
        while ((currentChar == fgetc(inputFile)) && currentChar != EOF) {
            count++;
        }
        fseek(inputFile, -1, SEEK_CUR); // Move back to last character

        fprintf(outputFile, "%c%d", currentChar, count);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Compression completed. Output file: %s\n", outputFilename);
}

// Function to decompress RLE compressed text
void decompress(const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
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
    printf("Decompression completed. Output file: %s\n", outputFilename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress/decompress> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'compress' or 'decompress'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}