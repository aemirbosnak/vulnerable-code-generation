//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    " ",     // space
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    return morse_table[c - 'A'];
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int i;
    for (i = 0; i < strlen(str); i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }
    return morse_code;
}

// Function to print Morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    char *str = "HELLO WORLD";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}