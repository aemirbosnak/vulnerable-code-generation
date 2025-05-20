//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Define our own error codes
enum error_codes {
    ERR_SUCCESS = 0,
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION_FAILED = 2,
    ERR_FILE_OPEN_FAILED = 3,
    ERR_FILE_READ_FAILED = 4,
    ERR_FILE_WRITE_FAILED = 5,
    ERR_UNKNOWN = 99
};

// Define our own error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            fprintf(stderr, "Invalid input provided.\n");
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            fprintf(stderr, "Memory allocation failed.\n");
            break;
        case ERR_FILE_OPEN_FAILED:
            fprintf(stderr, "File open failed.\n");
            break;
        case ERR_FILE_READ_FAILED:
            fprintf(stderr, "File read failed.\n");
            break;
        case ERR_FILE_WRITE_FAILED:
            fprintf(stderr, "File write failed.\n");
            break;
        case ERR_UNKNOWN:
        default:
            fprintf(stderr, "Unknown error occurred.\n");
            break;
    }

    // Exit the program with the appropriate exit code
    exit(error_code);
}

int main(int argc, char *argv[]) {
    // Check if the required number of arguments were provided
    if (argc != 2) {
        handle_error(ERR_INVALID_INPUT);
    }

    // Allocate memory for the input string
    char *input_string = malloc(strlen(argv[1]) + 1);
    if (input_string == NULL) {
        handle_error(ERR_MEMORY_ALLOCATION_FAILED);
    }

    // Copy the input string into the allocated memory
    strcpy(input_string, argv[1]);

    // Open the file for writing
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        handle_error(ERR_FILE_OPEN_FAILED);
    }

    // Write the input string to the file
    if (fwrite(input_string, strlen(input_string), 1, fp) != 1) {
        handle_error(ERR_FILE_WRITE_FAILED);
    }

    // Close the file
    if (fclose(fp) != 0) {
        handle_error(ERR_FILE_OPEN_FAILED);
    }

    // Free the allocated memory
    free(input_string);

    // Exit the program with success
    exit(ERR_SUCCESS);
}