//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *to_morse_code(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_code_string(char *str) {
    int len = strlen(str);
    char *morse_code_string = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        char *morse_code_char = to_morse_code(str[i]);
        if (morse_code_char != NULL) {
            strcat(morse_code_string, morse_code_char);
            strcat(morse_code_string, " ");
        }
    }
    morse_code_string[len * 5] = '\0';
    return morse_code_string;
}

// Print the Morse code for a string
void print_morse_code(char *str) {
    char *morse_code_string = to_morse_code_string(str);
    printf("%s\n", morse_code_string);
    free(morse_code_string);
}

int main() {
    char *str = "Hello World!";
    printf("Original string: %s\n", str);
    print_morse_code(str);
    return 0;
}