//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize_input(char* input) {
    char* sanitized_input = malloc(strlen(input) + 1); // Allocate memory for sanitized input
    int i = 0; // Initialize counter

    // Loop through input string and copy only alphanumeric characters
    while (input[i]) {
        if (isalnum(input[i])) {
            sanitized_input[i] = input[i];
            i++;
        }
    }
    sanitized_input[i] = '\0'; // Add null terminator

    // Free memory used by input string
    free(input);

    // Copy sanitized input to input string
    strcpy(input, sanitized_input);

    // Free memory used by sanitized input
    free(sanitized_input);
}

int main() {
    // Initialize variables
    char input[1000];
    int choice;

    // Welcome message
    printf("Welcome to the User Input Sanitizer!\n");

    // Loop until user chooses to exit
    do {
        // Prompt user for input
        printf("Enter some text: ");
        fgets(input, sizeof(input), stdin);

        // Sanitize input
        sanitize_input(input);

        // Display sanitized input
        printf("Sanitized input: %s\n", input);

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}