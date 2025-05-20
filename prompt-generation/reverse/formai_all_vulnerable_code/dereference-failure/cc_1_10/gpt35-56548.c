//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void panic(const char* message);

int main(int argc, char **argv) {
    FILE *input_file = NULL;
    char *buffer = NULL;
    size_t input_size = 0;

    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        panic("Program terminated.");
    }

    // Attempt to open the input file
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Failed to open input file %s\n", argv[1]);
        panic("Program terminated.");
    }

    // Attempt to determine the size of the input file
    fseek(input_file, 0, SEEK_END);
    input_size = ftell(input_file);
    if (input_size == -1) {
        printf("Failed to determine file size for input file %s\n", argv[1]);
        panic("Program terminated.");
    }

    // Allocate memory for the input buffer
    buffer = (char *) calloc(input_size + 1, sizeof(char));
    if (!buffer) {
        printf("Failed to allocate input buffer of size %lu\n", input_size + 1);
        panic("Program terminated.");
    }

    // Read the input file into the buffer
    rewind(input_file);
    if (fread(buffer, sizeof(char), input_size, input_file) != input_size) {
        printf("Failed to read input file %s into buffer\n", argv[1]);
        panic("Program terminated.");
    }

    // Close the input file
    if (fclose(input_file) != 0) {
        printf("Failed to close input file %s\n", argv[1]);
        panic("Program terminated.");
    }

    // Process the input data
    printf("Input data:\n%s\n", buffer);

    // Free the input buffer
    free(buffer);

    printf("Program completed successfully!\n");
    return EXIT_SUCCESS;
}

void panic(const char* message) {
    fprintf(stderr, "Panic: %s\n", message);
    exit(EXIT_FAILURE);
}