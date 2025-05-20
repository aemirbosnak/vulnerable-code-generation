//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Custom error type
typedef enum {
    FILE_ERROR,
    MEM_ERROR,
    INPUT_ERROR,
    OUTPUT_ERROR
} ErrorType;

// Error struct to store error information
typedef struct {
    ErrorType type;
    char* message;
} Error;

// Function for handling errors
void handleError(Error* err) {
    switch (err->type) {
        case FILE_ERROR:
            printf("Error: Failed to open file - %s\n", err->message);
            break;
        case MEM_ERROR:
            printf("Error: Failed to allocate memory - %s\n", err->message);
            break;
        case INPUT_ERROR:
            printf("Error: Invalid input - %s\n", err->message);
            break;
        case OUTPUT_ERROR:
            printf("Error: Failed to write to file - %s\n", err->message);
            break;
    }
    exit(1);
}

// Function that might throw an error
void throwError(ErrorType type, char* message) {
    Error* err = (Error*) malloc(sizeof(Error));
    err->type = type;
    err->message = message;
    handleError(err);
}

int main() {
    // Example usage
    FILE* file = fopen("nonexistentfile.txt", "r");
    if (!file) {
        throwError(FILE_ERROR, "File does not exist.");
    }
    
    return 0;
}