//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize the user input
char* sanitizeInput(char* user_input) {

    // Define the patterns/characters to be removed
    char *patterns[] = { 
                          "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", 
                          "-", "+", "=", "{", "}", "[", "]", "|", "\\", ";", 
                          ":", "\"", "\'", ",", ".", "<", ">", "/", "?", "`", "~", 
                          "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                          " ", "\n", "\r", "\t" 
                      };

    // Get the number of patterns to be removed
    int num_patterns = sizeof(patterns)/sizeof(patterns[0]);

    // Initialize variables
    char *clean_input = NULL;
    int input_len = strlen(user_input);
    int clean_input_len = input_len;

    // Allocate memory for the cleaned input
    clean_input = (char *) malloc(sizeof(char) * (clean_input_len + 1));
    memset(clean_input, 0, sizeof(clean_input) * (clean_input_len + 1));

    // Copy user input to cleaned input buffer, while removing unwanted patterns/characters
    for (int i = 0; i < input_len; i++) {
        int remove_pattern = 0;

        for (int j = 0; j < num_patterns; j++) {
            if (user_input[i] == patterns[j][0]) {
                remove_pattern = 1;
                break;
            }
        }

        if (!remove_pattern) {
            clean_input[strlen(clean_input)] = user_input[i];
        }
    }

    return clean_input;
}

// Main function to receive user input and sanitize it
int main() {

    char user_input[5000];
    char *clean_input = NULL;

    printf("Welcome! Please enter your input below:\n");
    fgets(user_input, sizeof(user_input), stdin);

    // Sanity check
    if (user_input[strlen(user_input) - 1] == '\n') {
        user_input[strlen(user_input) - 1] = '\0';
    }

    // Sanitize user input
    clean_input = sanitizeInput(user_input);

    // Print sanitized input for testing
    printf("Sanitized Input: %s\n", clean_input);

    // Free memory
    free(clean_input);

    return 0;
}