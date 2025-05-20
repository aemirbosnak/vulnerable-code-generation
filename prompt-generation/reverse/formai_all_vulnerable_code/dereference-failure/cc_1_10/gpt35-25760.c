//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    char inputChar, outputChar, prevChar;
    int indentLevel = 0;

    // Read in the input file
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.html", "r");
    outputFile = fopen("output.html", "w");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Loop through each character in the file and beautify it
    while ((inputChar = fgetc(inputFile)) != EOF) {
        // Remove extra whitespaces before current tag
        if (inputChar == '<' && prevChar == ' ') {
            fputc(prevChar, outputFile);
            while((prevChar = fgetc(inputFile)) == ' ');
            fputc(prevChar, outputFile);
            inputChar = fgetc(inputFile);
        }

        // Add newline before the current tag
        if (inputChar == '<') {
            fputc('\n', outputFile);
            for (int i = 0; i < indentLevel; i++) {
                fputc('\t', outputFile);
            }
            indentLevel++;
        }

        // Add newline after the current tag
        if (inputChar == '>') {
            fputc(outputChar, outputFile);
            fputc('\n', outputFile);
            indentLevel--;
            for (int i = 0; i < indentLevel; i++) {
                fputc('\t', outputFile);
            }
        }

        // Add character to output file
        outputChar = inputChar;
        fputc(outputChar, outputFile);
        prevChar = inputChar;
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Beautification complete.\n");

    return 0;
}