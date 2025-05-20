//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SUCCESS = 0,
    INVALID_ARGUMENT = -1,
    OUT_OF_MEMORY = -2,
    IO_ERROR = -3,
    UNEXPECTED_ERROR = -4
} ErrorStatus;

ErrorStatus validate_arguments(int argc, char **argv) {
    if (argc != 3) {
        return INVALID_ARGUMENT;
    }
    return SUCCESS;
}

ErrorStatus open_file(FILE **file, char *filename, char *mode) {
    *file = fopen(filename, mode);
    if (*file == NULL) {
        return IO_ERROR;
    }
    return SUCCESS;
}

ErrorStatus read_file(FILE *file, char **buffer, size_t *size) {
    *size = 0;
    char *tmp_buffer = NULL;
    size_t tmp_size = 0;
    while (!feof(file)) {
        tmp_size += 1024;
        tmp_buffer = realloc(tmp_buffer, tmp_size);
        if (tmp_buffer == NULL) {
            return OUT_OF_MEMORY;
        }
        size_t nread = fread(tmp_buffer + *size, 1, 1024, file);
        if (nread < 0) {
            return IO_ERROR;
        }
        *size += nread;
    }
    *buffer = tmp_buffer;
    return SUCCESS;
}

ErrorStatus write_file(FILE *file, char *buffer, size_t size) {
    size_t nwritten = fwrite(buffer, 1, size, file);
    if (nwritten != size) {
        return IO_ERROR;
    }
    return SUCCESS;
}

ErrorStatus close_file(FILE *file) {
    if (fclose(file) != 0) {
        return IO_ERROR;
    }
    return SUCCESS;
}

int main(int argc, char **argv) {
    ErrorStatus status;
    FILE *input_file, *output_file;
    char *input_buffer = NULL;
    size_t input_size;

    // Validate arguments
    status = validate_arguments(argc, argv);
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Invalid arguments\n");
        return status;
    }

    // Open input file
    status = open_file(&input_file, argv[1], "r");
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to open input file\n");
        return status;
    }

    // Read input file
    status = read_file(input_file, &input_buffer, &input_size);
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to read input file\n");
        close_file(input_file);
        return status;
    }

    // Open output file
    status = open_file(&output_file, argv[2], "w");
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to open output file\n");
        close_file(input_file);
        free(input_buffer);
        return status;
    }

    // Write output file
    status = write_file(output_file, input_buffer, input_size);
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to write output file\n");
        close_file(input_file);
        close_file(output_file);
        free(input_buffer);
        return status;
    }

    // Close files
    status = close_file(input_file);
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to close input file\n");
        close_file(output_file);
        free(input_buffer);
        return status;
    }

    status = close_file(output_file);
    if (status != SUCCESS) {
        fprintf(stderr, "Error: Unable to close output file\n");
        free(input_buffer);
        return status;
    }

    // Free memory
    free(input_buffer);

    return SUCCESS;
}