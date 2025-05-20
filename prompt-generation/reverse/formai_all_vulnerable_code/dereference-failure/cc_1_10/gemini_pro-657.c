//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SUCCESS,
    INVALID_ARGUMENT,
    OUT_OF_MEMORY,
    IO_ERROR,
    UNKNOWN_ERROR
} Error_code;

const char *error_messages[] = {
    "Success",
    "Invalid argument",
    "Out of memory",
    "IO error",
    "Unknown error"
};

Error_code check_argument(int argument) {
    if (argument < 0) {
        return INVALID_ARGUMENT;
    }
    return SUCCESS;
}

Error_code allocate_memory(void **ptr, size_t size) {
    *ptr = malloc(size);
    if (*ptr == NULL) {
        return OUT_OF_MEMORY;
    }
    return SUCCESS;
}

Error_code read_file(FILE *file, char *buffer, size_t size) {
    if (fread(buffer, size, 1, file) != 1) {
        return IO_ERROR;
    }
    return SUCCESS;
}

Error_code write_file(FILE *file, char *buffer, size_t size) {
    if (fwrite(buffer, size, 1, file) != 1) {
        return IO_ERROR;
    }
    return SUCCESS;
}

Error_code close_file(FILE *file) {
    if (fclose(file) != 0) {
        return IO_ERROR;
    }
    return SUCCESS;
}

void handle_error(Error_code error_code) {
    fprintf(stderr, "Error: %s\n", error_messages[error_code]);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int argument;
    char *buffer;
    FILE *file;

    // Check the argument
    if (argc != 2) {
        handle_error(INVALID_ARGUMENT);
    }
    argument = atoi(argv[1]);
    if (check_argument(argument) != SUCCESS) {
        handle_error(INVALID_ARGUMENT);
    }

    // Allocate memory
    if (allocate_memory((void **)&buffer, argument) != SUCCESS) {
        handle_error(OUT_OF_MEMORY);
    }

    // Read the file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        handle_error(IO_ERROR);
    }
    if (read_file(file, buffer, argument) != SUCCESS) {
        handle_error(IO_ERROR);
    }

    // Write the file
    file = fopen("output.txt", "w");
    if (file == NULL) {
        handle_error(IO_ERROR);
    }
    if (write_file(file, buffer, argument) != SUCCESS) {
        handle_error(IO_ERROR);
    }

    // Close the file
    if (close_file(file) != SUCCESS) {
        handle_error(IO_ERROR);
    }

    // Free memory
    free(buffer);

    return EXIT_SUCCESS;
}