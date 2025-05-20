//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Constants to represent Morse code mappings
#define ALPHABET_SIZE 26
#define MORSE_CODE_TIMEOUT 300 // Delay time in milliseconds for Morse code characters

// Morse code representation for each letter and numeral
const char *morseCode[ALPHABET_SIZE + 10] = {
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
    "----."  // 9
};

void printMorseCode(char c) {
    if (isalpha(c)) {
        int index = toupper(c) - 'A';
        printf("%s ", morseCode[index]);
    } else if (isdigit(c)) {
        int index = c - '0' + ALPHABET_SIZE;
        printf("%s ", morseCode[index]);
    } else if (c == ' ') {
        printf("/ "); // Indicate space between words with a slash
    } else {
        printf("? "); // Unknown characters
    }
}

void convertToMorse(const char *input) {
    printf("Converting the following text to Morse Code: %s\n", input);
    for (size_t i = 0; i < strlen(input); i++) {
        printMorseCode(input[i]);
    }
    printf("\n");
}

int main() {
    char *inputString = NULL;
    size_t inputLength = 0;

    printf("Welcome to the Morse Code Converter!\n");
    printf("Enter the text you wish to convert (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        getline(&inputString, &inputLength, stdin);

        // Remove the new line character
        inputString[strcspn(inputString, "\n")] = 0;

        // Exit condition
        if (strcmp(inputString, "exit") == 0) {
            break;
        }

        convertToMorse(inputString);
    }

    free(inputString); // Clean up dynamically allocated memory
    return 0;
}