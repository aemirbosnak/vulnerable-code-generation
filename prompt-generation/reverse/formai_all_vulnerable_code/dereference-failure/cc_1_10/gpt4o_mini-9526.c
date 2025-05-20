//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 256
#define FILE_BUFFER_SIZE 512

void handleError(const char *message, int errorCode) {
    fprintf(stderr, "Error: %s (Code: %d)\n", message, errorCode);
    exit(errorCode);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Failed to open file", 1);
    }

    char buffer[FILE_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        handleError("Error reading from file", 2);
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file", 3);
    }
}

void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        handleError("Failed to open file for writing", 4);
    }

    if (fputs(content, file) == EOF) {
        handleError("Error writing to file", 5);
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file", 6);
    }
}

char *getInputString() {
    char *input = (char *)malloc(MAX_STRING_SIZE);
    if (input == NULL) {
        handleError("Memory allocation failed", 7);
    }

    printf("Enter a string (max %d characters): ", MAX_STRING_SIZE - 1);
    if (fgets(input, MAX_STRING_SIZE, stdin) == NULL) {
        handleError("Error reading input", 8);
    }

    // Remove trailing newline character if any
    input[strcspn(input, "\n")] = 0;

    return input;
}

void appendToFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        handleError("Failed to open file for appending", 9);
    }

    if (fputs(content, file) == EOF) {
        handleError("Error appending to file", 10);
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file", 11);
    }
}

int main() {
    const char *filename = "output.txt";

    // Write initial content to file
    const char *initialContent = "This is the initial content of the file.\n";
    writeFile(filename, initialContent);
    printf("Initial content written to %s\n", filename);

    // Get user input
    char *userInput = getInputString();

    // Append user input to file
    appendToFile(filename, userInput);
    printf("User input appended to %s\n", filename);

    // Read and display the contents of the file
    printf("Contents of the file:\n");
    readFile(filename);

    // Clean up
    free(userInput);

    return 0;
}