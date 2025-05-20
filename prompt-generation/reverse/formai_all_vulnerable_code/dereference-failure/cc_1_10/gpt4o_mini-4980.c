//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER 256

// Function prototypes
void read_file(const char *filename);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the specified file
    read_file(argv[1]);

    return 0;
}

// Function to read from a file and handle errors
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Error opening file");
    }

    char buffer[MAX_BUFFER];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Trim newline character for clean output
        buffer[strcspn(buffer, "\n")] = 0;
        printf("Read line: %s\n", buffer);
    }

    if (ferror(file)) {
        handle_error("Error reading from file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }
}

// Centralized error handling function
void handle_error(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}