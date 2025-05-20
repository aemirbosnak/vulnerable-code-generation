//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Custom error codes
#define FILE_OPEN_ERROR 1
#define MEMORY_ALLOCATION_ERROR 2
#define INVALID_OPERATION_ERROR 3

// Function prototypes
void handle_error(int error_code);
void process_file(const char *filename);
void perform_memory_intensive_operation(size_t size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return INVALID_OPERATION_ERROR;
    }

    const char *filename = argv[1];
    process_file(filename);

    size_t array_size = 1000000;  // Example size for memory operation
    perform_memory_intensive_operation(array_size);

    printf("Program executed successfully!\n");
    return 0;
}

void handle_error(int error_code) {
    switch (error_code) {
        case FILE_OPEN_ERROR:
            fprintf(stderr, "Error: Unable to open file. %s\n", strerror(errno));
            break;
        case MEMORY_ALLOCATION_ERROR:
            fprintf(stderr, "Error: Memory allocation failed. %s\n", strerror(errno));
            break;
        case INVALID_OPERATION_ERROR:
            fprintf(stderr, "Error: Invalid operation. Please provide a valid input.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error occurred.\n");
            break;
    }
    exit(error_code);
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error(FILE_OPEN_ERROR);
    }

    char line[256];
    int line_count = 0;

    while (fgets(line, sizeof(line), file)) {
        printf("Line %d: %s", ++line_count, line);
    }

    if (ferror(file)) {
        fclose(file);
        handle_error(FILE_OPEN_ERROR);
    }

    printf("Total lines processed: %d\n", line_count);
    fclose(file);
}

void perform_memory_intensive_operation(size_t size) {
    int *array = malloc(size * sizeof(int));
    if (!array) {
        handle_error(MEMORY_ALLOCATION_ERROR);
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = i;  // Performing some operation
    }

    printf("Memory-intensive operation completed: Array initialized with %zu elements.\n", size);
    free(array);
}