//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

enum {
    ERROR_NONE = 0,
    ERROR_INVALID_ARGUMENT = 1,
    ERROR_OUT_OF_MEMORY = 2,
    ERROR_FILE_NOT_FOUND = 3,
    ERROR_FILE_ACCESS_DENIED = 4,
    ERROR_IO_ERROR = 5,
    ERROR_INTERNAL_ERROR = 6,
};

typedef struct {
    int code;
    const char *message;
} error_t;

static const error_t errors[] = {
    { ERROR_NONE, "No error." },
    { ERROR_INVALID_ARGUMENT, "Invalid argument." },
    { ERROR_OUT_OF_MEMORY, "Out of memory." },
    { ERROR_FILE_NOT_FOUND, "File not found." },
    { ERROR_FILE_ACCESS_DENIED, "File access denied." },
    { ERROR_IO_ERROR, "IO error." },
    { ERROR_INTERNAL_ERROR, "Internal error." },
};

void handle_error(error_t error)
{
    if (error.code == ERROR_NONE) {
        return;
    }

    fprintf(stderr, "Error: %s\n", error.message);

    if (error.code == ERROR_OUT_OF_MEMORY) {
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        handle_error((error_t) { ERROR_INVALID_ARGUMENT, "Missing argument." });
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        handle_error((error_t) { ERROR_FILE_NOT_FOUND, "File not found." });
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    if (ferror(file)) {
        handle_error((error_t) { ERROR_IO_ERROR, "IO error." });
        return EXIT_FAILURE;
    }

    fclose(file);

    return EXIT_SUCCESS;
}