//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

// Function to calculate checksum of a file
uint32_t calculate_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    uint32_t checksum = 0;
    uint8_t buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return checksum;
}

// Function to print the checksum in a formatted way
void print_checksum(const char *filename, uint32_t checksum) {
    printf("Checksum for file '%s': %08x\n", filename, checksum);
}

// Function to display usage information
void display_usage() {
    fprintf(stderr, "Usage: checksum_calculator <filename>\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        display_usage();
    }

    // Get the filename from the command line arguments
    const char *filename = argv[1];

    // Calculate the checksum
    uint32_t checksum = calculate_checksum(filename);

    // Print the checksum
    print_checksum(filename, checksum);

    return EXIT_SUCCESS;
}

// Additional secure function to check input validation
int is_valid_file(const char *filename) {
    // Basic validation: Ensure the filename doesn't contain illegal characters
    const char *invalid_chars = "/\\?%*:|\"<>";
    if (strpbrk(filename, invalid_chars) != NULL) {
        fprintf(stderr, "Invalid file name: %s\n", filename);
        return 0;
    }
    return 1;
}

// Function to read a file as a string to ensure it can be processed
char *read_file_as_string(const char *filename) {
    if (!is_valid_file(filename)) {
        display_usage();
    }

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}