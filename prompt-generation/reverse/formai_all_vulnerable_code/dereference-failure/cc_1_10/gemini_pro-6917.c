//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SUCCESS,
    FAILURE,
    NULL_POINTER,
    INVALID_ARGUMENT,
    OUT_OF_MEMORY,
    IO_ERROR,
    OTHER_ERROR
} ErrorCode;

ErrorCode OpenFile(FILE **file, const char *filename, const char *mode) {
    if (file == NULL) {
        return NULL_POINTER;
    }
    if (filename == NULL) {
        return INVALID_ARGUMENT;
    }
    if (mode == NULL) {
        return INVALID_ARGUMENT;
    }
    *file = fopen(filename, mode);
    if (*file == NULL) {
        return IO_ERROR;
    }
    return SUCCESS;
}

ErrorCode ReadFile(FILE *file, char **buffer, size_t *size) {
    if (file == NULL) {
        return NULL_POINTER;
    }
    if (buffer == NULL) {
        return INVALID_ARGUMENT;
    }
    if (size == NULL) {
        return INVALID_ARGUMENT;
    }
    fseek(file, 0, SEEK_END);
    long int length = ftell(file);
    if (length < 0) {
        return IO_ERROR;
    }
    *size = length;
    *buffer = malloc(length + 1);
    if (*buffer == NULL) {
        return OUT_OF_MEMORY;
    }
    fseek(file, 0, SEEK_SET);
    if (fread(*buffer, 1, length, file) != length) {
        free(*buffer);
        return IO_ERROR;
    }
    (*buffer)[length] = '\0';
    return SUCCESS;
}

ErrorCode WriteFile(FILE *file, const char *buffer, size_t size) {
    if (file == NULL) {
        return NULL_POINTER;
    }
    if (buffer == NULL) {
        return INVALID_ARGUMENT;
    }
    if (fwrite(buffer, 1, size, file) != size) {
        return IO_ERROR;
    }
    return SUCCESS;
}

ErrorCode CloseFile(FILE *file) {
    if (file == NULL) {
        return NULL_POINTER;
    }
    if (fclose(file) != 0) {
        return IO_ERROR;
    }
    return SUCCESS;
}

int main() {
    ErrorCode error;

    FILE *file;
    error = OpenFile(&file, "test.txt", "r");
    if (error != SUCCESS) {
        switch (error) {
            case NULL_POINTER:
                printf("Error: Null pointer passed to OpenFile().\n");
                return EXIT_FAILURE;
            case INVALID_ARGUMENT:
                printf("Error: Invalid argument passed to OpenFile().\n");
                return EXIT_FAILURE;
            case IO_ERROR:
                printf("Error: I/O error occurred while opening file.\n");
                return EXIT_FAILURE;
            default:
                printf("Error: Unknown error occurred while opening file.\n");
                return EXIT_FAILURE;
        }
    }

    char *buffer;
    size_t size;
    error = ReadFile(file, &buffer, &size);
    if (error != SUCCESS) {
        switch (error) {
            case NULL_POINTER:
                printf("Error: Null pointer passed to ReadFile().\n");
                return EXIT_FAILURE;
            case INVALID_ARGUMENT:
                printf("Error: Invalid argument passed to ReadFile().\n");
                return EXIT_FAILURE;
            case OUT_OF_MEMORY:
                printf("Error: Out of memory while allocating buffer for file contents.\n");
                return EXIT_FAILURE;
            case IO_ERROR:
                printf("Error: I/O error occurred while reading file.\n");
                return EXIT_FAILURE;
            default:
                printf("Error: Unknown error occurred while reading file.\n");
                return EXIT_FAILURE;
        }
    }

    error = WriteFile(file, buffer, size);
    if (error != SUCCESS) {
        switch (error) {
            case NULL_POINTER:
                printf("Error: Null pointer passed to WriteFile().\n");
                return EXIT_FAILURE;
            case INVALID_ARGUMENT:
                printf("Error: Invalid argument passed to WriteFile().\n");
                return EXIT_FAILURE;
            case IO_ERROR:
                printf("Error: I/O error occurred while writing to file.\n");
                return EXIT_FAILURE;
            default:
                printf("Error: Unknown error occurred while writing to file.\n");
                return EXIT_FAILURE;
        }
    }

    error = CloseFile(file);
    if (error != SUCCESS) {
        switch (error) {
            case NULL_POINTER:
                printf("Error: Null pointer passed to CloseFile().\n");
                return EXIT_FAILURE;
            case IO_ERROR:
                printf("Error: I/O error occurred while closing file.\n");
                return EXIT_FAILURE;
            default:
                printf("Error: Unknown error occurred while closing file.\n");
                return EXIT_FAILURE;
        }
    }

    free(buffer);

    return EXIT_SUCCESS;
}