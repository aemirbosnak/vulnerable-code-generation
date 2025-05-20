//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256

void handle_error(const char *msg) {
    fprintf(stderr, "Error: %s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void validate_file(FILE *file, const char *filename) {
    if (file == NULL) {
        handle_error("Opening file failed");
    }
}

void validate_pointer(void *ptr) {
    if (ptr == NULL) {
        handle_error("Memory allocation failed");
    }
}

void read_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    validate_file(file, filename);

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        puts(buffer);  // Print the line to STDOUT
    }

    if (ferror(file)) {
        handle_error("Error reading from the file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing the file");
    }
}

void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    validate_file(file, filename);

    if (fprintf(file, "%s", content) < 0) {
        handle_error("Error writing to the file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing the file after writing");
    }
}

void allocate_memory(int size) {
    void *memory = malloc(size);
    validate_pointer(memory);
    // Memory allocated successfully
    printf("Successfully allocated %d bytes of memory.\n", size);
    free(memory); // Be paranoid and free it immediately
}

void paranoid_string_copy(char *dest, const char *src, size_t dest_size) {
    if (strlen(src) >= dest_size) {
        handle_error("String overflow detected");
    }
    strcpy(dest, src);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename_to_read> <filename_to_write>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename_to_read = argv[1];
    const char *filename_to_write = argv[2];
    
    // Example of paranoid memory allocation
    allocate_memory(512); // Allocate 512 bytes of dummy memory

    // Test writing to a file
    const char *content_to_write = "Hello, World!\nThis is a test file.\n";
    write_to_file(filename_to_write, content_to_write);

    // Test reading from a file
    read_from_file(filename_to_read);

    // Example of paranoid string copy
    char safe_buffer[MAX_BUFFER_SIZE];
    const char *unsafe_string = "This string is too long and might cause trouble if not handled properly.";
    paranoid_string_copy(safe_buffer, unsafe_string, sizeof(safe_buffer));

    // Finished
    printf("Program finished executing successfully.\n");
    return 0; // Exit with success
}