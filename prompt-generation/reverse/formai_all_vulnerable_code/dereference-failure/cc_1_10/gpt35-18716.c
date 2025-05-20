//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char *inputFilename, *outputFilename;
    char ch;
    long fileSize;

    // Ask user for input and output file names
    printf("Enter input file name: ");
    scanf("%ms", &inputFilename);
    printf("Enter output file name: ");
    scanf("%ms", &outputFilename);

    // Open input file
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file\n");
        exit(1);
    }

    // Determine file size
    fseek(inputFile, 0L, SEEK_END);
    fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for file content
    char *fileContent = (char *) malloc(sizeof(char) * fileSize);

    // Read file content into memory buffer
    if (fread(fileContent, sizeof(char), fileSize, inputFile) != fileSize) {
        printf("Error: Cannot read input file\n");
        exit(1);
    }

    // Open output file
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open output file\n");
        exit(1);
    }

    // Write file content to output file backwards
    for (int i = fileSize - 1; i >= 0; i--) {
        ch = fileContent[i];
        fwrite(&ch, sizeof(char), 1, outputFile);
    }

    // Free memory and close files
    free(fileContent);
    fclose(inputFile);
    fclose(outputFile);

    printf("File has been reversed and saved to %s\n", outputFilename);

    return 0;
}