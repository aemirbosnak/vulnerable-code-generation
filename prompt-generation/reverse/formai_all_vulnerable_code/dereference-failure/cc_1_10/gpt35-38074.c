//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 512
#define MAX_WATERMARK_LENGTH 64
#define MAX_FILE_NAME_LENGTH 256

// Function to add watermark to the given file
void addWatermark(FILE* inputFile, FILE* outputFile, char* watermark) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        int lineLength = strlen(line);
        int watermarkLength = strlen(watermark);
        char newLine[MAX_LINE_LENGTH + MAX_WATERMARK_LENGTH];

        // Checking if the line already contains watermark to avoid repetition
        if (strstr(line, watermark) == NULL) {
            // Adding watermark at the end of the line
            sprintf(newLine, "%s%s", line, watermark);
            fputs(newLine, outputFile);
        }
        else {
            fputs(line, outputFile);
        }
    }
}

int main() {
    char watermark[MAX_WATERMARK_LENGTH];
    char inputFileName[MAX_FILE_NAME_LENGTH];
    char outputFileName[MAX_FILE_NAME_LENGTH];

    printf("Enter watermark: ");
    fgets(watermark, MAX_WATERMARK_LENGTH, stdin);

    printf("Enter input file name (with path): ");
    fgets(inputFileName, MAX_FILE_NAME_LENGTH, stdin);
    inputFileName[strcspn(inputFileName, "\n")] = 0;

    printf("Enter output file name (with path): ");
    fgets(outputFileName, MAX_FILE_NAME_LENGTH, stdin);
    outputFileName[strcspn(outputFileName, "\n")] = 0;

    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    if (outputFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    addWatermark(inputFile, outputFile, watermark);

    printf("Watermark added successfully!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}