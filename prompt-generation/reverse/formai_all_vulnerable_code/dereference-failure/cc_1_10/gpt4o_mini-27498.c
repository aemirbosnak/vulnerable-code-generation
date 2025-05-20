//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void handle_error(const char *msg);
void file_operations(const char *filename);
void memory_allocations(size_t size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file_operations(argv[1]);

    return EXIT_SUCCESS;
}

// Function to handle errors
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to perform file operations including error handling
void file_operations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Error opening file");
    }

    char buffer[256];
    size_t read_bytes;
    
    while ((read_bytes = fread(buffer, sizeof(char), sizeof(buffer) - 1, file)) > 0) {
        buffer[read_bytes] = '\0'; // Null-terminate the string
        printf("%s", buffer);
    }

    if (ferror(file)) {
        handle_error("Error reading file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }

    printf("\nFile operations completed successfully.\n");
}

// Function to allocate memory with error handling
void memory_allocations(size_t size) {
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        handle_error("Memory allocation failed");
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = i * i; // Initialize with square values
    }
    
    for (size_t i = 0; i < size; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);
}

// Function demonstrating file reading and memory allocation together
void process_file_and_memory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Error opening file for processing");
    }

    int num;
    size_t count = 0;
    size_t size = 10; // Initial size for dynamic allocation
    int *data = malloc(size * sizeof(int));
    if (data == NULL) {
        handle_error("Initial memory allocation failed");
    }

    while (fscanf(file, "%d", &num) != EOF) {
        if (count >= size) {
            size *= 2; // Double the size
            data = realloc(data, size * sizeof(int));
            if (data == NULL) {
                handle_error("Reallocation failed");
            }
        }
        data[count++] = num;
    }

    if (ferror(file)) {
        handle_error("Error reading from file");
    }

    fclose(file);

    printf("Read %zu integers from the file:\n", count);
    for (size_t i = 0; i < count; i++) {
        printf("data[%zu] = %d\n", i, data[i]);
    }

    free(data);
    printf("Memory processing completed successfully.\n");
}