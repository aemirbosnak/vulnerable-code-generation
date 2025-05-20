//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet Morse Code Conversion

// Declare the Morse code table
char morse_table[][6] = {
    {'.', '-', '-', '-', '-', '.'}, // A
    {'-', '.', '.', '.', '.', '.'}, // B
    {'-', '-', '.', '-', '.', '.'}, // C
    {'-', '.', '-', '.', '.', '.'}, // D
    {'.', '.', '.', '.', '.', '.'}, // E
    {'.', '.', '-', '.', '.', '.'}, // F
    {'-', '-', '-', '.', '.', '.'}, // G
    {'.', '.', '.', '.', '.', '.'}, // H
    {'.', '.', '.', '.', '.', '.'}, // I
    {'.', '-', '-', '-', '-', '.'}, // J
    {'-', '.', '-', '-', '.', '.'}, // K
    {'.', '-', '.', '.', '.', '.'}, // L
    {'-', '-', '-', '.', '.', '.'}, // M
    {'-', '-', '.', '.', '.', '.'}, // N
    {'-', '-', '-', '-', '.', '.'}, // O
    {'.', '-', '-', '-', '-', '.'}, // P
    {'-', '-', '.', '-', '-', '.'}, // Q
    {'.', '-', '.', '.', '.', '.'}, // R
    {'.', '.', '.', '.', '.', '.'}, // S
    {'-', '.', '.', '.', '.', '.'}, // T
    {'.', '.', '-', '.', '.', '.'}, // U
    {'.', '.', '.', '-', '-', '.'}, // V
    {'.', '-', '-', '-', '.', '.'}, // W
    {'-', '.', '.', '-', '.', '.'}, // X
    {'-', '-', '.', '-', '-', '.'}, // Y
    {'-', '-', '-', '-', '.', '.'} // Z
};

// Convert a character to Morse code
void char_to_morse(char c, char *morse)
{
    int i;

    // Find the character in the Morse code table
    for (i = 0; i < 26; i++) {
        if (c == 'a' + i || c == 'A' + i) {
            strcpy(morse, morse_table[i]);
            return;
        }
    }

    // Character not found
    strcpy(morse, "");
}

// Convert a string to Morse code
void string_to_morse(char *string, char *morse)
{
    int i;

    // Convert each character to Morse code
    for (i = 0; string[i] != '\0'; i++) {
        char_to_morse(string[i], &morse[i * 6]);
    }
}

// Print the Morse code representation of a string
void print_morse(char *morse)
{
    int i;

    // Print each character in the Morse code representation
    for (i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            printf(".");
        } else if (morse[i] == '-') {
            printf("-");
        } else {
            printf(" ");
        }
    }

    printf("\n");
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the user has provided a string to convert
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Convert the string to Morse code
    char morse[strlen(argv[1]) * 6 + 1];
    string_to_morse(argv[1], morse);

    // Print the Morse code representation of the string
    print_morse(morse);

    return 0;
}