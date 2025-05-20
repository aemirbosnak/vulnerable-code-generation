//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code table
const char morseCodeTable[][3] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

// Function to convert a character to Morse code
void charToMorseCode(char c, char morseCode[32]) {
    int index = (int)tolower(c) - 'a';

    if (index < 0 || index > 25) { // If character is not a letter
        switch (c) {
            case ' ': // Space
                strcpy(morseCode, "/");
                break;
            case '\0': // End of string
                morseCode[0] = '\0';
                break;
            default: // Other characters
                strcpy(morseCode, "");
                printf("Invalid character: %c\n", c);
                exit(EXIT_FAILURE);
        }

        return;
    }

    strcpy(morseCode, morseCodeTable[index]);
}

// Function to print Morse code
void printMorseCode(char morseCode[32]) {
    if (morseCode[0] == '\0') { // If Morse code is empty
        return;
    }

    int i = 0;
    while (morseCode[i] != '\0') {
        if (morseCode[i] == '.') {
            printf("._");
            i++;
            continue;
        }

        if (morseCode[i] == '-') {
            printf("_.");
            i++;
            continue;
        }

        if (morseCode[i] == '/') { // Space
            printf("/ ");
            i += 2;
            continue;
        }

        printf("Error: Invalid Morse code character %c\n", morseCode[i]);
        exit(EXIT_FAILURE);
    }
}

// Function to convert a string to Morse code
void stringToMorseCode(char input[100], char output[32][32], int *length) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        char morseCode[32] = {0};
        charToMorseCode(input[i], morseCode);
        strcpy(output[j], morseCode);
        j++;
        i++;
    }

    *length = j;
}

int main() {
    char input[100] = "HELLO WORLD";
    char output[32][32] = {0};
    int length = 0;

    stringToMorseCode(input, output, &length);

    for (int i = 0; i < length; i++) {
        printf("%s ", output[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}