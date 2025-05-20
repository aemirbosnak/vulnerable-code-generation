//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void safeFileOpen(const char *filename, FILE **file);
void readFileContents(FILE *file);
void handleError(const char *message);

// Custom error handler
void handleError(const char *message) {
    fprintf(stderr, "Error: %s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

// Safely open a file and handle errors
void safeFileOpen(const char *filename, FILE **file) {
    *file = fopen(filename, "r");
    if (*file == NULL) {
        handleError("Failed to open file");
    }
}

// Read contents of the file and handle errors
void readFileContents(FILE *file) {
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Print line to standard output
    }

    if (ferror(file)) {
        handleError("Error reading file");
    }
}

// Function to demonstrate safe dynamic memory allocation
char *safeAllocate(size_t size) {
    char *ptr = malloc(size);
    if (ptr == NULL) {
        handleError("Memory allocation failed");
    }
    return ptr;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = NULL;
    safeFileOpen(argv[1], &file); // Open file safely

    readFileContents(file); // Read contents from the file

    if (fclose(file) != 0) {
        handleError("Failed to close file");
    }

    // Demonstrating dynamic memory use
    size_t size = 50;
    char *dynamicString = safeAllocate(size); // Allocate memory safely

    snprintf(dynamicString, size, "This is a dynamically allocated string.\n");
    printf("%s", dynamicString); // Print the dynamically allocated string

    free(dynamicString); // Free the allocated memory

    return EXIT_SUCCESS;
}