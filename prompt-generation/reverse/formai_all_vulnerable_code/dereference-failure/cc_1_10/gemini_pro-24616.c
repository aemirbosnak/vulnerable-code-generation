//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Custom error type
typedef enum {
    ERR_NONE,
    ERR_IO,
    ERR_MEMORY,
    ERR_OTHER
} ErrorType;

// Custom error handling function
void handleError(ErrorType errorType) {
    switch (errorType) {
    case ERR_NONE:
        printf("No error occurred.\n");
        break;
    case ERR_IO:
        printf("An I/O error occurred: %s\n", strerror(errno));
        break;
    case ERR_MEMORY:
        printf("A memory allocation error occurred.\n");
        break;
    case ERR_OTHER:
        printf("An unknown error occurred.\n");
        break;
    }
}

int main() {
    // Allocate memory
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        handleError(ERR_MEMORY);
        return EXIT_FAILURE;
    }

    // Open file
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        handleError(ERR_IO);
        free(ptr);
        return EXIT_FAILURE;
    }

    // Read from file
    int value;
    if (fscanf(file, "%d", &value) != 1) {
        handleError(ERR_IO);
        fclose(file);
        free(ptr);
        return EXIT_FAILURE;
    }

    // Close file
    if (fclose(file) != 0) {
        handleError(ERR_IO);
        free(ptr);
        return EXIT_FAILURE;
    }

    // Free memory
    free(ptr);

    return EXIT_SUCCESS;
}