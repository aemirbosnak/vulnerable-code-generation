//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morseCodeTable[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    "-----", // 0
    " ",     // Space
};

// Convert a character to Morse code
char *charToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32; // Convert to uppercase
    }

    if (c >= 'A' && c <= 'Z') {
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
    char *morseCode = malloc(len * 5 + 1); // Allocate enough memory for the Morse code
    int index = 0;

    for (int i = 0; i < len; i++) {
        char *morse = charToMorse(str[i]);
        if (morse != NULL) {
            strcat(morseCode, morse);
            strcat(morseCode, " ");
            index += strlen(morse) + 1;
        }
    }

    morseCode[index - 1] = '\0'; // Remove the trailing space

    return morseCode;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    gets(str);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}