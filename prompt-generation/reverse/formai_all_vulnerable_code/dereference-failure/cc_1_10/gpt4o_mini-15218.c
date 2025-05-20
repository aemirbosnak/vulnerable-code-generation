//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Function prototypes
void* safe_malloc(size_t size);
void safe_strcpy(char* dest, const char* src, size_t dest_size);
void perform_file_operations(const char* filename);
void handle_error(const char* msg);

int main() {
    // Demonstrating safe memory allocation
    size_t array_size = 10;
    int* int_array = (int*)safe_malloc(array_size * sizeof(int));

    // Initialize the array with values.
    for (size_t i = 0; i < array_size; ++i) {
        int_array[i] = (int)i * 10;
    }

    // Log the contents of the int_array
    printf("Array contents:\n");
    for (size_t i = 0; i < array_size; ++i) {
        printf("%d ", int_array[i]);
    }
    printf("\n");

    // Performing file operations
    const char* filename = "example.txt";
    perform_file_operations(filename);

    // Free allocated memory
    free(int_array);
    return 0;
}

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        handle_error("Memory allocation failed");
    }
    return ptr;
}

void safe_strcpy(char* dest, const char* src, size_t dest_size) {
    if (strlen(src) >= dest_size) {
        handle_error("String copy failed: Source string too long");
    }
    strcpy(dest, src);
}

void perform_file_operations(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        handle_error("File opening failed");
    }

    const char* content = "Hello, ephemeral file operations!\n";
    if (fputs(content, file) == EOF) {
        fclose(file);
        handle_error("Writing to file failed");
    }

    if (fclose(file) != 0) {
        handle_error("File closing failed");
    }

    // Now read the content back
    char buffer[256];
    file = fopen(filename, "r");
    if (!file) {
        handle_error("File opening for reading failed");
    }

    printf("Reading from file:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (fclose(file) != 0) {
        handle_error("File closing failed");
    }

    // Clean up the file created
    if (remove(filename) != 0) {
        handle_error("File removal failed");
    }
}

void handle_error(const char* msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}