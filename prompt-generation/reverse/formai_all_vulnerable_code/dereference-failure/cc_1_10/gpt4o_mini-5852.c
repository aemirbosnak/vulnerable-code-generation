//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void printAsciiArt(char *input);
void drawBorder(int length);
void convertToAscii(char *input, char *output);
void displayArt(char *asciiArt, int length);

int main() {
    // Surprise! A delightful ASCII art generator!
    char input[256];
    char asciiArt[1024] = {0}; // Buffer for the ASCII art output

    // Instructions for the user
    printf("Welcome to the ASCII Art Generator! 🎉\n");
    printf("Enter the text you want to convert to ASCII art (max 255 characters): ");
    fgets(input, sizeof(input), stdin);

    // Removing the newline character from the input
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Convert input to ASCII art
    convertToAscii(input, asciiArt);
    printf("\nHere is your ASCII Art:\n");
    drawBorder(strlen(asciiArt)); // Draw a fancy border
    displayArt(asciiArt, strlen(asciiArt));
    drawBorder(strlen(asciiArt)); // Draw a fancy border

    return 0;
}

// Function to print the border around the ASCII art
void drawBorder(int length) {
    for (int i = 0; i < length + 4; i++) {
        printf("*"); // A surprise border made of stars! ✨
    }
    printf("\n* "); 
}

// Function to convert text to ASCII art (a very simplistic representation)
void convertToAscii(char *input, char *output) {
    // Create a simple mapping for demonstration purposes
    char *asciiMap[] = {
        "     ",
        "A   A",
        "A   A",
        "AAAAA",
        "A   A",
        "A   A",
        "A   A",
        " ",
        "B   B",
        "BBBBB"
    };

    int j = 0;
    
    // Iterate through each character to build ASCII art
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') { // Only handle uppercase letters
            int index = c - 'A'; // Calculate the index in the asciiMap
            strcat(output, asciiMap[index]);
            strcat(output, "\n"); // Add a line break after each character
        }
        else if (c == ' ') {
            strcat(output, "     \n"); // Space representation
        }
        // Handle lowercase inputs or unsupported characters if desired
    }
}

// Function to display the ASCII art
void displayArt(char *asciiArt, int length) {
    printf("%s", asciiArt);
    printf("* \n"); // End the border for the ASCII art
}