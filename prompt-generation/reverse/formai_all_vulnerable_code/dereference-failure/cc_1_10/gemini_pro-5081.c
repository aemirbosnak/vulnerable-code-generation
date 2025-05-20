//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    NULL
};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    char *morse_code = malloc(strlen(text) * 5 + 1); // Allocate memory for the Morse code representation
    char *p = morse_code; // Pointer to the beginning of the Morse code representation

    for (char *c = text; *c; c++) { // Loop through each character in the text
        if (*c >= 'A' && *c <= 'Z') { // If the character is an uppercase letter
            *p++ = morse_table[*c - 'A']; // Add the Morse code representation of the letter to the string
            *p++ = ' '; // Add a space between the letters
        } else if (*c >= 'a' && *c <= 'z') { // If the character is a lowercase letter
            *p++ = morse_table[*c - 'a' + 26]; // Add the Morse code representation of the letter to the string
            *p++ = ' '; // Add a space between the letters
        } else if (*c >= '0' && *c <= '9') { // If the character is a number
            *p++ = morse_table[*c - '0' + 52]; // Add the Morse code representation of the number to the string
            *p++ = ' '; // Add a space between the numbers
        } else if (*c == ' ') { // If the character is a space
            *p++ = ' '; // Add a space to the string
        } else { // If the character is not a letter, number, or space
            printf("Invalid character: %c\n", *c); // Print an error message
            free(morse_code); // Free the memory allocated for the Morse code representation
            return NULL; // Return NULL to indicate an error
        }
    }

    *p = '\0'; // Add a null-terminator to the end of the string

    return morse_code; // Return the Morse code representation of the text
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) { // If there is no text provided
        printf("Usage: %s <text>\n", argv[0]); // Print the usage message
        return 1; // Return 1 to indicate an error
    }

    char *text = argv[1]; // Get the text from the command line arguments
    char *morse_code = text_to_morse(text); // Convert the text to Morse code

    if (morse_code == NULL) { // If there was an error converting the text to Morse code
        return 1; // Return 1 to indicate an error
    }

    printf("Morse code: %s\n", morse_code); // Print the Morse code representation of the text

    free(morse_code); // Free the memory allocated for the Morse code representation

    return 0; // Return 0 to indicate success
}