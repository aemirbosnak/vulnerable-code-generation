//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code dictionary
const char *morse_code[] = {
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
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = toupper(c) - 'A';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Allocate enough space for the Morse code, assuming each character takes up to 5 characters
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        strcat(morse_code, morse);
        strcat(morse_code, " ");
        index += strlen(morse) + 1;
    }
    morse_code[index - 1] = '\0'; // Remove the trailing space
    return morse_code;
}

// Print the Morse code representation of a string
void print_morse_code(char *str) {
    char *morse_code = string_to_morse(str);
    printf("%s\n", morse_code);
    free(morse_code);
}

int main() {
    char *str = "HELLO WORLD";
    print_morse_code(str);
    return 0;
}