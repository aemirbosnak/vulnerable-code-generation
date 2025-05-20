//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum ErrorCodes {
    SUCCESS = 0,
    OUT_OF_MEMORY,
    INVALID_ARGUMENT,
    IO_ERROR,
    CUSTOM_ERROR
};

void handleError(enum ErrorCodes code) {
    switch (code) {
        case OUT_OF_MEMORY:
            printf("Out of memory!\n");
            break;
        case INVALID_ARGUMENT:
            printf("Invalid argument!\n");
            break;
        case IO_ERROR:
            printf("IO error!\n");
            break;
        case CUSTOM_ERROR:
            printf("Custom error!\n");
            break;
        default:
            printf("Unknown error code!\n");
            break;
    }
    exit(code);
}

int main() {
    int *ptr = NULL;
    int value = 42;

    // Allocate memory for the pointer
    ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        handleError(OUT_OF_MEMORY);
    }

    // Dereference the pointer and set the value
    *ptr = value;

    // Free the memory pointed by the pointer
    free(ptr);

    // Try to dereference the pointer again
    if (*ptr == value) {
        handleError(CUSTOM_ERROR);
    }

    return SUCCESS;
}