//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char* morsecode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to its morse code representation
char* charToMorse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morsecode[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morsecode[c - 'a'];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Function to convert a string to its morse code representation
char* stringToMorse(char* str) {
    int len = strlen(str);
    char* morseCode = malloc((len * 5 + 1) * sizeof(char));
    int i;
    int index = 0;
    for (i = 0; i < len; i++) {
        char* morse = charToMorse(str[i]);
        strcat(morseCode, morse);
        strcat(morseCode, " ");
        index += strlen(morse) + 1;
    }
    morseCode[index - 1] = '\0';
    return morseCode;
}

// Function to print the morse code representation of a string
void printMorseCode(char* morseCode) {
    printf("%s\n", morseCode);
}

// Main function
int main() {
    char* str = "Hello World";
    char* morseCode = stringToMorse(str);
    printMorseCode(morseCode);
    return 0;
}