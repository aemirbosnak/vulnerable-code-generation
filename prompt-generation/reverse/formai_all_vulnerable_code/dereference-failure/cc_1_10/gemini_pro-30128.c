//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SUCCESS,
    FAILURE,
    INVALID_ARGUMENT,
    OUT_OF_MEMORY,
    IO_ERROR,
    UNEXPECTED_ERROR
} error_code;

static const char *error_messages[] = {
    "Success",
    "Failure",
    "Invalid argument",
    "Out of memory",
    "IO error",
    "Unexpected error"
};

#define HANDLE_ERROR(code)  do {                                          \
                                    if ((code) != SUCCESS) {                \
                                        fprintf(stderr, "%s\n", error_messages[(code)]); \
                                        exit((code));                        \
                                    }                                        \
                                } while(0)

static error_code function1(int a, int b, int c, int *result) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return INVALID_ARGUMENT;
    }
    *result = a * b * c;
    return SUCCESS;
}

static error_code function2(const char *filename, char **buffer) {
    FILE *file;
    size_t size;
    file = fopen(filename, "r");
    if (file == NULL) {
        return IO_ERROR;
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    *buffer = malloc(size + 1);
    if (*buffer == NULL) {
        fclose(file);
        return OUT_OF_MEMORY;
    }
    if (fread(*buffer, 1, size, file) != size) {
        fclose(file);
        free(*buffer);
        return IO_ERROR;
    }
    fclose(file);
    (*buffer)[size] = '\0';
    return SUCCESS;
}

int main(void) {
    int a, b, c, result;
    char *buffer;
    HANDLE_ERROR(function1(1, 2, 3, &result));
    printf("Result: %d\n", result);
    HANDLE_ERROR(function2("file.txt", &buffer));
    printf("Buffer: %s\n", buffer);
    free(buffer);
    return 0;
}