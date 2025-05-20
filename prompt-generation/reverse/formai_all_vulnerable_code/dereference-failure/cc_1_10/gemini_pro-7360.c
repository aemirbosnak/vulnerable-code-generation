//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

enum error_code {
    SUCCESS = 0,
    ERR_ALLOC = 1,
    ERR_IO = 2,
    ERR_OTHER = 3
};

typedef struct {
    const char *message;
    enum error_code code;
} error;

error *create_error(const char *message, enum error_code code) {
    error *err = malloc(sizeof(*err));
    if (err == NULL) {
        return NULL;
    }

    err->message = message;
    err->code = code;
    return err;
}

void destroy_error(error *err) {
    free(err);
}

void handle_error(error *err) {
    fprintf(stderr, "Error: %s (code %d)\n", err->message, err->code);
    destroy_error(err);
}

int main(void) {
    error *err = NULL;

    // Allocate memory for a buffer
    char *buffer = malloc(1024);
    if (buffer == NULL) {
        err = create_error("Failed to allocate memory for buffer", ERR_ALLOC);
        goto error_handling;
    }

    // Read data from a file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        err = create_error("Failed to open file", ERR_IO);
        goto error_handling;
    }

    // Process data from the file
    // ...

    // Close the file
    if (fclose(file) != 0) {
        err = create_error("Failed to close file", ERR_IO);
        goto error_handling;
    }

    // Free the buffer
    free(buffer);

    // Exit with success
    return 0;

error_handling:
    handle_error(err);
    return EXIT_FAILURE;
}