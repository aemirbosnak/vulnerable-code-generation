//Falcon-180B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// Macro for error handling
#define CHECK(expr) do { \
        if (!(expr)) { \
            printf("Error: %s\n", strerror(errno)); \
            exit(1); \
        } \
    } while (0)

// Function to read a file into a buffer
void read_file(const char* filename, char** buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    *buffer = malloc(file_size + 1);
    if (*buffer == NULL) {
        printf("Error: Could not allocate memory for file '%s'\n", filename);
        exit(1);
    }

    size_t bytes_read = fread(*buffer, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire file '%s'\n", filename);
        exit(1);
    }

    (*buffer)[file_size] = '\0';
    fclose(file);
}

// Function to write a buffer to a file
void write_file(const char* filename, const char* buffer) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    size_t bytes_written = fwrite(buffer, 1, strlen(buffer), file);
    if (bytes_written!= strlen(buffer)) {
        printf("Error: Could not write entire buffer to file '%s'\n", filename);
        exit(1);
    }

    fclose(file);
}

int main() {
    // Read input file
    char* input_buffer = NULL;
    read_file("input.txt", &input_buffer);

    // Do some processing on the input buffer

    // Write output file
    char* output_buffer = NULL;
    CHECK(asprintf(&output_buffer, "Processed input: %s", input_buffer));
    write_file("output.txt", output_buffer);

    free(input_buffer);
    free(output_buffer);

    return 0;
}