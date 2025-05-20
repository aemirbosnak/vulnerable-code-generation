//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
unsigned long calculate_checksum(const char *data, size_t length);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input file
    const char *input_file = argv[1];
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read file contents
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';  // Null-terminate the string
    fclose(file);

    // Calculate the checksum
    unsigned long checksum = calculate_checksum(buffer, file_size);
    printf("Checksum for file '%s': %lu\n", input_file, checksum);

    // Clean up
    free(buffer);
    return EXIT_SUCCESS;
}

// Function to calculate the checksum of a string
unsigned long calculate_checksum(const char *data, size_t length) {
    unsigned long checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)data[i]; // Sum the ASCII values of each character
    }
    return checksum;
}

// Function to print usage information
void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input_file>\n", prog_name);
}