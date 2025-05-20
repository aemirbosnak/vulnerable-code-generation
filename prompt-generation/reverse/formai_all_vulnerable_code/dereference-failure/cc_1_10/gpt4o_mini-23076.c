//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

FILE *openFile(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        handleError("Error opening file");
    }
    return file;
}

void closeFile(FILE *file) {
    if (fclose(file) != 0) {
        handleError("Error closing file");
    }
}

char *readLine(FILE *file) {
    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        handleError("Memory allocation failed");
    }
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
        free(buffer);
        if (feof(file)) {
            return NULL; // End of file
        } else {
            handleError("Error reading line from file");
        }
    }
    return buffer;
}

void writeLine(FILE *file, const char *line) {
    if (fputs(line, file) == EOF) {
        handleError("Error writing line to file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];

    FILE *inputFile = openFile(inputFilename, "r");
    FILE *outputFile = openFile(outputFilename, "w");

    char *line = NULL;
    while ((line = readLine(inputFile)) != NULL) {
        writeLine(outputFile, line);
        free(line);
    }

    closeFile(inputFile);
    closeFile(outputFile);

    printf("File processing completed successfully!\n");
    return EXIT_SUCCESS;
}