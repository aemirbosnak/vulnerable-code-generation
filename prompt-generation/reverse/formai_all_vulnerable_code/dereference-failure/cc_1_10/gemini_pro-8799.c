//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ERR_SUCCESS = 0,
    ERR_INVALID_ARGUMENT = 1,
    ERR_OUT_OF_MEMORY = 2,
    ERR_FILE_NOT_FOUND = 3,
} ErrorCode;

const char *error_messages[] = {
    "Success",
    "Invalid argument",
    "Out of memory",
    "File not found",
};

ErrorCode open_file(const char *filename, FILE **fp) {
    *fp = fopen(filename, "r");
    if (*fp == NULL) {
        return ERR_FILE_NOT_FOUND;
    }
    return ERR_SUCCESS;
}

ErrorCode read_file(FILE *fp, char **buffer, size_t *size) {
    if (fseek(fp, 0, SEEK_END) != 0) {
        return ERR_INVALID_ARGUMENT;
    }
    *size = ftell(fp);
    if (*size == -1) {
        return ERR_INVALID_ARGUMENT;
    }
    *buffer = malloc(*size);
    if (*buffer == NULL) {
        return ERR_OUT_OF_MEMORY;
    }
    if (fseek(fp, 0, SEEK_SET) != 0) {
        return ERR_INVALID_ARGUMENT;
    }
    if (fread(*buffer, *size, 1, fp) != 1) {
        return ERR_INVALID_ARGUMENT;
    }
    return ERR_SUCCESS;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    ErrorCode error = open_file(argv[1], &fp);
    if (error != ERR_SUCCESS) {
        fprintf(stderr, "Error opening file: %s\n", error_messages[error]);
        return 1;
    }

    char *buffer;
    size_t size;
    error = read_file(fp, &buffer, &size);
    if (error != ERR_SUCCESS) {
        fprintf(stderr, "Error reading file: %s\n", error_messages[error]);
        return 1;
    }

    printf("%s", buffer);
    free(buffer);
    fclose(fp);
    return 0;
}