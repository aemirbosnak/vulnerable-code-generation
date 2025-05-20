//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table.
const char *morse_table[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-.." // L
};

// Function to convert a character to Morse code.
char *char_to_morse(char c) {
    return morse_table[c - 'A'];
}

// Function to convert a string to Morse code.
char *string_to_morse(char *str) {
    char *morse = malloc(strlen(str) * 5 + 1); // Allocate enough space for the Morse code representation.
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        strcat(morse, char_to_morse(str[i]));
        strcat(morse, " "); // Add a space between each character.
    }

    return morse;
}

// Main function.
int main() {
    char str[] = "HELLO";
    char *morse;

    // Get the Morse code representation of the string.
    morse = string_to_morse(str);

    // Print the Morse code representation.
    printf("%s\n", morse);

    free(morse); // Free the memory allocated for the Morse code representation.

    return 0;
}