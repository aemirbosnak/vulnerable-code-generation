//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".- ",     // A
    "-... ",   // B
    "-.-. ",   // C
    "-.. ",    // D
    ". ",      // E
    "..-. ",   // F
    "--. ",    // G
    ".... ",   // H
    ".. ",     // I
    ".--- ",   // J
    "-.- ",    // K
    ".-.. ",   // L
    "-- ",     // M
    "-.. ",    // N
    "--- ",    // O
    ".--. ",   // P
    "--.- ",   // Q
    ".-. ",    // R
    "... ",    // S
    "- ",      // T
    "..- ",    // U
    "...- ",   // V
    ".-- ",    // W
    "-..- ",   // X
    "-.-- ",   // Y
    "--.. "    // Z
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return (char *)morse_table[c - 'a'];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *str_to_morse(char *str) {
    char *morse_str = malloc(strlen(str) * 5);
    int i;
    for (i = 0; i < strlen(str); i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_str, morse_char);
        }
    }
    return morse_str;
}

// Print the Morse code for a string
void print_morse(char *str) {
    char *morse_str = str_to_morse(str);
    printf("%s\n", morse_str);
    free(morse_str);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    print_morse(argv[1]);
    return EXIT_SUCCESS;
}