//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character table
char* morse_table[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
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
    " ",     // Space
};

// Convert a character to Morse code
char* char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else if (index >= 26 && index < 36) {
        return morse_table[index - 26];
    } else {
        return " ";
    }
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse = malloc(len * 5 + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        char c = str[i];
        char* morse_char = char_to_morse(c);
        strcat(morse, morse_char);
        strcat(morse, " ");
        index += strlen(morse_char) + 1;
    }
    morse[index - 1] = '\0';
    return morse;
}

// Print the Morse code representation of a string
void print_morse(char* str) {
    char* morse = string_to_morse(str);
    printf("%s\n", morse);
    free(morse);
}

int main() {
    char* str = "HELLO WORLD";
    print_morse(str);
    return 0;
}