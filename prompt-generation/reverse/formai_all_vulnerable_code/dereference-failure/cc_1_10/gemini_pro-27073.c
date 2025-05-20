//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 512

typedef struct _morse_code {
    char character;
    char *code;
} morse_code;

morse_code morse_codes[] = {
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

char *convert_to_morse_code(char *text) {
    int text_length = strlen(text);
    char *morse_code = malloc(text_length * 5);
    int morse_code_index = 0;

    for (int i = 0; i < text_length; i++) {
        char character = text[i];
        for (int j = 0; j < sizeof(morse_codes) / sizeof(morse_code); j++) {
            if (morse_codes[j].character == character) {
                strcpy(morse_code + morse_code_index, morse_codes[j].code);
                morse_code_index += strlen(morse_codes[j].code);
                break;
            }
        }
    }

    return morse_code;
}

int main() {
    char text[MAX_LENGTH];
    char *morse_code;

    printf("Enter text to convert to Morse code: ");
    fgets(text, MAX_LENGTH, stdin);

    morse_code = convert_to_morse_code(text);

    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return 0;
}