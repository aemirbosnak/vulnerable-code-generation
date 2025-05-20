//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    char *morse;
} TextMorsePair;

TextMorsePair pairs[] = {
    {"A", ".-"},
    {"B", "-..."},
    {"C", "-.-."},
    {"D", "-.."},
    {"E", "."},
    {"F", "..-."},
    {"G", "--."},
    {"H", "...."},
    {"I", ".."},
    {"J", ".---"},
    {"K", "-.-"},
    {"L", ".-.."},
    {"M", "--"},
    {"N", "-."},
    {"O", "---"},
    {"P", ".--."},
    {"Q", "--.-"},
    {"R", ".-."},
    {"S", "..."},
    {"T", "-"},
    {"U", "..-"},
    {"V", "...-"},
    {"W", ".--"},
    {"X", "-..-"},
    {"Y", "-.--"},
    {"Z", "--.."},
    {"0", "-----"},
    {"1", ".----"},
    {"2", "..---"},
    {"3", "...--"},
    {"4", "....-"},
    {"5", "....."},
    {"6", "-...."},
    {"7", "--..."},
    {"8", "---.."},
    {"9", "----."},
    {" ", " "},
};

char *toMorse(char *text) {
    char *morse = malloc(strlen(text) * 4 + 1);
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < sizeof(pairs) / sizeof(TextMorsePair); j++) {
            if (text[i] == pairs[j].text[0]) {
                strcat(morse, pairs[j].morse);
                break;
            }
        }
        if (j == sizeof(pairs) / sizeof(TextMorsePair)) {
            morse[i] = text[i];
        }
    }
    return morse;
}

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    char *morse = toMorse(text);
    printf("Morse code: %s\n", morse);
    free(morse);
    return 0;
}