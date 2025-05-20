//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum error_codes {
    SUCCESS,
    ERR_INVALID_ARGUMENT,
    ERR_MEMORY_ALLOCATION_FAILED,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_OPEN_FAILED,
    ERR_FILE_READ_FAILED,
    ERR_FILE_WRITE_FAILED,
    ERR_FILE_CLOSE_FAILED
};

const char *error_messages[] = {
    "Success",
    "Invalid argument",
    "Memory allocation failed",
    "File not found",
    "File open failed",
    "File read failed",
    "File write failed",
    "File close failed"
};

#define CHECK_ERROR(expr, error_code) \
    do { \
        if ((expr) != SUCCESS) { \
            fprintf(stderr, "%s: %s\n", __func__, error_messages[error_code]); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)



int main(int argc, char **argv) {
    FILE *fp;
    char *buffer;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    CHECK_ERROR(fp != NULL, ERR_FILE_OPEN_FAILED);

    buffer = malloc(1024);
    CHECK_ERROR(buffer != NULL, ERR_MEMORY_ALLOCATION_FAILED);

    fread(buffer, 1024, 1, fp);
    CHECK_ERROR(ferror(fp) == 0, ERR_FILE_READ_FAILED);

    fclose(fp);
    CHECK_ERROR(ferror(fp) == 0, ERR_FILE_CLOSE_FAILED);

    printf("%s", buffer);
    free(buffer);

    return EXIT_SUCCESS;
}