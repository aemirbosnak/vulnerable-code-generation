//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_TEXT_LENGTH 100
#define MAX_MORSE_CODE_LENGTH 1000
#define NUM_ALPHABETS 26

// Morse code table
char *morse_code_table[NUM_ALPHABETS] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-..-"
};

// Function to convert a character to its Morse code equivalent
char *character_to_morse_code(char character) {
    int index = character - 'A';
    if (index >= 0 && index < NUM_ALPHABETS) {
        return morse_code_table[index];
    }
    return NULL;
}

// Function to convert a text string to Morse code
char *text_to_morse_code(char *text) {
    int text_length = strlen(text);
    char *morse_code = malloc(MAX_MORSE_CODE_LENGTH * sizeof(char));
    morse_code[0] = '\0';

    for (int i = 0; i < text_length; i++) {
        char *morse_code_character = character_to_morse_code(text[i]);
        if (morse_code_character != NULL) {
            strcat(morse_code, morse_code_character);
        }
    }

    return morse_code;
}

// Function to print the Morse code
void print_morse_code(char *morse_code) {
    printf("Morse Code: %s\n", morse_code);
}

// Main function
int main() {
    // Get the input text from the user
    char text[MAX_TEXT_LENGTH];
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse_code = text_to_morse_code(text);

    // Print the Morse code
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}