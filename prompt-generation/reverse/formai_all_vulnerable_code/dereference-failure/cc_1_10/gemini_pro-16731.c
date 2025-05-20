//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    char* morse;
} LetterMorse;

LetterMorse letterMorseTable[] = {
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

char* textToMorse(char* text) {
    int textLength = strlen(text);
    char* morseCode = malloc(textLength * 5); // Assuming each character can be represented by at most 5 morse code units
    int morseCodeLength = 0;

    for (int i = 0; i < textLength; i++) {
        char letter = text[i];
        char* morse = NULL;

        for (int j = 0; j < sizeof(letterMorseTable) / sizeof(LetterMorse); j++) {
            if (letterMorseTable[j].letter == letter) {
                morse = letterMorseTable[j].morse;
                break;
            }
        }

        if (morse != NULL) {
            strcat(morseCode, morse);
            morseCodeLength += strlen(morse);
        }
    }

    return morseCode;
}

int main() {
    char* text = "HELLO WORLD";
    char* morseCode = textToMorse(text);

    printf("Original text: %s\n", text);
    printf("Morse code: %s\n", morseCode);

    free(morseCode);

    return 0;
}