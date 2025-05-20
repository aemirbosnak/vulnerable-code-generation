//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct morse {
    char letter;
    char *code;
};

// Morse code table
struct morse morse_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"},
    {' ', " "}
};

// Function to convert a character to Morse code
char *to_morse(char letter) {
    for (size_t i = 0; i < sizeof(morse_table) / sizeof(morse_table[0]); i++) {
        if (morse_table[i].letter == letter) {
            return morse_table[i].code;
        }
    }
    return NULL;
}

// Function to convert a text to Morse code
char *text_to_morse(const char *text) {
    char *morse_text = malloc(1);
    morse_text[0] = '\0';

    for (size_t i = 0; text[i] != '\0'; i++) {
        char *code = to_morse(text[i]);
        if (code) {
            size_t new_len = strlen(morse_text) + strlen(code) + 2;
            morse_text = realloc(morse_text, new_len);
            strcat(morse_text, code);
            strcat(morse_text, " ");
        }
    }

    return morse_text;
}

int main() {
    // Let's say we want to convert "Hello, World!" to Morse code
    const char *text = "Hello, World!";
    char *morse_text = text_to_morse(text);

    // And now, let's flaunt our Morse code masterpiece!
    printf("Original text: %s\n", text);
    printf("Morse code: %s\n", morse_text);

    free(morse_text);
    return 0;
}