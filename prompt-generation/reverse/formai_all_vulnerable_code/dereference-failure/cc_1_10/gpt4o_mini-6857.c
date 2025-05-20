//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024  // Maximum file size 1MB
#define BUFFER_SIZE 1024            // Buffer size for reading

unsigned long calculate_checksum(const char *data, size_t length) {
    unsigned long checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)data[i];
    }
    return checksum;
}

void read_file_content(const char *file_path, char *buffer, size_t *file_size) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    *file_size = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <file_path>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *file_path = argv[1];
    char *buffer = (char*)malloc(MAX_FILE_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    size_t file_size;
    read_file_content(file_path, buffer, &file_size);

    unsigned long checksum = calculate_checksum(buffer, file_size);

    printf("Checksum for file '%s': %lu\n", file_path, checksum);

    free(buffer);
    return EXIT_SUCCESS;
}