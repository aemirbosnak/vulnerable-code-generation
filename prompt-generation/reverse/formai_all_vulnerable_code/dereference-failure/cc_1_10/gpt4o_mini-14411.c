//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

// Function to handle errors
void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to allocate memory and check for errors
void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        handleError("Memory allocation failed");
    }
    return ptr;
}

// Function to read a line of input safely
char* safeGetLine() {
    char *buffer = safeMalloc(MAX_INPUT);
    if (fgets(buffer, MAX_INPUT, stdin) == NULL) {
        free(buffer);
        handleError("Failed to read input");
    }
    // Remove the newline character if it's there
    buffer[strcspn(buffer, "\n")] = 0; 
    return buffer;
}

// Function to open a file safely
FILE* safeFopen(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        handleError("File opening failed");
    }
    return file;
}

// Function to perform file operations and handle errors
void performFileOperations(const char *filename) {
    // Open file for writing
    FILE *file = safeFopen(filename, "w");
    
    // Get user input to write to the file
    printf("Enter text to write to the file (press Ctrl+D to finish):\n");
    char *line;
    while (1) {
        line = safeGetLine();
        if (strlen(line) == 0) {
            free(line);
            break; // Exit on empty line
        }
        fprintf(file, "%s\n", line);
        free(line);
    }
    
    if (fclose(file) != 0) {
        handleError("Failed to close the file");
    }
}

// Function to read a file and print its contents
void readFile(const char *filename) {
    FILE *file = safeFopen(filename, "r");
    char buffer[MAX_INPUT];
    
    printf("\nContents of %s:\n", filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (fclose(file) != 0) {
        handleError("Failed to close the file");
    }
}

int main() {
    const char *filename = "output.txt";

    // Perform file operations (write to file)
    performFileOperations(filename);

    // Read from the file and display its contents
    readFile(filename);

    return 0;
}