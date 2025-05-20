//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char* morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }

    int index = c - 'A';

    if (index >= 0 && index < 26) {
        return (char*)morse_code[index];
    }

    return NULL;
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5);

    for (int i = 0; i < len; i++) {
        char* c = char_to_morse(str[i]);

        if (c) {
            strcat(morse_code, c);
            strcat(morse_code, " ");
        }
    }

    return morse_code;
}

// Main function
int main() {
    char* str = "HELLO WORLD";

    char* morse_code = string_to_morse(str);

    printf("Original string: %s\n", str);
    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return 0;
}