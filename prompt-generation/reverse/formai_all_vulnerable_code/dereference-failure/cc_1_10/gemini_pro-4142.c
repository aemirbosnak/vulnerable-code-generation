//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Custom error codes
enum ERRORS {
    ERR_FILE_OPEN,
    ERR_FILE_READ,
    ERR_FILE_WRITE,
    ERR_MEMORY_ALLOC,
    ERR_INVALID_ARG,
};

// Error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_FILE_OPEN:
            perror("Error opening file");
            break;
        case ERR_FILE_READ:
            perror("Error reading file");
            break;
        case ERR_FILE_WRITE:
            perror("Error writing file");
            break;
        case ERR_MEMORY_ALLOC:
            perror("Error allocating memory");
            break;
        case ERR_INVALID_ARG:
            fprintf(stderr, "Invalid argument\n");
            break;
        default:
            fprintf(stderr, "Unknown error\n");
    }

    // Clean up resources and exit program
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc < 2) {
        handle_error(ERR_INVALID_ARG);
    }

    // Open file for reading
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        handle_error(ERR_FILE_OPEN);
    }

    // Read from file
    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    if (bytes_read == 0) {
        handle_error(ERR_FILE_READ);
    }

    // Write to file
    FILE *fp_out = fopen("output.txt", "w");
    if (fp_out == NULL) {
        handle_error(ERR_FILE_OPEN);
    }

    size_t bytes_written = fwrite(buffer, 1, bytes_read, fp_out);
    if (bytes_written != bytes_read) {
        handle_error(ERR_FILE_WRITE);
    }

    // Close files
    fclose(fp);
    fclose(fp_out);

    // Allocate memory
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        handle_error(ERR_MEMORY_ALLOC);
    }

    // Free memory
    free(ptr);

    return EXIT_SUCCESS;
}