//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** This program will convert a given text string into Morse code */

// Morse code conversion table
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                 "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                 "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
char *alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                 "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

/**
 * Function to convert a single character into its corresponding Morse code
 * @param c The character to convert
 * @return The Morse code representation of the character
 */
char *convert(char c) {
    return morse[toupper(c) - 'A'];
}

/**
 * Function to convert an entire string into its corresponding Morse code
 * @param text The string to convert
 * @return The Morse code representation of the string
 */
char *text_to_morse(char *text) {
    char *result = malloc(strlen(text) * 5); // Maximum size of Morse code will be 5 times the size of the input string
    char code[10];
    result[0] = '\0'; // Initialize the result string with null character

    // Loop over each character in the input string and convert to Morse code
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            strcat(result, convert(text[i]));
            strcat(result, " "); // Separation between characters
        } else if (text[i] == ' ') {
            strcat(result, "/ "); // Separation between words
        }
    }

    return result;
}

int main() {
    char text[200];
    char *morse_code;

    // Get user input
    printf("Enter text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character at the end of the string
    if (text[strlen(text)-1] == '\n') {
        text[strlen(text)-1] = '\0';
    }

    // Convert the input string to Morse code
    morse_code = text_to_morse(text);

    // Print the Morse code output
    printf("Morse code: %s\n", morse_code);

    // Free dynamically allocated memory
    free(morse_code);

    return 0;
}