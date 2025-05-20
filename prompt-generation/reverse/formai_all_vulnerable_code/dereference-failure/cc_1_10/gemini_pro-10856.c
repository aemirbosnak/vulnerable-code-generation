//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum {
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION_FAILED,
    ERR_FILE_OPERATION_FAILED,
    ERR_UNKNOWN
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            printf("Invalid input.\n");
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            printf("Memory allocation failed.\n");
            break;
        case ERR_FILE_OPERATION_FAILED:
            printf("File operation failed.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
    }
    exit(error_code);
}

// Function to read a file and return its contents
char *read_file(const char *filename) {
    FILE *fp;
    char *buffer;
    size_t file_size;

    // Open the file for reading in binary mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        handle_error(ERR_FILE_OPERATION_FAILED);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the buffer
    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        handle_error(ERR_MEMORY_ALLOCATION_FAILED);
    }

    // Read the file into the buffer
    if (fread(buffer, 1, file_size, fp) != file_size) {
        handle_error(ERR_FILE_OPERATION_FAILED);
    }

    // Close the file
    fclose(fp);

    // Terminate the buffer with a null character
    buffer[file_size] = '\0';

    return buffer;
}

int main() {
    char *file_contents;
    int num_lines;
    char *line;

    // Read the file into a buffer
    file_contents = read_file("input.txt");

    // Count the number of lines in the file
    num_lines = 0;
    line = strtok(file_contents, "\n");
    while (line != NULL) {
        num_lines++;
        line = strtok(NULL, "\n");
    }

    // Print the number of lines in the file
    printf("The file contains %d lines.\n", num_lines);

    // Free the memory allocated for the buffer
    free(file_contents);

    return 0;
}