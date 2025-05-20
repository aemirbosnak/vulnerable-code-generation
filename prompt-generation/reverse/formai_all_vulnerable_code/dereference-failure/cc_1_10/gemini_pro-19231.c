//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
    "--..", "|"  // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }

    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    }

    if (c == ' ') {
        return morse_table[26];  // Space
    }

    return NULL;  // Invalid character
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);  // Allocate enough space for the morse code
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);

        if (morse != NULL) {
            strcpy(&morse_code[j], morse);
            j += strlen(morse);

            // Add a space between characters
            if (i < len - 1) {
                morse_code[j++] = ' ';
            }
        }
    }

    morse_code[j] = '\0';  // Null-terminate the string

    return morse_code;
}

int main() {
    char *text = "Hello World";
    char *morse_code = string_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return 0;
}