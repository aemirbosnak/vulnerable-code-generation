//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    int i;
    for (i = 0; i < len; i++) {
        char *c_morse = char_to_morse(str[i]);
        if (c_morse != NULL) {
            strcat(morse_code, c_morse);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

// Function to print Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    int i;
    for (i = 0; i < len; i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf(".");
        } else if (morse_code[i] == '-') {
            printf("-");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *text = "HELLO WORLD";
    char *morse_code = string_to_morse(text);
    print_morse_code(morse_code);
    return 0;
}