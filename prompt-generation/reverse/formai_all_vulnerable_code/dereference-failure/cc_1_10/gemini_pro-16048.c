//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct Morse {
    char letter;
    char code[6];
} Morse;

Morse morse_table[] = {
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

char *to_morse(char *text) {
    int i, j, k;
    char *morse_code = malloc(MAX_LEN * sizeof(char));
    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < sizeof(morse_table) / sizeof(Morse); j++) {
            if (text[i] == morse_table[j].letter) {
                strcat(morse_code, morse_table[j].code);
                strcat(morse_code, " ");
                break;
            }
        }
    }
    return morse_code;
}

int main() {
    char text[MAX_LEN];
    printf("Enter a text to convert to Morse code: ");
    fgets(text, MAX_LEN, stdin);
    char *morse_code = to_morse(text);
    printf("Morse code: %s\n", morse_code);
    free(morse_code);
    return 0;
}