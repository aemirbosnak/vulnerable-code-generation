//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DASH     "-"
#define DOT      "."
#define SPACE    "/"
#define MORSE_LEN 26

char *morse[] = {
    ".----", // A
    "..---", // B
    "...--", // C
    "....-", // D
    ".....", // E
    "-....", // F
    "--...", // G
    "---..", // H
    "----.", // I
    "-----", // J
    ".--.--", // K
    "--.-.", // L
    ".-..", // M
    "--", // N
    "-.", // O
    "---", // P
    ".--.", // Q
    "--.-", // R
    ".-.", // S
    "...", // T
    "-", // U
    "..-", // V
    "...-", // W
    ".--", // X
    "--.."  // Y, Z is same as Y
};

int main(int argc, char **argv) {
    int i, j;
    char text[81];

    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    strcpy(text, argv[1]);

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            printf("%s ", morse[toupper(text[i]) - 'A']);
        } else if (text[i] == ' ') {
            printf("%s\n", SPACE);
        } else {
            printf("Invalid character '%c'\n", text[i]);
            return 1;
        }
    }

    for (i = 0; i < MORSE_LEN; i++) {
        for (j = 0; morse[i][j] != '\0'; j++) {
            putchar(morse[i][j] == DOT ? '.' : '-');
            fflush(stdout);
            usleep(morse[i][j] == DOT ? 100 : 300);
        }
        putchar(' ');
        fflush(stdout);
        usleep(700);
    }

    return 0;
}