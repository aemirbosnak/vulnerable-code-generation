//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to remove leading and trailing whitespace
void trim_whitespace(char *str) {
    char *end;

    // Trim leading whitespace
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the string after the last non-whitespace character
    *(end + 1) = '\0';
}

// Function to sanitize user input
void sanitize_input(char *input) {
    char sanitized[MAX_INPUT_LENGTH];
    int j = 0;

    for (int i = 0; input[i]; i++) {
        // Allow only alphanumeric characters and spaces
        if (isalnum((unsigned char)input[i]) || isspace((unsigned char)input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized); // Copy sanitized input back
}

// Function to display the final sanitized input
void display_sanitized_input(const char *input) {
    printf("Sanitized Input: '%s'\n", input);
}

int main() {
    char user_input[MAX_INPUT_LENGTH];

    printf("Welcome to the Enchanted Forest of User Input!\n");
    printf("Here, we only accept the finest, purest of inputs\n");
    printf("Please enter your magical phrase (letters, numbers, and spaces only): ");

    // Get user input
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        printf("Failed to read input, exiting...\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    // Trim and sanitize the user input
    trim_whitespace(user_input);
    sanitize_input(user_input);

    // Display the refined output
    display_sanitized_input(user_input);

    // Quest completion message
    printf("Your quest for the perfect input has been successful!\n");
    printf("May your journey through the enchanted realm be filled with joy!\n");

    return 0;
}