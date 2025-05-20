//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    char *morse;
} LetterToMorse;

LetterToMorse alphabet[] = {
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
    {' ', "  "}
};

const int num_letters = sizeof(alphabet) / sizeof(LetterToMorse);

char *text_to_morse(char *text) {
    char *morse = malloc(strlen(text) * 5);  // Allocate enough space for the morse code
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < num_letters; j++) {
            if (text[i] == alphabet[j].letter) {
                strcat(morse, alphabet[j].morse);
                break;
            }
        }
        strcat(morse, " ");  // Add a space between each letter
    }
    return morse;
}

int main() {
    char *text = "Hello, world!";
    char *morse = text_to_morse(text);
    printf("Text: %s\nMorse code: %s\n", text, morse);
    free(morse);
    return 0;
}