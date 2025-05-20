//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH_MORSE_CODE 26

char morse_code[LENGTH_MORSE_CODE][5] = {
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

void print_morse_code(char morse[]) {
    int i;
    for (i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == ' ') {
            printf(" ");
        } else {
            int j;
            for (j = 0; j < LENGTH_MORSE_CODE; j++) {
                if (strcmp(morse + i, morse_code[j]) == 0) {
                    printf("%s", morse_code[j]);
                    break;
                }
            }
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    int i, len = strlen(argv[1]);
    char text[len + 1];
    strcpy(text, argv[1]);

    for (i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    char morse[len + 1];
    strcpy(morse, "");
    int j = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            morse[j++] = ' ';
            continue;
        }

        int k;
        for (k = 0; k < LENGTH_MORSE_CODE; k++) {
            if (text[i] == (char)(k + 'A')) {
                strcat(morse, morse_code[k]);
                break;
            }
        }

        if (k == LENGTH_MORSE_CODE) {
            printf("Error: Unknown character %c in text.\n", text[i]);
            return 1;
        }

        if (i != len - 1) {
            strcat(morse, "/");
        }
    }

    print_morse_code(morse);

    return 0;
}