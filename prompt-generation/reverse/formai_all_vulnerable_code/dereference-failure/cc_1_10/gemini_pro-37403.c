//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char morse_dict[][8] = {
    ".-",    // A
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
char *char_to_morse(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (c == 'A' + i || c == 'a' + i) {
            return morse_dict[i];
        }
    }
    for (i = 0; i < 10; i++) {
        if (c == '0' + i) {
            return morse_dict[26 + i];
        }
    }
    if (c == ' ') {
        return morse_dict[36];
    }
    return NULL;
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int i, len = strlen(str);
    char *morse_str = malloc(len * 5); // Allocate enough memory for the Morse code string
    for (i = 0; i < len; i++) {
        strcat(morse_str, char_to_morse(str[i]));
        strcat(morse_str, " "); // Add a space between each character's Morse code
    }
    return morse_str;
}

int main() {
    char *str = "Hello World";
    char *morse_str = string_to_morse(str);
    printf("Original string: %s\n", str);
    printf("Morse code: %s\n", morse_str);
    free(morse_str); // Free the allocated memory
    return 0;
}