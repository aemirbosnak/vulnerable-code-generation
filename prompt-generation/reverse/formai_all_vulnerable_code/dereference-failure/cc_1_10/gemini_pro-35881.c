//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum Errors {
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION_FAILED,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_OPEN_FAILED,
    ERR_FILE_READ_FAILED,
    ERR_FILE_WRITE_FAILED,
    ERR_UNEXPECTED_ERROR
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            fprintf(stderr, "Invalid input\n");
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            fprintf(stderr, "Memory allocation failed\n");
            break;
        case ERR_FILE_NOT_FOUND:
            fprintf(stderr, "File not found\n");
            break;
        case ERR_FILE_OPEN_FAILED:
            fprintf(stderr, "File open failed\n");
            break;
        case ERR_FILE_READ_FAILED:
            fprintf(stderr, "File read failed\n");
            break;
        case ERR_FILE_WRITE_FAILED:
            fprintf(stderr, "File write failed\n");
            break;
        default:
            fprintf(stderr, "Unexpected error\n");
    }
    exit(error_code);
}

int main() {
    // Example of invalid input
    char *input = NULL;
    if (strcmp(input, "valid") != 0) {
        handle_error(ERR_INVALID_INPUT);
    }

    // Example of memory allocation failure
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        handle_error(ERR_MEMORY_ALLOCATION_FAILED);
    }

    // Example of file not found
    FILE *file = fopen("non-existent-file.txt", "r");
    if (file == NULL) {
        handle_error(ERR_FILE_NOT_FOUND);
    }

    // Example of file open failure
    file = fopen("invalid-file-permissions.txt", "w");
    if (file == NULL) {
        handle_error(ERR_FILE_OPEN_FAILED);
    }

    // Example of file read failure
    char buffer[100];
    if (fread(buffer, sizeof(buffer), 1, file) != 1) {
        handle_error(ERR_FILE_READ_FAILED);
    }

    // Example of file write failure
    if (fwrite(buffer, sizeof(buffer), 1, file) != 1) {
        handle_error(ERR_FILE_WRITE_FAILED);
    }

    // Close the file
    if (fclose(file) != 0) {
        handle_error(ERR_UNEXPECTED_ERROR);
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}