//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arrays to store the morse code equivalents of each character
const char *morseCodeTable[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
};

// Function to convert a character to its morse code equivalent
char *toMorseCode(char c) {
    int index = (int)c - (int)'A';

    // Check if the character is valid (A-Z, 0-9)
    if (index < 0 || index > 35) {
        return NULL;
    }

    return morseCodeTable[index];
}

// Function to convert a text string to morse code
char *textToMorseCode(char *text) {
    int textLength = strlen(text);
    int morseCodeLength = textLength * 5; // Assuming 5 characters per morse code symbol
    char *morseCode = malloc(morseCodeLength);

    memset(morseCode, 0, morseCodeLength); // Initialize the morse code string to all zeros

    int morseCodeIndex = 0;
    for (int i = 0; i < textLength; i++) {
        char *symbol = toMorseCode(text[i]);
        if (symbol != NULL) {
            strcpy(&morseCode[morseCodeIndex], symbol);
            strcat(&morseCode[morseCodeIndex], " "); // Add a space between each morse code symbol
            morseCodeIndex += strlen(symbol) + 1;
        }
    }

    return morseCode;
}

int main() {
    char text[] = "HELLO WORLD";

    char *morseCode = textToMorseCode(text);

    printf("Text: %s\n", text);
    printf("Morse Code: %s\n", morseCode);

    free(morseCode);

    return 0;
}