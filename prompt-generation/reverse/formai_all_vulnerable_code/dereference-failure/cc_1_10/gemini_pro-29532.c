//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum {
    ERR_INVALID_ARGUMENT = 1,
    ERR_OUT_OF_MEMORY = 2,
    ERR_FILE_NOT_FOUND = 3,
    ERR_IO_ERROR = 4,
    ERR_UNKNOWN = 5
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_ARGUMENT:
            fprintf(stderr, "Invalid argument.\n");
            break;
        case ERR_OUT_OF_MEMORY:
            fprintf(stderr, "Out of memory.\n");
            break;
        case ERR_FILE_NOT_FOUND:
            fprintf(stderr, "File not found.\n");
            break;
        case ERR_IO_ERROR:
            fprintf(stderr, "I/O error.\n");
            break;
        case ERR_UNKNOWN:
        default:
            fprintf(stderr, "Unknown error.\n");
            break;
    }

    exit(error_code);
}

// Function that may generate errors
int do_something(int arg1, char *arg2) {
    // Check for invalid arguments
    if (arg1 < 0 || arg2 == NULL) {
        handle_error(ERR_INVALID_ARGUMENT);
    }

    // Allocate memory
    char *buffer = malloc(1024);
    if (buffer == NULL) {
        handle_error(ERR_OUT_OF_MEMORY);
    }

    // Open a file
    FILE *file = fopen(arg2, "r");
    if (file == NULL) {
        handle_error(ERR_FILE_NOT_FOUND);
    }

    // Read from the file
    size_t bytes_read = fread(buffer, 1, 1024, file);
    if (bytes_read < 1024) {
        handle_error(ERR_IO_ERROR);
    }

    // Close the file
    fclose(file);

    // Free the memory
    free(buffer);

    return 0;
}

int main(int argc, char **argv) {
    // Check for valid arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s arg1 arg2\n", argv[0]);
        exit(ERR_INVALID_ARGUMENT);
    }

    // Parse arguments
    int arg1 = atoi(argv[1]);
    char *arg2 = argv[2];

    // Call function that may generate errors
    int error_code = do_something(arg1, arg2);

    // Handle error
    if (error_code != 0) {
        handle_error(error_code);
    }

    return 0;
}