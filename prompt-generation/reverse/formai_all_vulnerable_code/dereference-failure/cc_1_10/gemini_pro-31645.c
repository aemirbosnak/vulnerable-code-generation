//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static const char *morse[] = {
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

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
static char *string_to_morse(const char *str) {
    char *morse_code = malloc(strlen(str) * 5 + 1);
    int i;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        char *c_morse = char_to_morse(str[i]);
        if (c_morse != NULL) {
            strcpy(&morse_code[j], c_morse);
            j += strlen(c_morse);
            morse_code[j++] = ' ';
        }
    }

    morse_code[j] = '\0';
    return morse_code;
}

// Print Morse code
static void print_morse(const char *morse_code) {
    int i;

    for (i = 0; morse_code[i] != '\0'; i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf(".");
        } else if (morse_code[i] == '-') {
            printf("-");
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *morse_code = string_to_morse(argv[1]);
    print_morse(morse_code);

    free(morse_code);

    return 0;
}