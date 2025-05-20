//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void check_memory_allocation(void *ptr);
void handle_file_error(FILE *file, const char *filename);
void process_input(const char *input, int *result);

int main() {
    char *input_buffer;
    int result = 0;

    // Allocate memory for input buffer
    input_buffer = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
    check_memory_allocation(input_buffer);

    printf("Welcome to the Error Handling Adventure!\n");
    printf("Please enter a number to be doubled: ");

    // Read user input
    if (fgets(input_buffer, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Input error: %s\n", strerror(errno));
        free(input_buffer);
        return EXIT_FAILURE;
    }

    // Process the input
    process_input(input_buffer, &result);
    printf("The doubled value is: %d\n", result);

    // Clean up
    free(input_buffer);
    printf("Thank you for playing!\n");
    return EXIT_SUCCESS;
}

void check_memory_allocation(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void handle_file_error(FILE *file, const char *filename) {
    if (file == NULL) {
        fprintf(stderr, "Could not open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void process_input(const char *input, int *result) {
    char *endptr; // pointer for error handling

    // Convert string to integer
    errno = 0; // Reset errno before the conversion
    long n = strtol(input, &endptr, 10);

    // Check for conversion errors
    if (errno != 0 || endptr == input || *endptr != '\n') {
        fprintf(stderr, "Invalid input: '%s'. Please enter a valid number.\n", input);
        exit(EXIT_FAILURE);
    }

    // Double the result
    *result = n * 2;
}