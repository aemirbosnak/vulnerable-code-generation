//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 256

typedef struct {
    char character;
    char *morse_code;
} MorseCodeMapping;

MorseCodeMapping morse_code_map[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', " "}, {'\0', "\0"}
};

void text_to_morse_code(char *text, char *morse_code) {
    int text_length = strlen(text);
    int morse_code_length = 0;

    for (int i = 0; i < text_length; i++) {
        char character = text[i];
        char *morse_code_mapping = NULL;

        for (int j = 0; morse_code_map[j].character != '\0'; j++) {
            if (morse_code_map[j].character == character) {
                morse_code_mapping = morse_code_map[j].morse_code;
                break;
            }
        }

        if (morse_code_mapping != NULL) {
            strcat(morse_code, morse_code_mapping);
            strcat(morse_code, " ");
            morse_code_length += strlen(morse_code_mapping) + 1;
        }
    }

    morse_code[morse_code_length - 1] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char text[MAX_CHAR_LENGTH];
    strcpy(text, argv[1]);

    char morse_code[MAX_CHAR_LENGTH];
    morse_code[0] = '\0';

    text_to_morse_code(text, morse_code);

    printf("%s\n", morse_code);

    return EXIT_SUCCESS;
}