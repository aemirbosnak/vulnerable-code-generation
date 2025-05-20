//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
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
    " "     // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;  // Convert to uppercase
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return morse_table[36];
    } else {
        return NULL;  // Invalid character
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);  // Allocate enough space for the Morse code
    int i, j, k = 0;
    for (i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse) {
            for (j = 0; j < strlen(morse); j++) {
                morse_code[k++] = morse[j];
                morse_code[k++] = ' ';  // Add a space between each character
            }
        }
    }
    morse_code[k] = '\0';  // Null-terminate the string
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("-");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *str = "HELLO WORLD";
    char *morse_code = string_to_morse(str);
    printf("Original string: %s\n", str);
    printf("Morse code: ");
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}