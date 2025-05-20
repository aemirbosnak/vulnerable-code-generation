//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Predefined Morse code table
const char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Array of characters that have corresponding Morse code
const char characters[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', '0', ' '
};

// Function to convert a character to its corresponding Morse code
char *char_to_morse(char character) {
    int index = 0;
    while (characters[index] != character) {
        index++;
    }
    return (char *)morse_code_table[index];
}

// Function to convert a string to Morse code
char *string_to_morse(char *string) {
    char *morse_code = (char *)malloc(sizeof(char) * 1000); // Assuming the maximum length of the Morse code is 1000 characters
    int i, j, k = 0;
    for (i = 0; string[i] != '\0'; i++) {
        char *code = char_to_morse(toupper(string[i]));
        for (j = 0; code[j] != '\0'; j++) {
            morse_code[k++] = code[j];
            morse_code[k++] = ' '; // Add a space between each character's Morse code
        }
    }
    morse_code[k] = '\0'; // Terminate the string with a null character
    return morse_code;
}

int main() {
    char string[] = "Hello World";
    char *morse_code = string_to_morse(string);
    printf("Original string: %s\n", string);
    printf("Morse code: %s\n", morse_code);
    free(morse_code); // Free the allocated memory
    return 0;
}