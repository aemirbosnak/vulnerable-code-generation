//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet
char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to its Morse code representation
char *charToMorse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse[c - 'a'];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Convert a string to its Morse code representation
char *stringToMorse(char *str) {
    char *morseCode = malloc(strlen(str) * 5); // Allocate enough space for the Morse code representation
    int i;
    for (i = 0; i < strlen(str); i++) {
        char *c = charToMorse(str[i]);
        if (c != NULL) {
            strcat(morseCode, c);
        }
    }
    return morseCode;
}

// Print the Morse code representation of a string
void printMorseCode(char *morseCode) {
    int i;
    for (i = 0; i < strlen(morseCode); i++) {
        printf("%c", morseCode[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char *str = "Hello, world!";
    char *morseCode = stringToMorse(str);
    printMorseCode(morseCode);
    return 0;
}