//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct morse_char {
    char letter;
    char morse[5];
};

// Morse code alphabet
struct morse_char morse_alphabet[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'\0', ""}
};

// Convert a character to Morse code
char* char_to_morse(char letter) {
    for (int i = 0; morse_alphabet[i].letter != '\0'; i++) {
        if (morse_alphabet[i].letter == letter) {
            return morse_alphabet[i].morse;
        }
    }

    return NULL;
}

// Convert a text string to Morse code
char* text_to_morse(char* text) {
    int text_length = strlen(text);
    char* morse_code = malloc(text_length * 5);

    for (int i = 0; i < text_length; i++) {
        char* morse = char_to_morse(text[i]);

        if (morse != NULL) {
            strcat(morse_code, morse);

            // Add a space between characters
            if (i < text_length - 1) {
                strcat(morse_code, " ");
            }
        }
    }

    return morse_code;
}

int main() {
    // Get the text to be converted
    char* text = "Hello, world!";

    // Convert the text to Morse code
    char* morse_code = text_to_morse(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    return 0;
}