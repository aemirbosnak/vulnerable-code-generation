//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define DOT      "_ .-"
#define DASH     "-- ... "
#define SPACE    "/"
#define MORSE_LEN 26

char *morseCode[MORSE_LEN] = {
    ".--", // A
    "--.", // B
    "...", // C
    "-.", // D
    "---", // E
    ".---", // F
    "--", // G
    "---.", // H
    ".--.--.", // I
    "--..", // J
    "..", // K
    "-.--.", // L
    "--.--", // M
    "--.-", // N
    ".-..", // O
    "--", // P
    ".--.", // Q
    "--.-.", // R
    ".-.", // S
    "...-", // T
    "-..-", // U
    "-.--", // V
    "--..--", // W
    ".--..--", // X
    "-.--.-.", // Y
    "--.-.--" // Z
};

void printMorse(const char *morseStr) {
    size_t strLen = strlen(morseStr);
    size_t i = 0;

    for (; i < strLen; ++i) {
        if (isspace(morseStr[i])) {
            printf("%s ", SPACE);
            continue;
        }

        int index = morseStr[i] - 'A';

        if (index < 0 || index >= MORSE_LEN) {
            fprintf(stderr, "Invalid character '%c' found in Morse string.\n", morseStr[i]);
            exit(EXIT_FAILURE);
        }

        printf("%s ", morseCode[index]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text to encode>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printMorse(argv[1]);
    return EXIT_SUCCESS;
}