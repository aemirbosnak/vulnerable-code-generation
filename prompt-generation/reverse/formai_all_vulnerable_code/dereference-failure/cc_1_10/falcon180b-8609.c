//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 32

typedef struct {
    char *code;
    int length;
} MorseCode;

MorseCode morse_codes[] = {
    {"A", 1},
    {"B", 2},
    {"C", 3},
    {"D", 4},
    {"E", 5},
    {"F", 6},
    {"G", 7},
    {"H", 8},
    {"I", 2},
    {"J", 3},
    {"K", 5},
    {"L", 4},
    {"M", 2},
    {"N", 6},
    {"O", 3},
    {"P", 5},
    {"Q", 8},
    {"R", 3},
    {"S", 3},
    {"T", 1},
    {"U", 4},
    {"V", 6},
    {"W", 9},
    {"X", 6},
    {"Y", 3},
    {"Z", 7},
    {"0", 5},
    {"1", 2},
    {"2", 5},
    {"3", 5},
    {"4", 4},
    {"5", 4},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9}
};

int main() {
    char *text = "Hello, World!";
    int i, j, k;
    char morse_code[MAX_CODE_LENGTH];
    char *p;

    printf("Text: %s\n", text);

    // Convert text to uppercase
    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
        }
    }

    // Remove spaces and punctuation
    p = strtok(text, ".,!?-");
    while (p) {
        j = 0;
        k = 0;
        while (morse_codes[j].code) {
            if (strcmp(p, morse_codes[j].code) == 0) {
                strncpy(morse_code, morse_codes[j].code, MAX_CODE_LENGTH);
                k = morse_codes[j].length;
                break;
            }
            j++;
        }
        if (k > 0) {
            printf("%s ", morse_code);
        }
        p = strtok(NULL, ".,!?-");
    }

    printf("\n");

    return 0;
}