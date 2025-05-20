//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 26
#define DASH_LENGTH 3
#define DOT_LENGTH 1

char morse[][LENGTH] = {
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

void printMorse(char morseCode[DASH_LENGTH + DOT_LENGTH + 1]) {
    int i;
    for (i = 0; i < strlen(morseCode); i++) {
        if (morseCode[i] == '.')
            printf(" %c", '.');
        else if (morseCode[i] == '-')
            printf(" %c", '_');
        if (i < strlen(morseCode) - 1)
            printf(" ");
    }
}

bool isAlphanumeric(char c) {
    return (isalpha(c) || isdigit(c));
}

int main() {
    char text[101], morseOutput[101][DASH_LENGTH + DOT_LENGTH + 1];
    int i, j, length;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0, length = 0; i < strlen(text); i++) {
        if (isAlphanumeric(text[i])) {
            strcpy(morseOutput[length], morse[text[i] - 'A']);
            length++;
        }
    }

    printf("\nMorse Code Output:\n");
    for (i = 0; i < length; i++) {
        printf("%s ", morseOutput[i]);
    }

    printf("\n");
    printMorse("");

    return 0;
}