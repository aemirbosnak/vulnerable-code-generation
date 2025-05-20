//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256
#define BUFFER_SIZE 1024

// Function prototypes
void readFile(const char *filename);
void handleFileError(const char *filename, FILE *file);
void processLine(char *line);
void handleMemoryError(void *ptr);
void cleanup(FILE *file);

// Main program
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    readFile(argv[1]);
    return EXIT_SUCCESS;
}

// Reads the content of a file line by line
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    handleFileError(filename, file);

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        processLine(buffer);
    }

    cleanup(file);
}

// Handles file opening errors
void handleFileError(const char *filename, FILE *file) {
    if (!file) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Processes each line read from the file
void processLine(char *line) {
    // Simulate dynamic memory allocation for processing
    char *processedLine = malloc(MAX_LINE_LENGTH);
    handleMemoryError(processedLine);

    // Dummy processing: copying line and uppercasing it
    size_t len = strnlen(line, MAX_LINE_LENGTH - 1);
    for (size_t i = 0; i < len; i++) {
        processedLine[i] = (line[i] >= 'a' && line[i] <= 'z') ? line[i] - 32 : line[i];
    }
    processedLine[len] = '\0'; // Null-terminate the string

    // Output the processed line
    printf("Processed Line: %s", processedLine);
    free(processedLine); // Clean up allocated memory
}

// Handles memory allocation errors
void handleMemoryError(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Cleans up resources
void cleanup(FILE *file) {
    if (file) {
        fclose(file);
        printf("File closed successfully.\n");
    }
}