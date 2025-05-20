//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum ErrorCodes {
    ERR_SUCCESS = 0,
    ERR_INVALID_INPUT,
    ERR_MEMORY_ALLOCATION_FAILED,
    ERR_FILE_OPEN_FAILED,
    ERR_FILE_WRITE_FAILED,
    ERR_FILE_READ_FAILED,
    ERR_INVALID_FILE_FORMAT
};

// Custom error messages
const char *errorMessages[] = {
    "Success",
    "Invalid input",
    "Memory allocation failed",
    "File open failed",
    "File write failed",
    "File read failed",
    "Invalid file format"
};

// Custom error handling function
void handleError(int errorCode) {
    if (errorCode != ERR_SUCCESS) {
        fprintf(stderr, "Error: %s\n", errorMessages[errorCode]);
        exit(errorCode);
    }
}

int main() {
    // Custom error handling example
    int *ptr = NULL;
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        handleError(ERR_MEMORY_ALLOCATION_FAILED);
    }

    // Custom error handling example
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        handleError(ERR_FILE_OPEN_FAILED);
    }

    // Custom error handling example
    if (fwrite("Hello world", 1, 11, file) != 11) {
        handleError(ERR_FILE_WRITE_FAILED);
    }

    // Custom error handling example
    fclose(file);
    file = fopen("data.txt", "r");
    if (file == NULL) {
        handleError(ERR_FILE_OPEN_FAILED);
    }

    char buffer[100];
    if (fread(buffer, 1, 100, file) != 100) {
        handleError(ERR_FILE_READ_FAILED);
    }

    // Custom error handling example
    if (strcmp(buffer, "Hello world") != 0) {
        handleError(ERR_INVALID_FILE_FORMAT);
    }

    fclose(file);
    free(ptr);

    return ERR_SUCCESS;
}