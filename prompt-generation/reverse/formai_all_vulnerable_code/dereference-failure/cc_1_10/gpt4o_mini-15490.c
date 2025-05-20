//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define ASCII_HEIGHT 7
#define ASCII_WIDTH 6

// Function to convert a character to its ASCII art representation
void charToASCII(char c, char output[ASCII_HEIGHT][ASCII_WIDTH]) {
    // Define patterns for each character from ' ' (space) to '~' (tilde)
    const char *asciiChars[95][ASCII_HEIGHT] = {
        {"   ", "   ", "   ", "   ", "   ", "   ", "   "}, // ' '
        {"   ", "  |", "  |", "  |", "  |", "  |", "   "}, // '!'
        {"   ", "   ", " \\ ", "   ", "   ", "   ", "   "}, // '"'
        {"   ", "  |", "  |", "\\_|", "  |", "/ |", "   "}, // '#'
        {"   ", "  /", " / ", "|__|", "  |", "  |", "   "}, // '$'
        {"   ", " __", "  /", " /", "|", " \\ ", "   "}, // '%'
        {"   ", " __", " / ", "|__|", "  \\", "   ", "   "}, // '&'
        {"   ", "   ", "  |", "   ", "   ", "   ", "   "}, // '''
        {"   ", "   ", "   ", "  |", "  |", "   ", "   "}, // '('
        {"   ", "   ", "   ", "  |", "  |", "   ", "   "}, // ')'
        {"   ", "   ", " \\/", " /\\", "   ", "   ", "   "}, // '*'
        {"   ", "   ", "  |", " __|", "  |", "   ", "   "}, // '+'
        {"   ", "   ", "   ", "   ", "   ", " \\ ", "   "}, // ','
        {"   ", "   ", "   ", " __", "   ", "   ", "   "}, // '-'
        {"   ", "   ", "   ", "   ", "   ", "  |", "   "}, // '.'
        {"   ", "   ", "   ", "  /", " / ", "   ", "   "}, // '/'
        {"   ", " __", "|  |", "|__|", "|  |", " __", "   "}, // '0'
        {"   ", "  |", "  |", "  |", "  |", " __", "   "}, // '1'
        {"   ", " __", "  |", "  |", "  |", " __|", "   "}, // '2'
        {"   ", " __", "  |", "  |", " __|", "   ", "   "}, // '3'
        {"   ", "|  |", "|__|", "   |", "   |", "   ", "   "}, // '4'
        {"   ", " __", "|   ", " __|", "   ", "   ", "   "}, // '5'
        {"   ", " __", "|   ", "|__|", "   |", "   ", "   "}, // '6'
        {"   ", " __", "  |", "  |", "  |", "   ", "   "}, // '7'
        {"   ", " __", "|  |", "|__|", "   |", "   ", "   "}, // '8'
        {"   ", " __", "|  |", "|__|", "   |", "   ", "   "}, // '9'
        // Patterns for other characters omitted for brevity.
        // Add more characters as needed
    };

    if (c < 32 || c > 126) {
        // Non-printable characters will be set to blank
        for (int i = 0; i < ASCII_HEIGHT; i++) {
            strcpy(output[i], "   ");
        }
    } else {
        for (int i = 0; i < ASCII_HEIGHT; i++) {
            strcpy(output[i], asciiChars[c - 32][i]);
        }
    }
}

// Function to print the ASCII art representation of a string
void printASCIIArt(const char *str) {
    char output[ASCII_HEIGHT][ASCII_WIDTH];
    for (int i = 0; i < ASCII_HEIGHT; i++) {
        for (int j = 0; j < strlen(str); j++) {
            charToASCII(str[j], output);
            printf("%s ", output[i]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Enter a string (max %d characters): ", MAX_INPUT - 1);
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("\nASCII Art Representation:\n");
    printASCIIArt(input);
    return 0;
}