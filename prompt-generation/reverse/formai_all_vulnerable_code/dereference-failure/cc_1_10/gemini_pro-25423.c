//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "..--", "-.--.",
    "--.-", ".-.-", "---", ".----", "..---", "...--", "....-", ".....", "-....",
    "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    int index = c - 'A';

    if (index < 0 || index >= 26) {
        return NULL;
    }

    return morse_table[index];
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5);

    int i;
    int index = 0;
    for (i = 0; i < len; i++) {
        char* c_morse = char_to_morse(str[i]);

        if (c_morse == NULL) {
            continue;
        }

        strcat(morse_code, c_morse);
        strcat(morse_code, " ");

        index += strlen(c_morse) + 1;
    }

    return morse_code;
}

int main() {
    char* str = "HELLO WORLD";

    char* morse_code = string_to_morse(str);

    printf("%s\n", morse_code);

    free(morse_code);

    return 0;
}