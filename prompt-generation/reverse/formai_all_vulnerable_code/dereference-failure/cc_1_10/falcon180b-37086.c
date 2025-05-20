//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputLine[MAX_LINE_LENGTH], outputLine[MAX_LINE_LENGTH];
    int lineNumber = 0;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(inputLine, MAX_LINE_LENGTH, inputFile)!= NULL) {
        lineNumber++;

        // Remove leading/trailing whitespace
        char *inputLineTrimmed = strtok(inputLine, " \t\n\r\f\v");
        if (inputLineTrimmed == NULL) {
            continue;
        }

        // Remove comments
        char *inputLineCleaned = strtok(NULL, " \t\n\r\f\v");
        if (inputLineCleaned == NULL) {
            continue;
        }

        snprintf(outputLine, MAX_LINE_LENGTH, "%d: %s", lineNumber, inputLineCleaned);
        fprintf(outputFile, "%s\n", outputLine);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}