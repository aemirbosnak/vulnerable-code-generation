//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_LINE_LENGTH 1024

void handleError(const char *errorMsg) {
    perror(errorMsg);
    exit(EXIT_FAILURE);
}

FILE *openFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Failed to open file");
    }
    return file;
}

char *readLine(FILE *file) {
    char *line = (char *)malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        handleError("Memory allocation failed");
    }

    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL; // End of file or error
    }
	
    // Strip trailing newline
    line[strcspn(line, "\n")] = 0; 
    return line;
}

void processLine(const char *line, int lineNumber) {
    printf("Line %d: %s\n", lineNumber, line);
}

void readFileLines(const char *filename) {
    FILE *file = openFile(filename);
    char *line;
    int lineNumber = 0;

    while ((line = readLine(file)) != NULL) {
        lineNumber++;
        processLine(line, lineNumber);
        free(line);
    }

    if (ferror(file)) {
        handleError("Error reading file");
    }

    fclose(file);
}

void generateFile(const char *filename, int numberOfLines) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        handleError("Failed to create file");
    }

    for (int i = 1; i <= numberOfLines; i++) {
        fprintf(file, "This is line number %d\n", i);
    }

    if (ferror(file)) {
        handleError("Error writing to file");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <output_filename> <number_of_lines>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *outputFilename = argv[1];
    int numberOfLines = atoi(argv[2]);
    if (numberOfLines <= 0) {
        fprintf(stderr, "Number of lines must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Generate a file with example lines
    generateFile(outputFilename, numberOfLines);

    // Read and process the file
    readFileLines(outputFilename);

    return EXIT_SUCCESS;
}