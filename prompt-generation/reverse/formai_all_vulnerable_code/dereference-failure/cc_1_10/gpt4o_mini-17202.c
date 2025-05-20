//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

// Function prototypes
void sanitizeInput(char* input);
void trimWhitespace(char* input);
int isValidInput(const char* input);
void getInput(char* buffer, size_t size);
void displayMenu();
void processInput(const char* input);

int main() {
    // Initialize necessary variables
    char userInput[MAX_INPUT_SIZE];
    int running = 1;

    // Display the menu to the user
    displayMenu();

    // Main loop to continuously get user input until exit
    while (running) {
        printf("Enter your choice: ");
        getInput(userInput, sizeof(userInput));

        // Sanitize input before processing
        sanitizeInput(userInput);

        // Check if the user wants to exit
        if (strcmp(userInput, "exit") == 0) {
            running = 0;
            printf("Exiting the program. Goodbye!\n");
        } else {
            // Process the valid input
            processInput(userInput);
        }
    }

    return 0;
}

// Function to sanitize input
void sanitizeInput(char* input) {
    // Trim whitespace from the input
    trimWhitespace(input);
    
    // Check for validity
    if (!isValidInput(input)) {
        printf("Invalid input received. Please enter a valid option.\n");
        input[0] = '\0';  // Clear invalid input
    }
}

// Function to trim leading and trailing whitespace
void trimWhitespace(char* input) {
    char* end;
    // Trim leading whitespace
    while (isspace((unsigned char)*input)) input++;

    // Trim trailing whitespace
    end = input + strlen(input) - 1;
    while (end > input && isspace((unsigned char)*end)) end--;

    // Null terminate the string
    *(end + 1) = '\0';
}

// Function to validate the input
int isValidInput(const char* input) {
    // Valid options are digits '1' to '5' or 'exit'
    if (strcmp(input, "exit") == 0) return 1;
    if (strlen(input) == 1 && input[0] >= '1' && input[0] <= '5') return 1;
    return 0;
}

// Function to get input from the user
void getInput(char* buffer, size_t size) {
    // Use fgets to avoid buffer overflow
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove the newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// Function to display the menu of options
void displayMenu() {
    printf("=== User Input Sanitizer Program ===\n");
    printf("1. Option One\n");
    printf("2. Option Two\n");
    printf("3. Option Three\n");
    printf("4. Option Four\n");
    printf("5. Option Five\n");
    printf("Type 'exit' to quit the program.\n");
}

// Function to process valid input and display corresponding messages
void processInput(const char* input) {
    switch (input[0]) {
        case '1':
            printf("You selected Option One.\n");
            break;
        case '2':
            printf("You selected Option Two.\n");
            break;
        case '3':
            printf("You selected Option Three.\n");
            break;
        case '4':
            printf("You selected Option Four.\n");
            break;
        case '5':
            printf("You selected Option Five.\n");
            break;
        default:
            // No need for this because of prior validation but kept for safety
            printf("This should not be displayed. Invalid input detected.\n");
            break;
    }
}