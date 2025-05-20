//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling function
void handle_error(const char *error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(EXIT_FAILURE);
}

int main() {
    // Declare variables
    FILE *file;
    char *buffer;
    size_t buffer_size;
    ssize_t bytes_read;

    // Open file
    file = fopen("error_handling_example.txt", "r");
    if (file == NULL) {
        handle_error("Error opening file");
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    buffer_size = ftell(file);
    rewind(file);

    // Allocate memory for buffer
    buffer = malloc(buffer_size);
    if (buffer == NULL) {
        handle_error("Error allocating memory for buffer");
    }

    // Read file into buffer
    bytes_read = fread(buffer, 1, buffer_size, file);
    if (bytes_read != buffer_size) {
        handle_error("Error reading file into buffer");
    }

    // Close file
    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }

    // Process data in buffer
    // ...

    // Free memory allocated for buffer
    free(buffer);

    return EXIT_SUCCESS;
}