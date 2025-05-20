//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define BLACKLIST_SIZE 5

// Function to sanitize the input
void sanitize_input(const char* input, char* sanitized_output) {
    const char* blacklist[BLACKLIST_SIZE] = {
        "DROP", 
        "SELECT", 
        "INSERT", 
        "DELETE", 
        "--"
    };

    int i, j, is_blacklisted;

    char* token;
    char* tmp_input = strdup(input);
    char* saveptr;

    // Iterate through each token in the input
    token = strtok_r(tmp_input, " ", &saveptr);
    while (token != NULL) {
        is_blacklisted = 0;

        // Check against the blacklist
        for (i = 0; i < BLACKLIST_SIZE; i++) {
            if (strcasecmp(token, blacklist[i]) == 0) {
                is_blacklisted = 1;
                break;
            }
        }

        // If not blacklisted, append to sanitized_output
        if (!is_blacklisted) {
            strcat(sanitized_output, token);
            strcat(sanitized_output, " ");
        }

        // Get the next token
        token = strtok_r(NULL, " ", &saveptr);
    }

    // Free the duplicate string
    free(tmp_input);
    // Trim the final output to avoid trailing space
    sanitized_output[strlen(sanitized_output) - 1] = '\0'; 
}

// Function to display menu
void display_menu() {
    printf("===================================\n");
    printf("          Input Sanitizer         \n");
    printf("===================================\n");
    printf("Enter your input (type 'exit' to quit):\n");
    printf("===================================\n");
}

// Function to clear the output buffer
void clear_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    char sanitized_output[MAX_INPUT_SIZE] = {'\0'};
    
    display_menu();

    while (1) {
        printf("> ");
        if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
            break; // Exit on input error
        }

        // Remove trailing newline
        user_input[strcspn(user_input, "\n")] = 0;

        // Check if user wants to exit
        if (strcasecmp(user_input, "exit") == 0) {
            break;
        }

        // Reset the sanitized_output for new input
        sanitized_output[0] = '\0';

        // Sanitize the input
        sanitize_input(user_input, sanitized_output);

        // Print out sanitized result
        printf("Sanitized Output: %s\n", sanitized_output);
    }

    printf("Exiting program...\n");
    return 0;
}