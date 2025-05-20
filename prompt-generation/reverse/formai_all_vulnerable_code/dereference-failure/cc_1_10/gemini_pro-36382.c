//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
    char *art[] = {
        " _ ", // A
        " ___ ", // B
        "   _  ", // C
        "  __  ", // D
        "_    _", // E
        "___  ", // F
        "_   _ ", // G
        " __ __", // H
        "   __", // I
        " __  ", // J
        "_  __ ", // K
        "__    ", // L
        "   __ ", // M
        "   __ ", // N
        "_     ", // O
        "___  ", // P
        "__   ", // Q
        " ___  ", // R
        "   __ ", // S
        " __ ", // T
        "   __ ", // U
        " __  ", // V
        " ___  ", // W
        "__ __ ", // X
        " __ __", // Y
        " ___  ", // Z
        "    ", // Space
    };
    return art[c - 'A'];
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
    int len = strlen(str);
    char *art = malloc(len * 5 + 1); // 5 characters per letter + 1 for null terminator
    for (int i = 0; i < len; i++) {
        strcat(art, char_to_ascii(str[i]));
    }
    return art;
}

// Main function
int main() {
    char str[] = "ASCII ART";
    char *art = string_to_ascii(str);
    printf("%s\n", art);
    free(art);
    return 0;
}