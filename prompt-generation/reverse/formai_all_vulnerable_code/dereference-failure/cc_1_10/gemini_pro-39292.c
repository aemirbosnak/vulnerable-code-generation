//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum Errors {
    ERR_SUCCESS = 0,
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION_FAILURE = 2,
    ERR_FILE_OPEN_FAILURE = 3,
    ERR_FILE_WRITE_FAILURE = 4,
    ERR_FILE_READ_FAILURE = 5,
    ERR_FILE_CLOSE_FAILURE = 6,
    ERR_UNKNOWN = 99
};

// Custom error messages
const char *ErrorMessages[] = {
    "Success",
    "Invalid input",
    "Memory allocation failure",
    "File open failure",
    "File write failure",
    "File read failure",
    "File close failure",
    "Unknown error"
};

// Function to print an error message and exit the program
void PrintErrorMessageAndExit(int ErrorCode) {
    fprintf(stderr, "%s: %s\n", ErrorMessages[ErrorCode], strerror(ErrorCode));
    exit(ErrorCode);
}

// Function to handle file open errors
int HandleFileOpenError(FILE *file, const char *filename) {
    if (file == NULL) {
        PrintErrorMessageAndExit(ERR_FILE_OPEN_FAILURE);
    }

    return ERR_SUCCESS;
}

// Function to handle file write errors
int HandleFileWriteError(FILE *file) {
    if (ferror(file)) {
        PrintErrorMessageAndExit(ERR_FILE_WRITE_FAILURE);
    }

    return ERR_SUCCESS;
}

// Function to handle file read errors
int HandleFileReadError(FILE *file) {
    if (ferror(file)) {
        PrintErrorMessageAndExit(ERR_FILE_READ_FAILURE);
    }

    return ERR_SUCCESS;
}

// Function to handle file close errors
int HandleFileCloseError(FILE *file) {
    if (fclose(file) != 0) {
        PrintErrorMessageAndExit(ERR_FILE_CLOSE_FAILURE);
    }

    return ERR_SUCCESS;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for invalid input
    if (argc != 2) {
        PrintErrorMessageAndExit(ERR_INVALID_INPUT);
    }

    // Open the file
    FILE *file = fopen(argv[1], "w");
    int FileOpenError = HandleFileOpenError(file, argv[1]);
    if (FileOpenError != ERR_SUCCESS) {
        return FileOpenError;
    }

    // Write to the file
    fprintf(file, "Hello, world!\n");
    int FileWriteError = HandleFileWriteError(file);
    if (FileWriteError != ERR_SUCCESS) {
        fclose(file);
        return FileWriteError;
    }

    // Close the file
    int FileCloseError = HandleFileCloseError(file);
    if (FileCloseError != ERR_SUCCESS) {
        return FileCloseError;
    }

    return ERR_SUCCESS;
}