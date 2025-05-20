//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '.', ',', '!', '?', ';', ':', '"', '\''};

// Function to sanitize the input string
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized string
    char* sanitized_input = malloc(MAX_INPUT_LENGTH);

    // Initialize the sanitized string
    memset(sanitized_input, 0, MAX_INPUT_LENGTH);

    // Loop through each character in the input string
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        // Check if the character is allowed
        bool is_allowed = false;
        for (int k = 0; k < strlen(allowed_characters); k++) {
            if (input[i] == allowed_characters[k]) {
                is_allowed = true;
                break;
            }
        }

        // If the character is allowed, add it to the sanitized string
        if (is_allowed) {
            sanitized_input[j] = input[i];
            j++;
        }

        // Increment the index of the input string
        i++;
    }

    // Return the sanitized string
    return sanitized_input;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_LENGTH];
    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the input string
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized string
    printf("The sanitized string is: %s", sanitized_input);

    // Free the memory allocated for the sanitized string
    free(sanitized_input);

    return 0;
}