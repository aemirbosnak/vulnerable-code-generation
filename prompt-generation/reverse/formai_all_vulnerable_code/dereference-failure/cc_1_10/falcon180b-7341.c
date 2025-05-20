//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to read a binary file and return its contents as a char array
char* readBinaryFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = malloc(fileSize + 1);
    fread(data, fileSize, 1, file);
    fclose(file);
    data[fileSize] = '\0';

    return data;
}

// Function to write a char array to a binary file
void writeBinaryFile(const char* filename, const char* data) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

// Function to parse a binary file and extract all text strings longer than a given length
void extractStrings(const char* data, int minLength, FILE* outputFile) {
    char* currentString = malloc(minLength + 1);
    char* start = data;

    while (true) {
        memset(currentString, 0, minLength + 1);
        strncat(currentString, start, minLength);

        if (isprint(currentString[0])) {
            fprintf(outputFile, "%.*s\n", minLength, currentString);
        }

        start += minLength;
        if (start >= data + strlen(data)) {
            break;
        }
    }

    free(currentString);
}

int main() {
    const char* inputFileName = "input.bin";
    const char* outputFileName = "output.txt";

    // Read input binary file
    char* inputData = readBinaryFile(inputFileName);

    // Extract all text strings longer than 10 characters
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open file '%s'\n", outputFileName);
        exit(1);
    }

    extractStrings(inputData, 10, outputFile);

    fclose(outputFile);

    // Write extracted strings to output binary file
    writeBinaryFile("extracted_strings.bin", inputData);

    free(inputData);
    return 0;
}