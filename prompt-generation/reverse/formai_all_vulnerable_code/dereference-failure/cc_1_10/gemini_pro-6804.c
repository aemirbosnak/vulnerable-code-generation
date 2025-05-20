//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char morse_table[][8] = {
    {'.', '-', '-', '-', '-', '.', '.', '.'}, // A
    {'-', '.', '.', '.', '-', '.', '.', '.'}, // B
    {'-', '.', '-', '.', '-', '.', '.', '.'}, // C
    {'-', '.', '.', '.', '.', '-', '.', '.'}, // D
    {'.', '.', '.', '.', '.', '.', '.', '.'}, // E
    {'.', '.', '-', '.', '-', '.', '.', '.'}, // F
    {'-', '-', '.', '.', '-', '.', '.', '.'}, // G
    {'.', '.', '.', '.', '-', '.', '.', '.'}, // H
    {'.', '.', '.', '.', '.', '.', '-', '.'}, // I
    {'.', '-', '-', '-', '-', '.', '.', '.'}, // J
    {'-', '.', '-', '-', '.', '.', '.', '.'}, // K
    {'.', '-', '.', '.', '.', '-', '.', '.'}, // L
    {'-', '-', '.', '.', '.', '.', '.', '.'}, // M
    {'-', '-', '-', '.', '.', '.', '.', '.'}, // N
    {'-', '-', '-', '-', '-', '.', '.', '.'}, // O
    {'.', '-', '-', '-', '.', '.', '.', '.'}, // P
    {'-', '-', '.', '-', '-', '.', '.', '.'}, // Q
    {'.', '-', '.', '.', '-', '.', '.', '.'}, // R
    {'.', '.', '.', '.', '.', '.', '.', '.'}, // S
    {'-', '.', '.', '.', '.', '.', '.', '.'}, // T
    {'.', '.', '.', '.', '.', '.', '-', '.'}, // U
    {'.', '.', '.', '.', '.', '-', '-', '.'}, // V
    {'.', '-', '-', '.', '.', '.', '.', '.'}, // W
    {'-', '.', '.', '.', '-', '.', '.', '.'}, // X
    {'-', '-', '.', '.', '-', '.', '.', '.'}, // Y
    {'-', '-', '-', '.', '.', '.', '.', '.'} // Z
};

// Function to convert a character to Morse code
void char_to_morse(char character, char *morse_code) {
    // Get the index of the character in the Morse code table
    int index = character - 'A';

    // Copy the Morse code for the character to the output buffer
    strcpy(morse_code, morse_table[index]);
}

// Function to convert a string to Morse code
void string_to_morse(char *string, char *morse_code) {
    // Loop through each character in the string
    while (*string) {
        // Convert the character to Morse code
        char_to_morse(*string, morse_code);

        // Append the Morse code to the output buffer
        strcat(morse_code, " ");

        // Increment the pointer to the next character in the string
        string++;
    }
}

// Main function
int main() {
    // Get the input string from the user
    char string[100];
    printf("Enter a string to convert to Morse code: ");
    gets(string);

    // Convert the string to Morse code
    char morse_code[500];
    string_to_morse(string, morse_code);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    return 0;
}