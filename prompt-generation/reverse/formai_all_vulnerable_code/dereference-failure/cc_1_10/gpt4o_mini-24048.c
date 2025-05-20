//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define WATERMARK "WATERMARK"

// Function to embed watermark into the text
void embedWatermark(char *inputFile, char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "w");
    if (!outFile) {
        perror("Failed to open output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), inFile)) {
        // Embed watermark at random position
        int position = rand() % (strlen(line) - 1);
        char temp[MAX_LEN];
        snprintf(temp, position + 1, "%s", line);
        snprintf(temp + position, MAX_LEN - position, "%s%s", WATERMARK, line + position);
        fputs(temp, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

// Function to extract watermark from the text
void extractWatermark(char *inputFile, char *extractedFile) {
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(extractedFile, "w");
    if (!outFile) {
        perror("Failed to open extracted file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), inFile)) {
        char *watermarkPos = strstr(line, WATERMARK);
        if (watermarkPos != NULL) {
            fputs(line, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);
}

// Function to display usage of the program
void displayUsage(char *programName) {
    printf("Usage:\n");
    printf("  %s embed <inputFile> <outputFile>\n", programName);
    printf("  %s extract <inputFile> <extractedFile>\n", programName);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 4) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL)); // Seed for randomness

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3]);
        printf("Watermark embedded successfully into %s\n", argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractWatermark(argv[2], argv[3]);
        printf("Watermark extracted successfully to %s\n", argv[3]);
    } else {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}