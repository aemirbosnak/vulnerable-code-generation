//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code table
static const char *morse_code[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-.."   // L
};

// Convert a character to Morse code
char *to_morse(char c) {
    // Convert the character to uppercase
    c = toupper(c);

    // Get the index of the character in the alphabet
    int index = c - 'A';

    // If the character is not a letter, return an empty string
    if (index < 0 || index >= 26) {
        return "";
    }

    // Return the Morse code for the character
    return morse_code[index];
}

// Convert a text string to Morse code
char *to_morse_str(char *text) {
    // Allocate memory for the Morse code string
    int len = strlen(text);
    char *morse = malloc(len * 5 + 1);

    // Convert each character in the text string to Morse code
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse, to_morse(text[i]));
        strcat(morse, " ");
    }

    // Remove the trailing space from the Morse code string
    morse[strlen(morse) - 1] = '\0';

    // Return the Morse code string
    return morse;
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided a text string
    if (argc < 2) {
        printf("Usage: %s text\n", argv[0]);
        return 1;
    }

    // Convert the text string to Morse code
    char *morse = to_morse_str(argv[1]);

    // Print the Morse code string
    printf("%s\n", morse);

    // Free the memory allocated for the Morse code string
    free(morse);

    return 0;
}