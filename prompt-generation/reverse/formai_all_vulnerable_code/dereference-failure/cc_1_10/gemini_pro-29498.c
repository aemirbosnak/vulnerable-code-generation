//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ERROR_SUCCESS 0
#define ERROR_INVALID_ARGUMENT -1
#define ERROR_OUT_OF_MEMORY -2
#define ERROR_FILE_NOT_FOUND -3
#define ERROR_IO_ERROR -4

typedef struct {
    int code;
    const char *message;
} Error;

static const Error errors[] = {
    {ERROR_SUCCESS, "Success"},
    {ERROR_INVALID_ARGUMENT, "Invalid argument"},
    {ERROR_OUT_OF_MEMORY, "Out of memory"},
    {ERROR_FILE_NOT_FOUND, "File not found"},
    {ERROR_IO_ERROR, "I/O error"},
};

static const char *get_error_message(int code) {
    for (size_t i = 0; i < sizeof(errors) / sizeof(errors[0]); i++) {
        if (errors[i].code == code) {
            return errors[i].message;
        }
    }
    return "Unknown error";
}

int main(int argc, char **argv) {
    // Check for the correct number of arguments.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return ERROR_INVALID_ARGUMENT;
    }

    // Open the file.
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s\n", get_error_message(ERROR_FILE_NOT_FOUND));
        return ERROR_FILE_NOT_FOUND;
    }

    // Read the file contents.
    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    if (bytes_read == 0) {
        fprintf(stderr, "Error: %s\n", get_error_message(ERROR_IO_ERROR));
        return ERROR_IO_ERROR;
    }

    // Close the file.
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error: %s\n", get_error_message(ERROR_IO_ERROR));
        return ERROR_IO_ERROR;
    }

    // Print the file contents.
    printf("%s", buffer);

    return ERROR_SUCCESS;
}