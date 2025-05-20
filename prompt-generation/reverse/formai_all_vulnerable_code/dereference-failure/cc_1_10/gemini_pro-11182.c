//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Custom error codes
enum custom_errors {
    ERR_NO_MEMORY = 1,
    ERR_FILE_NOT_FOUND = 2,
    ERR_INVALID_ARGUMENT = 3
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_NO_MEMORY:
            fprintf(stderr, "Error: Out of memory.\n");
            break;
        case ERR_FILE_NOT_FOUND:
            fprintf(stderr, "Error: File not found.\n");
            break;
        case ERR_INVALID_ARGUMENT:
            fprintf(stderr, "Error: Invalid argument.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error.\n");
    }

    // Exit the program with the specified error code.
    exit(error_code);
}

// Main function
int main() {
    // Allocate memory for a buffer.
    char *buffer = malloc(1024);
    if (buffer == NULL) {
        handle_error(ERR_NO_MEMORY);
    }

    // Open a file.
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        handle_error(ERR_FILE_NOT_FOUND);
    }

    // Read data from the file into the buffer.
    size_t bytes_read = fread(buffer, 1, 1024, file);
    if (bytes_read == 0) {
        handle_error(ERR_INVALID_ARGUMENT);
    }

    // Close the file.
    fclose(file);

    // Free the memory allocated for the buffer.
    free(buffer);

    return 0;
}