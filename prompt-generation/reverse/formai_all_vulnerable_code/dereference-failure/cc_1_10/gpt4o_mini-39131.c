//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void compress(const char *inputFile, const char *outputFile);
void decompress(const char *inputFile, const char *outputFile);
void fatal(const char *msg);

int main() {
    char *inputFile = "romeo_juliet.txt";
    char *outputFile = "compressed.rj";
    char *decompressedFile = "decompressed.txt";

    printf("Alas, fair user! The adventure begins...\n");
    
    // Compress
    printf("Compressing the tales of love...\n");
    compress(inputFile, outputFile);
    
    // Decompress
    printf("Reviving the words of yore...\n");
    decompress(outputFile, decompressedFile);
    
    printf("Thus completes the cycle of love! Files hath been processed.\n");
    return 0;
}

void fatal(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

void compress(const char *inputFile, const char *outputFile) {
    FILE *inFile, *outFile;
    inFile = fopen(inputFile, "r");
    if (!inFile) fatal("Cannot open input file");

    outFile = fopen(outputFile, "w");
    if (!outFile) fatal("Cannot open output file");

    char ch;
    int count = 1;

    while ((ch = fgetc(inFile)) != EOF) {
        char nextCh = fgetc(inFile);
        if (ch == nextCh) {
            count++;
        } else {
            fprintf(outFile, "%c%d", ch, count);
            count = 1;
            if (nextCh != EOF) {
                ungetc(nextCh, inFile); // Put back char if it's read but not repeated
            }
        }
    }

    fclose(inFile);
    fclose(outFile);

    printf("The ink hath dried, compression complete! 🎭\n");
}

void decompress(const char *inputFile, const char *outputFile) {
    FILE *inFile, *outFile;
    inFile = fopen(inputFile, "r");
    if (!inFile) fatal("Cannot open input file");

    outFile = fopen(outputFile, "w");
    if (!outFile) fatal("Cannot open output file");

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        int count = 0;
        // Read the number that follows the character
        while (isdigit(ch)) {
            count = count * 10 + (ch - '0');
            ch = fgetc(inFile);
        }
        ungetc(ch, inFile); // Put back the character for next reading
        for (int i = 0; i < count; ++i) {
            fputc(ch, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);

    printf("The secrets of love reborn, decompression hath been achieved! 🌹\n");
}