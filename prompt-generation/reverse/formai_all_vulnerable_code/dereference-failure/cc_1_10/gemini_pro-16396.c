//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
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

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return (char *)morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return (char *)morse_table[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_str(char *str) {
    int len = strlen(str);
    char *morse_str = malloc(len * 5 + 1); // Each character can be up to 5 Morse code units long, plus spaces
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *morse_char = to_morse(str[i]);
        if (morse_char != NULL) {
            strcpy(morse_str + j, morse_char);
            j += strlen(morse_char);
            morse_str[j++] = ' ';
        }
    }
    morse_str[j] = '\0';
    return morse_str;
}

int main() {
    // Get the text to convert
    char text[101];
    printf("Enter the text to convert to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char *morse_str = to_morse_str(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_str);

    // Free the allocated memory
    free(morse_str);

    return 0;
}