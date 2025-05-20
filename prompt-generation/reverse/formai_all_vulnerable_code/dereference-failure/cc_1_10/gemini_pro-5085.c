//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse code table
char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", "-.", "---", ".--.-", ".-.-", "-..-.",
    "--..--", "..."
};

// Function to convert a character to Morse code
char *charToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morseCodeTable[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morseCodeTable[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morseCodeTable[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "?";
    }
}

// Function to convert a string to Morse code
char *stringToMorse(char *str) {
    int len = strlen(str);
    char *morseCode = malloc((len * 5) + 1); // Allocate enough space for the Morse code
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = charToMorse(str[i]);
        strcat(morseCode, morse);
        strcat(morseCode, " ");
        index += strlen(morse) + 1;
    }
    morseCode[index - 1] = '\0'; // Remove the trailing space
    return morseCode;
}

// Function to print Morse code in a dynamic style
void printMorseCode(char *morseCode) {
    int len = strlen(morseCode);
    for (int i = 0; i < len; i++) {
        if (morseCode[i] == '.') {
            printf("滴 ");
        } else if (morseCode[i] == '-') {
            printf("嗒 ");
        } else if (morseCode[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Get the text to convert from the user
    char text[100];
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morseCode = stringToMorse(text);

    // Print the Morse code in a dynamic style
    printMorseCode(morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}