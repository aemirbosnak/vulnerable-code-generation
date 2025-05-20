//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MORSE_CODE_LENGTH 26
const char morseCode[MORSE_CODE_LENGTH][4] = {
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
    "--.." // Y
};

void printMorseCode(const char *text) {
    const char *word = strtok(text, " ");

    while (word != NULL) {
        int i;
        for (i = 0; i < MORSE_CODE_LENGTH; i++) {
            if (strcmp(word, morseCode[i]) == 0) {
                printf("%s\n", morseCode[i]);
                break;
            }
        }

        if (i == MORSE_CODE_LENGTH) {
            printf("Error: Unknown text: %s\n", word);
        }

        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    printf("Shocked Text to Morse Code Converter:\n");
    printf("----------------------------------------\n");
    printf("Text: %s\n", argv[1]);

    printf("\n");

    printMorseCode(argv[1]);

    printf("\n");
    printf("I can't believe you entered that text!\n");
    printf("----------------------------------------\n");

    return 0;
}