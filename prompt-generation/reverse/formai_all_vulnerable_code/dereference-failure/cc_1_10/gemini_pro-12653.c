//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Morse code table
const char *morse_code[] = {
    ".- ", // A
    "-... ", // B
    "-.-. ", // C
    "-.. ", // D
    ". ", // E
    "..-. ", // F
    "--. ", // G
    ".... ", // H
    ".. ", // I
    ".--- ", // J
    "-.- ", // K
    ".-.. ", // L
    "-- ", // M
    "-.. ", // N
    "--- ", // O
    ".--. ", // P
    "--.- ", // Q
    ".-. ", // R
    "... ", // S
    "- ", // T
    "..- ", // U
    "...- ", // V
    ".-- ", // W
    "-..- ", // X
    "-.-- ", // Y
    "--.. "  // Z
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return (char *)morse_code[c - 'a'];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 4 + 1);
    int i;
    for (i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcat(morse_code, morse);
        }
    }
    return morse_code;
}

// Print a string in Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    int i;
    for (i = 0; i < len; i++) {
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

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);

    return 0;
}