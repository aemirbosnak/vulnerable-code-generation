//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MORSE_CODE_LENGTH 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char morse[MAX_MORSE_CODE_LENGTH];
    char *word;
} MorseCodeTable;

MorseCodeTable morseTable[] = {
    {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."},
    {"F", "..-."}, {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"},
    {"K", "-.-"}, {"L", ".-.."}, {"M", "--"}, {"N", "-."}, {"O", "---"},
    {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"},
    {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"}, {"Y", "-.--"},
    {"Z", "--.."}, {"1", ".----"}, {"2", "..---"}, {"3", "...--"}, {"4", "....-"},
    {"5", "....."}, {"6", "-...."}, {"7", "--..."}, {"8", "---.."}, {"9", "----."},
    {"0", "-----"}
};

int main(int argc, char *argv[]) {
    char text[MAX_WORD_LENGTH];
    char morseCode[MAX_MORSE_CODE_LENGTH];
    MorseCodeTable *morseCodeTable;
    int i, j, k;

    printf("Welcome to the Medieval Text to Morse Code Converter!\n");
    printf("Enter your text to be converted: ");
    fgets(text, MAX_WORD_LENGTH, stdin);

    printf("Converting to Morse Code...\n");

    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    for (i = 0; i < strlen(text); i++) {
        morseCodeTable = NULL;
        for (j = 0; j < sizeof(morseTable)/sizeof(morseTable[0]); j++) {
            if (strcmp(morseTable[j].word, text[i]) == 0) {
                morseCodeTable = &morseTable[j];
                break;
            }
        }

        if (morseCodeTable!= NULL) {
            strcat(morseCode, morseCodeTable->morse);
        } else {
            strcat(morseCode, " ");
        }
    }

    printf("Your text in Morse Code: %s\n", morseCode);

    return 0;
}