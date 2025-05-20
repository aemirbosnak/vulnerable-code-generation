//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-....", "..--", "-..-", "-.--", "--..",
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 4 + 1);
    int i;
    char *c;
    for (i = 0; i < strlen(str); i++) {
        c = char_to_morse(str[i]);
        if (c != NULL) {
            strcat(morse_code, c);
        }
    }
    return morse_code;
}

// Function to print Morse code
void print_morse(char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == '.') {
            printf(".");
        } else if (morse_code[i] == '-') {
            printf("-");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *str = "HELLO WORLD";
    char *morse_code = string_to_morse(str);
    print_morse(morse_code);
    free(morse_code);
    return 0;
}