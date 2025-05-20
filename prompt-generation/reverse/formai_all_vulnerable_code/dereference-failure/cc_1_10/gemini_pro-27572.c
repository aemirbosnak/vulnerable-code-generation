//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morseCode[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-"
};

// Function to convert a character to Morse code
char *textToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morseCode[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morseCode[c - 'A'];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *stringToMorse(char *str) {
    char *morseCodeString = malloc(strlen(str) * 5);
    for (int i = 0; i < strlen(str); i++) {
        char *morseCodeChar = textToMorse(str[i]);
        if (morseCodeChar != NULL) {
            strcat(morseCodeString, morseCodeChar);
            strcat(morseCodeString, " ");
        }
    }
    return morseCodeString;
}

// Function to print a string in Morse code
void printMorseCode(char *morseCodeString) {
    for (int i = 0; i < strlen(morseCodeString); i++) {
        if (morseCodeString[i] == '.') {
            printf("· ");
        } else if (morseCodeString[i] == '-') {
            printf("- ");
        } else if (morseCodeString[i] == ' ') {
            printf("   ");
        }
    }
    printf("\n");
}

int main() {
    char *str = "THANK YOU";
    char *morseCodeString = stringToMorse(str);
    printf("Original string: %s\n", str);
    printf("Morse code: ");
    printMorseCode(morseCodeString);
    free(morseCodeString);
    return 0;
}