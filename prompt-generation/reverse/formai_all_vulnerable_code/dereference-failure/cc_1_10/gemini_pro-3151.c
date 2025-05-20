//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the error codes
#define ERR_INVALID_ARGUMENT 1
#define ERR_FILE_NOT_FOUND 2
#define ERR_MEMORY_ALLOCATION_FAILED 3
#define ERR_IO_ERROR 4

// Define the error messages
const char *error_messages[] = {
    "Invalid argument",
    "File not found",
    "Memory allocation failed",
    "IO error"
};

// Define the error handling function
void handle_error(int error_code) {
    // Print the error message
    fprintf(stderr, "%s\n", error_messages[error_code - 1]);

    // Exit the program with the error code
    exit(error_code);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        handle_error(ERR_INVALID_ARGUMENT);
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        handle_error(ERR_FILE_NOT_FOUND);
    }

    // Read the file contents into a buffer
    char *buffer;
    size_t buffer_size = 1024;
    buffer = malloc(buffer_size);

    // Check if the memory allocation was successful
    if (buffer == NULL) {
        handle_error(ERR_MEMORY_ALLOCATION_FAILED);
    }

    // Read the file contents
    size_t bytes_read = fread(buffer, 1, buffer_size, file);

    // Check if there was an IO error
    if (bytes_read < 0) {
        handle_error(ERR_IO_ERROR);
    }

    // Close the file
    fclose(file);

    // Print the file contents
    printf("%s", buffer);

    // Free the buffer
    free(buffer);

    return 0;
}