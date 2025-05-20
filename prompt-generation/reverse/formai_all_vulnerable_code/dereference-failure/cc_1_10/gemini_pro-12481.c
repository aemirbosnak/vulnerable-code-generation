//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error codes
enum errors {
    ERR_NONE = 0,
    ERR_INVALID_ARGS = 1,
    ERR_FILE_NOT_FOUND = 2,
    ERR_IO_ERROR = 3,
    ERR_MEMORY_ALLOCATION = 4,
    ERR_UNKNOWN = 5
};

// Error messages
const char *error_messages[] = {
    "No error",
    "Invalid arguments",
    "File not found",
    "IO error",
    "Memory allocation error",
    "Unknown error"
};

// Print error message and exit
void print_error(int error_code) {
    if (error_code < 0 || error_code >= ERR_UNKNOWN) {
        error_code = ERR_UNKNOWN;
    }
    fprintf(stderr, "%s\n", error_messages[error_code]);
    exit(error_code);
}

// Open file
FILE *open_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        print_error(ERR_FILE_NOT_FOUND);
    }
    return fp;
}

// Read file
char *read_file(const char *filename) {
    FILE *fp = open_file(filename);
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        print_error(ERR_MEMORY_ALLOCATION);
    }

    fread(buffer, file_size, 1, fp);
    buffer[file_size] = '\0';
    fclose(fp);

    return buffer;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        print_error(ERR_INVALID_ARGS);
    }

    char *buffer = read_file(argv[1]);
    printf("%s", buffer);
    free(buffer);

    return ERR_NONE;
}