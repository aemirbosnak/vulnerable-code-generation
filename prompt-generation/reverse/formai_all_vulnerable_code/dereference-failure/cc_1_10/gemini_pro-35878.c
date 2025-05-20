//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code mapping
char *morse_code[] = {
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
    "/ ",    // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return morse_code[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *c_morse = char_to_morse(str[i]);
        if (c_morse != NULL) {
            strcat(morse_code, c_morse);
            strcat(morse_code, " ");
            j++;
        }
    }
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    char *str = "Hello World";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}