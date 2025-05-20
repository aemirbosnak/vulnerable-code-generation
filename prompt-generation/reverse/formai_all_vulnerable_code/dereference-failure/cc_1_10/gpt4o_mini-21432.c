//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

// Function prototypes
void handleError(const char *message);
void readFileContents(const char *filename);
void processFileLine(const char *line);
void demoErrorHandling(int value);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    readFileContents(argv[1]);

    // Demonstrating error handling
    demoErrorHandling(5);
    demoErrorHandling(0); // This will cause an error

    return EXIT_SUCCESS;
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s: %s\n", message, strerror(errno));
    // You might perform additional error logging or cleanup here
    exit(EXIT_FAILURE);
}

void readFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Failed to open the file");
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        processFileLine(buffer);
    }

    if (ferror(file)) {
        fclose(file);
        handleError("Error reading the file");
    }

    fclose(file);
}

void processFileLine(const char *line) {
    // Simulate processing of the line
    printf("Processing line: %s", line);
}

void demoErrorHandling(int value) {
    if (value < 1) {
        handleError("Value must be greater than 0");
    }

    printf("Processed value: %d\n", value);
    // Additional logic can be added here
}