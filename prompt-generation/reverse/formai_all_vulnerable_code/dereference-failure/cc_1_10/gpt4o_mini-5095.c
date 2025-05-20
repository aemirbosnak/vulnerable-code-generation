//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

// Function declarations
unsigned long calculate_checksum(const char *input);
void strip_newline(char *str);
void display_usage();

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH];
    unsigned long checksum;

    // Display usage if no input is provided
    if (argc < 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    // Get the input string from the command line arguments
    strncpy(input, argv[1], MAX_INPUT_LENGTH - 1);
    input[MAX_INPUT_LENGTH - 1] = '\0'; // Ensure null-termination

    // Strip newline characters (if present)
    strip_newline(input);

    // Calculate the checksum
    checksum = calculate_checksum(input);

    // Display the result
    printf("Input String: %s\n", input);
    printf("Checksum: %lu\n", checksum);

    return EXIT_SUCCESS;
}

// Function to calculate the checksum
unsigned long calculate_checksum(const char *input) {
    unsigned long checksum = 0;
    size_t length = strlen(input);
    
    // Simple checksum calculation: sum of ASCII values modulo 256
    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)input[i];
    }

    return checksum % 256; // Return the checksum value within 0-255
}

// Function to strip newline characters from strings
void strip_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0'; // Replace newline with null terminator
    }
}

// Function to display usage instructions
void display_usage() {
    printf("Usage: checksum_calculator <input_string>\n");
    printf("Calculates a simple checksum of the provided input string.\n");
    printf("Example: checksum_calculator \"hello world\"\n");
}