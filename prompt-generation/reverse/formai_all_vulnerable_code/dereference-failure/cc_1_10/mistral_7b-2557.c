//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

void readFile(FILE *file, char *buffer) {
    size_t bytesRead = fread(buffer, sizeof(char), MAX_LINE_SIZE, file);
    if (feof(file)) {
        printf("Error: Reached end of file while reading.\n");
        exit(EXIT_FAILURE);
    }
    if (ferror(file)) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
}

void writeFile(FILE *file, const char *buffer, size_t size) {
    size_t bytesWritten = fwrite(buffer, sizeof(char), size, file);
    if (ferror(file)) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
}

int isValidChar(char c) {
    return (isalnum(c) || isspace(c) || c == '\n');
}

void recoverData(char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isValidChar(input[i])) {
            output[j++] = input[i];
        }

        i++;
    }

    output[j] = '\0';
}

int main() {
    FILE *inputFile = fopen(INPUT_FILE, "r");
    FILE *outputFile = fopen(OUTPUT_FILE, "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char inputBuffer[MAX_LINE_SIZE];
    char outputBuffer[MAX_LINE_SIZE];

    while (!feof(inputFile)) {
        readFile(inputFile, inputBuffer);

        char *start = inputBuffer;
        char *end = inputBuffer + strlen(inputBuffer);

        recoverData(start, outputBuffer);

        fseek(inputFile, ftell(inputFile) - (sizeof(char) * (end - start)), SEEK_SET);

        writeFile(outputFile, outputBuffer, strlen(outputBuffer));
    }

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}