//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_LEN 512

typedef struct morse_code {
    char c;
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
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"},
    {' ', "  "},
    {'\n', "\n"},
    {'\0', NULL}
};

char *text_to_morse(char *text) {
    char *morse = malloc(MAX_BUF_LEN);
    int i, j;
    for (i = 0, j = 0; text[i] != '\0'; i++) {
        for (j = 0; morse_codes[j].c != '\0'; j++) {
            if (text[i] == morse_codes[j].c) {
                strcat(morse, morse_codes[j].code);
                strcat(morse, " ");
                break;
            }
        }
    }
    return morse;
}

char *morse_to_text(char *morse) {
    char *text = malloc(MAX_BUF_LEN);
    int i, j;
    char *token = strtok(morse, " ");
    while (token != NULL) {
        for (j = 0; morse_codes[j].c != '\0'; j++) {
            if (strcmp(morse_codes[j].code, token) == 0) {
                strncat(text, &morse_codes[j].c, 1);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return text;
}

int main() {
    char *text = "Hello, World!";
    char *morse = text_to_morse(text);
    printf("Text: %s\nMorse: %s\n", text, morse);
    free(morse);
    char *text2 = morse_to_text(morse);
    printf("Morse: %s\nText: %s\n", morse, text2);
    free(text2);
    return 0;
}