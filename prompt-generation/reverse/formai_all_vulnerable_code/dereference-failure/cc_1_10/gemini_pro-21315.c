//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Custom error codes
enum errors {
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION,
    ERR_FILE_OPERATION,
    ERR_NETWORK_ERROR
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            fprintf(stderr, "Invalid input. Please try again.\n");
            break;
        case ERR_MEMORY_ALLOCATION:
            fprintf(stderr, "Memory allocation failed. Please try again.\n");
            exit(EXIT_FAILURE);
        case ERR_FILE_OPERATION:
            fprintf(stderr, "File operation failed. Please check file permissions.\n");
            exit(EXIT_FAILURE);
        case ERR_NETWORK_ERROR:
            fprintf(stderr, "Network error. Please check your internet connection.\n");
            exit(EXIT_FAILURE);
        default:
            fprintf(stderr, "Unknown error occurred. Please try again.\n");
            exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Declare variables
    int *ptr;
    FILE *fp;

    // Allocate memory
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        handle_error(ERR_MEMORY_ALLOCATION);
    }

    // Open a file
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        handle_error(ERR_FILE_OPERATION);
    }

    // Use the allocated memory and the file
    *ptr = 100;
    fprintf(fp, "%d\n", *ptr);

    // Free memory and close file
    free(ptr);
    fclose(fp);

    return 0;
}