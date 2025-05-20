//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Define a constant for the maximum length of input
#define MAX_LENGTH 256

// Function declarations
void sanitizeInput(char *input);
void printUsage(const char *progName);

/**
 * Sanitize input string by removing unwanted characters and trimming spaces.
 * @param input - The input string to be sanitized.
 */
void sanitizeInput(char *input) {
    int n = strlen(input);
    char sanitized[MAX_LENGTH];
    int j = 0;

    // Scan through each character in the input
    for (int i = 0; i < n; i++) {
        // Only keep alphanumeric characters and spaces
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }

    // Null terminate the sanitized string
    sanitized[j] = '\0';
    
    // Copy sanitized string back to the input
    strcpy(input, sanitized);
}

/**
 * Print usage information for the program.
 * @param progName - The name of the program.
 */
void printUsage(const char *progName) {
    printf("Usage: %s <string>\n", progName);
    printf("This program sanitizes input by removing unwanted characters and spaces.\n");
    printf("Only alphanumeric characters and spaces are retained.\n");
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize buffer for the input
    char input[MAX_LENGTH];

    // Copy input from command line argument safely
    strncpy(input, argv[1], MAX_LENGTH - 1);
    input[MAX_LENGTH - 1] = '\0'; // Ensure null termination

    printf("Original Input: %s\n", input);

    // Sanitize the input
    sanitizeInput(input);

    // Output the sanitized result
    printf("Sanitized Input: %s\n", input);
    
    return EXIT_SUCCESS;
}