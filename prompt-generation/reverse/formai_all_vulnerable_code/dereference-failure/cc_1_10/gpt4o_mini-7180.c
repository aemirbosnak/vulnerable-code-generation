//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function to calculate checksum
unsigned int calculate_checksum(const char *data, size_t length) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)data[i];
    }
    return checksum;
}

// Function to read file content
char *read_file(const char *filename, size_t *file_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Move pointer to the end of the file to get its size
    fseek(file, 0, SEEK_END);
    *file_size = ftell(file);
    rewind(file); // Set pointer back to the start

    // Allocate memory for file content
    char *buffer = (char *)malloc(*file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Read file content into buffer
    fread(buffer, 1, *file_size, file);
    buffer[*file_size] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to write checksum to a file
int write_checksum(const char *filename, unsigned int checksum) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening checksum file");
        return -1;
    }

    fprintf(file, "Checksum: %u\n", checksum);
    fclose(file);
    return 0;
}

// Main function to orchestrate the checksum calculation
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_checksum_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t file_size = 0;
    char *file_content = read_file(argv[1], &file_size);
    if (!file_content) {
        return EXIT_FAILURE;
    }

    unsigned int checksum = calculate_checksum(file_content, file_size);
    printf("Calculated checksum for '%s': %u\n", argv[1], checksum);

    if (write_checksum(argv[2], checksum) != 0) {
        free(file_content);
        return EXIT_FAILURE;
    }

    printf("Checksum written to '%s'\n", argv[2]);
    free(file_content);
    return EXIT_SUCCESS;
}