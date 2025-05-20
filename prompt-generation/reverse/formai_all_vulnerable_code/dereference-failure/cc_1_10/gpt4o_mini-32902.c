//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define ASCII art character set
const char *ascii_chars = " .:-=+*%@#";

// Function to convert a character to ASCII art
void char_to_ascii(char c, char *output) {
    if (c >= ' ' && c <= '~') { // Consider only printable ASCII
        int index = (c - ' ') * (sizeof(ascii_chars) - 1) / 94;
        strcpy(output, ascii_chars[index]);
    } else {
        strcpy(output, " ");
    }
}

// Function to convert a string to ASCII art
void string_to_ascii_art(const char *str) {
    size_t len = strlen(str);
    char art[2]; // Array to hold ASCII art character

    // Loop through each character in the string
    for (size_t i = 0; i < len; i++) {
        char_to_ascii(str[i], art);
        printf("%s ", art);
    }
    printf("\n");
}

// Function to print a welcome message
void print_welcome_message() {
    printf("Welcome to the Text to ASCII Art Generator!\n");
    printf("Enter a string (or 'exit' to quit): \n");
}

// Main function
int main() {
    char input[1024]; // Input string buffer

    print_welcome_message();

    while (1) {
        // Get input from the user
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove the trailing newline character
        input[strcspn(input, "\n")] = 0; 

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Convert and print the ASCII art
        string_to_ascii_art(input);
    }

    return 0;
}