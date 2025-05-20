//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "--...", "---.", ".-.-.-",
    "-....", "..--.-", ".-..-.", ".--.-. ", "---..", "..--", "-....-", ".-.-",
    "-...", ".-..", ".-.", "-..", "..", "---", "....", ".."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int i;
    char *c;
    int index = 0;

    for (i = 0; i < strlen(str); i++) {
        c = char_to_morse(str[i]);
        if (c != NULL) {
            strcpy(morse_code + index, c);
            index += strlen(c);
            morse_code[index++] = ' ';
        }
    }

    morse_code[index] = '\0';

    return morse_code;
}

int main() {
    char *str = "Hello World";
    char *morse_code = string_to_morse(str);

    printf("%s\n", morse_code);

    free(morse_code);

    return 0;
}