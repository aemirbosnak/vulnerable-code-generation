//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_NONE 0
#define ERROR_INVALID_ARGUMENT -1
#define ERROR_OUT_OF_MEMORY -2
#define ERROR_IO_ERROR -3
#define ERROR_UNKNOWN -4

typedef struct {
    int code;
    const char *message;
} error_t;

error_t *error_create(int code, const char *message) {
    error_t *error = malloc(sizeof(error_t));
    if (error == NULL) {
        return NULL;
    }
    error->code = code;
    error->message = message;
    return error;
}

void error_destroy(error_t *error) {
    free(error);
}

const char *error_message(error_t *error) {
    return error->message;
}

int error_code(error_t *error) {
    return error->code;
}

int main(int argc, char *argv[]) {
    error_t *error = NULL;

    if (argc != 2) {
        error = error_create(ERROR_INVALID_ARGUMENT, "Invalid number of arguments");
        goto cleanup;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error = error_create(ERROR_IO_ERROR, "Could not open file");
        goto cleanup;
    }

    char *buffer = malloc(1024);
    if (buffer == NULL) {
        error = error_create(ERROR_OUT_OF_MEMORY, "Could not allocate memory");
        goto cleanup;
    }

    size_t bytes_read = fread(buffer, 1, 1024, file);
    if (bytes_read < 0) {
        error = error_create(ERROR_IO_ERROR, "Could not read from file");
        goto cleanup;
    }

    printf("%s", buffer);

cleanup:
    if (error != NULL) {
        fprintf(stderr, "%s\n", error_message(error));
        error_destroy(error);
    }

    if (file != NULL) {
        fclose(file);
    }

    if (buffer != NULL) {
        free(buffer);
    }

    return error == NULL ? EXIT_SUCCESS : EXIT_FAILURE;
}