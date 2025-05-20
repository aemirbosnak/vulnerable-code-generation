//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define our own custom error codes
enum errors {
    NO_ERROR = 0,
    INVALID_INPUT = 1,
    MEMORY_ALLOCATION_FAILED = 2,
    FILE_OPEN_FAILED = 3,
    FILE_READ_FAILED = 4,
    FILE_WRITE_FAILED = 5,
    OTHER_ERROR = 6
};

// Define our own custom error handling function
void handle_error(enum errors error) {
    switch (error) {
        case NO_ERROR:
            printf("No error occurred.\n");
            break;
        case INVALID_INPUT:
            printf("Invalid input was entered.\n");
            break;
        case MEMORY_ALLOCATION_FAILED:
            printf("Memory allocation failed.\n");
            break;
        case FILE_OPEN_FAILED:
            printf("File open failed.\n");
            break;
        case FILE_READ_FAILED:
            printf("File read failed.\n");
            break;
        case FILE_WRITE_FAILED:
            printf("File write failed.\n");
            break;
        case OTHER_ERROR:
            printf("An unknown error occurred.\n");
            break;
    }
}

// Main function
int main() {
    // Declare our variables
    int *ptr = NULL;
    FILE *fp = NULL;
    int value;

    // Try to allocate memory for our pointer
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        handle_error(MEMORY_ALLOCATION_FAILED);
        return EXIT_FAILURE;
    }

    // Try to open a file for reading
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        handle_error(FILE_OPEN_FAILED);
        return EXIT_FAILURE;
    }

    // Try to read a value from the file
    if (fscanf(fp, "%d", &value) != 1) {
        handle_error(FILE_READ_FAILED);
        return EXIT_FAILURE;
    }

    // Try to write a value to the file
    if (fprintf(fp, "%d", value) != 1) {
        handle_error(FILE_WRITE_FAILED);
        return EXIT_FAILURE;
    }

    // Close the file
    if (fclose(fp) != 0) {
        handle_error(FILE_WRITE_FAILED);
        return EXIT_FAILURE;
    }

    // Free the memory allocated for our pointer
    free(ptr);

    // Return success
    return EXIT_SUCCESS;
}