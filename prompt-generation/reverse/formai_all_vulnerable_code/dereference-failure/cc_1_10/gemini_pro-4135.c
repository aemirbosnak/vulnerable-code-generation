//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MORSE_CODE_LENGTH 50

typedef struct {
    char letter;
    char *morse_code;
} morse_code_entry;

morse_code_entry morse_code_table[] = {
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    char morse_code[MAX_MORSE_CODE_LENGTH];
    int i, j;

    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < sizeof(morse_code_table) / sizeof(morse_code_entry); j++) {
            if (text[i] == morse_code_table[j].letter) {
                strcat(morse_code, morse_code_table[j].morse_code);
                break;
            }
        }

        if (j == sizeof(morse_code_table) / sizeof(morse_code_entry)) {
            fprintf(stderr, "Error: Invalid character '%c' in text\n", text[i]);
            return EXIT_FAILURE;
        }
    }

    printf("%s\n", morse_code);

    return EXIT_SUCCESS;
}