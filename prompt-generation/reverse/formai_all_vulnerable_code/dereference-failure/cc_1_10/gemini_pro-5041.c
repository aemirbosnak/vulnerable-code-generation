//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _morse_code {
    char letter;
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
};

char *get_morse_code(char letter) {
    int i;
    for (i = 0; i < sizeof(morse_codes) / sizeof(morse_code); i++) {
        if (morse_codes[i].letter == letter) {
            return morse_codes[i].code;
        }
    }
    return NULL;
}

char *convert_to_morse_code(char *text) {
    int i;
    char *morse_code = malloc(strlen(text) * 5 + 1);
    morse_code[0] = '\0';
    for (i = 0; i < strlen(text); i++) {
        char *code = get_morse_code(text[i]);
        if (code != NULL) {
            strcat(morse_code, code);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

int main() {
    char *text = "HELLO WORLD";
    char *morse_code = convert_to_morse_code(text);
    printf("%s\n", morse_code);
    free(morse_code);
    return 0;
}