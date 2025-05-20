//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character table
char *morse_table[] = {
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
    " ",     // space
};

// Convert a single character to Morse code
char *to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return morse_table[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_string(char *str) {
    int len = strlen(str);
    char *morse_str = malloc(len * 5 + 1); // 5 characters per character plus 1 for null terminator
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *morse = to_morse(str[i]);
        if (morse != NULL) {
            strcpy(morse_str + j, morse);
            j += strlen(morse);
            morse_str[j++] = ' ';
        }
    }
    morse_str[j] = '\0';
    return morse_str;
}

// Print Morse code
void print_morse(char *morse) {
    int len = strlen(morse);
    int i;
    for (i = 0; i < len; i++) {
        if (morse[i] == '.') {
            printf("·");
        } else if (morse[i] == '-') {
            printf("—");
        } else if (morse[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char *str = "Hello, world!";
    char *morse_str = to_morse_string(str);
    printf("Original string: %s\n", str);
    printf("Morse code: ");
    print_morse(morse_str);
    free(morse_str);
    return 0;
}