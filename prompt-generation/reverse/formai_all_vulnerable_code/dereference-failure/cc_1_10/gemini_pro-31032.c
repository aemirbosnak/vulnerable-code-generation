//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char letter;
    char *morse;
} morse_code_t;

morse_code_t morse_code[] = {
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
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', " "}
};

char *convert_to_morse(char *text) {
    char *morse_code_string = malloc(strlen(text) * 5); // Allocate enough space for the morse code string
    int morse_code_index = 0;

    for (int i = 0; i < strlen(text); i++) {
        char letter = toupper(text[i]);

        for (int j = 0; j < sizeof(morse_code) / sizeof(morse_code_t); j++) {
            if (letter == morse_code[j].letter) {
                strcat(morse_code_string, morse_code[j].morse);
                strcat(morse_code_string, " ");
                morse_code_index++;
                break;
            }
        }
    }

    return morse_code_string;
}

int main() {
    char text[] = "Hello, world!";
    char *morse_code_string = convert_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse_code_string);

    free(morse_code_string);

    return 0;
}