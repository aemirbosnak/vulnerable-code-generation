//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 256

// Function to strip leading and trailing whitespace characters
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\t')) --end;

    // Null terminate after last valid character
    *(end + 1) = '\0';

    return str;
}

// Function to sanitize input
void sanitize_input(const char* input, char* output) {
    int i, j = 0;
    
    for (i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= '0' && input[i] <= '9') ||
            input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '-') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null terminate sanitized output
}

// Helper function to print characters in hexadecimal
void print_hex(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("0x%02x ", (unsigned char)str[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized[MAX_INPUT_LENGTH];
    char* trimmed_input;

    puts("Welcome to the Enigmatic Input Sanitizer!");
    puts("Anything you type will face the trials of the sanitizing gauntlet.");
    puts("Please enter your text (end with ENTER, max 256 chars):");

    // Read user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        puts("An unfortunate event occurred while gathering your thoughts.");
        return EXIT_FAILURE;
    }

    // Trim whitespace from input
    trimmed_input = trim_whitespace(input);

    // Sanitize user input
    sanitize_input(trimmed_input, sanitized);

    // Output results
    printf("Original Input: %s", trimmed_input);
    printf("Sanitized Input: %s\n", sanitized);
    
    puts("Now, let us unveil the hidden secrets of your input in hexadecimal!");
    print_hex(trimmed_input);

    puts("And here is the relic of your sanitized input in hexadecimal:");
    print_hex(sanitized);
    
    puts("The saga of your input has reached its conclusion.");
    return EXIT_SUCCESS;
}