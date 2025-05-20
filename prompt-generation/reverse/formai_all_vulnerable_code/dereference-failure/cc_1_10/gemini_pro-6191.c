//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: complex
// C program to calculate the checksum of a given array of bytes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of an array of bytes
unsigned char calculate_checksum(const unsigned char *data, size_t length) {
    unsigned char checksum = 0;

    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
    }

    return checksum;
}

// Function to print the checksum of an array of bytes
void print_checksum(const unsigned char *data, size_t length) {
    unsigned char checksum = calculate_checksum(data, length);
    printf("Checksum: %02X\n", checksum);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an input file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Get the file size
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for the file data
    unsigned char *data = malloc(file_size);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for file data\n");
        return EXIT_FAILURE;
    }

    // Read the file data into memory
    size_t bytes_read = fread(data, 1, file_size, input_file);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error reading file data\n");
        return EXIT_FAILURE;
    }

    // Close the input file
    fclose(input_file);

    // Calculate the checksum of the file data
    print_checksum(data, file_size);

    // Free the memory allocated for the file data
    free(data);

    return EXIT_SUCCESS;
}