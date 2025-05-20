//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct morse_code {
    char letter;
    char *code;
};

struct morse_code morse_codes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', " "}
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s text\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int text_len = strlen(text);

    for (int i = 0; i < text_len; i++) {
        char letter = toupper(text[i]);
        struct morse_code *code = NULL;

        for (int j = 0; j < sizeof(morse_codes) / sizeof(struct morse_code); j++) {
            if (morse_codes[j].letter == letter) {
                code = &morse_codes[j];
                break;
            }
        }

        if (code == NULL) {
            fprintf(stderr, "Invalid character: %c\n", letter);
            return 1;
        }

        printf("%s ", code->code);
    }

    printf("\n");
    return 0;
}