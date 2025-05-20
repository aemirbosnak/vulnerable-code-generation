//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
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
    " ",    // space
};

// Recursively convert a character to Morse code
char *to_morse(char c) {
    if (c == '\0') {
        return "";
    } else {
        int index = c - 'A';
        if (index >= 0 && index < 26) {
            return strcat(morse_table[index], to_morse(c + 1));
        } else if (index == 26) {
            return " ";
        } else {
            return to_morse(c + 1);
        }
    }
}

// Print the Morse code for a string
void print_morse(char *str) {
    if (*str == '\0') {
        printf("\n");
    } else {
        printf("%s ", to_morse(*str));
        print_morse(str + 1);
    }
}

int main() {
    char str[] = "HELLO WORLD";
    printf("Text: %s\n", str);
    printf("Morse code: ");
    print_morse(str);
    return 0;
}