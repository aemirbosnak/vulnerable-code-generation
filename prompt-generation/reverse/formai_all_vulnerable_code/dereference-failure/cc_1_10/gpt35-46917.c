//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_MORSE_CODE_LENGTH 20

/* Define morse code mappings */
const char *morseCodeMappings[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

/* Define corresponding character mappings */
const char *characterMappings[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

/* Convert a character to morse code */
char *charToMorseCode(char c) {
    /* Find index of character */
    int index = -1;
    for (int i = 0; i < 36; i++) {
        if (characterMappings[i][0] == c) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        /* Character not in mappings, return NULL */
        return NULL;
    }

    /* Return corresponding morse code */
    return (char *) morseCodeMappings[index];
}

/* Convert a string to morse code */
char *stringToMorseCode(char *string) {
    /* Allocate memory for morse code string */
    char *morseCode = calloc(MAX_INPUT_LENGTH * MAX_MORSE_CODE_LENGTH, sizeof(char));

    /* Loop through characters in string and convert to morse code */
    for (int i = 0; i < strlen(string); i++) {
        char *c = charToMorseCode(string[i]);
        if (c == NULL) {
            /* Character not in mappings, return NULL */
            free(morseCode);
            return NULL;
        }
        strcat(morseCode, c);
        strcat(morseCode, " ");
    }

    /* Return morse code string */
    return morseCode;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string to convert to morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Remove newline character from input */
    input[strcspn(input, "\n")] = 0;

    /* Convert input string to morse code */
    char *morseCode = stringToMorseCode(input);

    if (morseCode == NULL) {
        printf("Invalid input, could not convert to morse code.\n");
        return 1;
    }

    printf("Input: %s\n", input);
    printf("Morse code: %s\n", morseCode);

    /* Free memory allocated for morse code */
    free(morseCode);

    return 0;
}