//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Paranoid error handling macros
#define PARANOID_CHECK(condition)                                                           \
    if (!(condition)) {                                                                    \
        fprintf(stderr, "[%s:%d] Assertion failed: %s\n", __FILE__, __LINE__, #condition); \
        exit(EXIT_FAILURE);                                                                \
    }
#define PARANOID_ASSERT(condition)                                                              \
    if (!(condition)) {                                                                    \
        fprintf(stderr, "[%s:%d] Assertion failed: %s\n", __FILE__, __LINE__, #condition); \
    }

// Calculate the checksum of a file
unsigned long long calculate_checksum(const char *filename) {
    // Open the file in read-only mode
    FILE *fp = fopen(filename, "rb");
    PARANOID_CHECK(fp != NULL);

    // Allocate a buffer to store the file contents
    char *buffer = malloc(MAX_FILE_SIZE);
    PARANOID_CHECK(buffer != NULL);

    // Read the file contents into the buffer
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp);
    PARANOID_ASSERT(bytes_read != 0);

    // Close the file
    fclose(fp);

    // Calculate the checksum of the buffer
    unsigned long long checksum = 0;
    for (size_t i = 0; i < bytes_read; i++) {
        checksum += buffer[i];
    }

    // Free the buffer
    free(buffer);

    // Return the checksum
    return checksum;
}

// Print the usage of the program
void print_usage(const char *program_name) {
    printf("Usage: %s <filename>\n", program_name);
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Calculate the checksum of the file
    unsigned long long checksum = calculate_checksum(argv[1]);

    // Print the checksum
    printf("Checksum: %llu\n", checksum);

    return 0;
}