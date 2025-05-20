//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Morse code dictionary
const char *morseCode[] = {
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
    "--..", // Y
    "-----" // Z
};

typedef struct {
    char c;
    int len;
} CharCode;

// Function to print Morse code for a given character
void printMorseCode(const char *morseCodeStr) {
    for (int i = 0; i < strlen(morseCodeStr); i++) {
        if (morseCodeStr[i] == '.') {
            printf(" . ");
            usleep(500000); // Dot duration
        } else if (morseCodeStr[i] == '-') {
            printf(" - ");
            usleep(1000000); // Dash duration
        }
    }
    printf(" "); // Space duration
}

// Function to process input text and print Morse code
void processText(const char *inputText) {
    for (int i = 0; i < strlen(inputText); i++) {
        if (isalnum(inputText[i])) {
            const char *morseCodeStr = morseCode[inputText[i] - 'A'];
            printMorseCode(morseCodeStr);
        } else if (inputText[i] == ' ') {
            printf("   "); // Space between words
        } else if (inputText[i] == '\n') {
            printf("\n"); // Newline character
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input-text>\n", argv[0]);
        return 1;
    }

    processText(argv[1]);

    return 0;
}