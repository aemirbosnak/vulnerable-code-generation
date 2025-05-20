//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to check if the input is valid based on user-defined criteria
int is_valid_input(const char *input) {
    // Check for empty input
    if (input == NULL || strlen(input) == 0) {
        return 0; // Invalid: Empty input
    }

    // Validate each character in the input; allow alphanumeric and spaces only
    for (size_t i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i]) && !isspace(input[i])) {
            return 0; // Invalid: Non-alphanumeric character found
        }
    }

    // All checks passed
    return 1;
}

// Function to sanitize the input - remove leading/trailing spaces
void sanitize_input(char *input) {
    char *start = input;
    char *end = input + strlen(input) - 1;

    // Trim leading whitespace
    while (isspace(*start)) {
        start++;
    }

    // Trim trailing whitespace
    while (end > start && isspace(*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';

    // Move the validated input to the start of the original array
    memmove(input, start, end - start + 2);
}

// Function to log input into a file
void log_input(const char *input) {
    FILE *file = fopen("input_log.txt", "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    
    fprintf(file, "%s\n", input);
    fclose(file);
}

// Main program
int main() {
    char user_input[MAX_INPUT_LENGTH];

    // Continuously prompt the user for input
    while (1) {
        printf("Enter a valid input (or type 'exit' to quit): ");
        if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
            perror("Error reading input");
            continue;
        }

        // Remove the trailing newline character
        user_input[strcspn(user_input, "\n")] = '\0';

        // Exit condition
        if (strcasecmp(user_input, "exit") == 0) {
            break; // Exit the loop
        }

        // Sanitize and validate the input
        sanitize_input(user_input);
        if (is_valid_input(user_input)) {
            printf("Valid input received: '%s'\n", user_input);
            log_input(user_input); // Log input to file
        } else {
            printf("Invalid input. Please enter alphanumeric characters only.\n");
        }
    }

    printf("Program terminated. Logged inputs to 'input_log.txt'.\n");
    return 0;
}