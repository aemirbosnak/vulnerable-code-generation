//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--",
    "---.", "-...-", "-.--.", "-.--.-", ".-.-.-", "..-..-", "---...", ".----", "..-...", "---..",
    ".----.", ".-.-.-", "..--.-", ".-..-.", ".-...-", ".-.--.", "-....-", "-.-..-", "-.--.-.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    // Check if the character is in the alphabet
    if (c >= 'a' && c <= 'z') {
        c -= 'a' - 'A'; // Convert to uppercase
    }
    if (c < 'A' || c > 'Z') {
        return ""; // Invalid character
    }

    // Return the Morse code for the character
    return (char *)morse_table[c - 'A'];
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse = malloc(strlen(str) * 5 + 1); // 5 characters per character + 1 for null-termination

    // Convert each character to Morse code
    int i = 0;
    while (str[i] != '\0') {
        strcat(morse, char_to_morse(str[i]));
        strcat(morse, " "); // Add a space between characters
        i++;
    }

    // Return the Morse code string
    return morse;
}

// Print the Morse code for a string
void print_morse(char *morse) {
    // Print each character in the Morse code string
    int i = 0;
    while (morse[i] != '\0') {
        printf("%c", morse[i]);
        i++;
    }

    // Print a newline
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a string to convert
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Convert the string to Morse code
    char *morse = string_to_morse(argv[1]);

    // Print the Morse code
    print_morse(morse);

    // Free the memory allocated for the Morse code string
    free(morse);

    return 0;
}