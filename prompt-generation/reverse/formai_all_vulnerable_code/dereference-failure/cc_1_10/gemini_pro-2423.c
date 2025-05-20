//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character representation
char morse_code[26][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "...", ".-", ".-..", "--", "-.",
    "-.-", "-..", ".", "..-", "...", ".-.-", "..", "---", ".--.", "--.-", ".-.-", "...",
    "-", "-..-", "-.--", "--.."
};

// Convert a character to its Morse code representation
char *text_to_morse(char character) {
    // Check if the character is a letter
    if (character >= 'a' && character <= 'z') {
        // Convert the character to uppercase
        character -= 32;
    }

    // Check if the character is a number
    else if (character >= '0' && character <= '9') {
        // Convert the character to its Morse code representation
        return morse_code[character - '0'];
    }

    // Check if the character is a valid character
    else {
        // Return an empty string
        return "";
    }

    // Return the Morse code representation of the character
    return morse_code[character - 'A'];
}

// Convert a string to its Morse code representation
char *text_to_morse_string(char *text) {
    // Allocate memory for the Morse code representation
    char *morse_code_string = malloc(strlen(text) * 6 + 1);

    // Convert each character to its Morse code representation
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        char *character_morse_code = text_to_morse(text[i]);
        int length = strlen(character_morse_code);
        for (j = 0; j < length; j++) {
            morse_code_string[j + i * 6] = character_morse_code[j];
        }
        morse_code_string[j + i * 6] = ' ';
        i++;
    }

    // Add a null terminator to the end of the Morse code representation
    morse_code_string[i * 6] = '\0';

    // Return the Morse code representation
    return morse_code_string;
}

// Print a string in Morse code
void print_morse_code(char *morse_code) {
    // Print each character in the Morse code representation
    int i = 0;
    while (morse_code[i] != '\0') {
        if (morse_code[i] == '.') {
            printf(".");
        } else if (morse_code[i] == '-') {
            printf("-");
        } else {
            printf(" ");
        }
        i++;
    }

    // Print a newline character
    printf("\n");
}

int main() {
    // Get the text to convert to Morse code
    char text[100];
    printf("Enter the text to convert to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char *morse_code_string = text_to_morse_string(text);

    // Print the Morse code representation
    printf("The Morse code representation of the text is: ");
    print_morse_code(morse_code_string);

    // Free the memory allocated for the Morse code representation
    free(morse_code_string);

    return 0;
}