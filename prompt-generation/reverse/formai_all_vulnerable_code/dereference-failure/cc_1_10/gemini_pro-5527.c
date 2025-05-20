//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
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
    "-----",// 0
    ".----",// 1
    "..---",// 2
    "...--",// 3
    "....-",// 4
    ".....",// 5
    "-....",// 6
    "--...",// 7
    "---..",// 8
    "----.",// 9
    " ",    // Space
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return morse_table[35];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *code = char_to_morse(str[i]);
        if (code != NULL) {
            strcat(morse_code, code);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

int main() {
    char text[] = "Hello, World!";
    char *morse_code = string_to_morse(text);
    printf("%s\n", morse_code);
    free(morse_code);
    return 0;
}