//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", "|", " "
};

// Convert a character to Morse code
char *charToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morseCodeTable[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morseCodeTable[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morseCodeTable[c - '0' + 26];
    } else if (c == ' ') {
        return morseCodeTable[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *stringToMorse(char *str) {
    int len = strlen(str);
    char *morseCode = malloc(len * 5);  // Allocate enough space for the Morse code
    morseCode[0] = '\0';  // Initialize the Morse code string

    for (int i = 0; i < len; i++) {
        char *morse = charToMorse(str[i]);
        if (morse != NULL) {
            strcat(morseCode, morse);  // Append the Morse code to the Morse code string
            strcat(morseCode, " ");   // Add a space between each Morse code character
        }
    }

    return morseCode;
}

// Print the Morse code
void printMorseCode(char *morseCode) {
    printf("%s", morseCode);
}

// Main function
int main() {
    char *str = "Hello, world!";
    char *morseCode = stringToMorse(str);
    printMorseCode(morseCode);

    return 0;
}