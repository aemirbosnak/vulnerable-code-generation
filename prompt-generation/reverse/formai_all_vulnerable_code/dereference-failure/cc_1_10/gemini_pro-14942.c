//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    }
    if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    }
    if (c == ' ') {
        return " ";
    }
    return "";
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++) {
        char *morse = char_to_morse(str[i]);
        strcat(morse_code, morse);
        strcat(morse_code, " ");
        j += strlen(morse) + 1;
    }
    morse_code[j - 1] = '\0';
    return morse_code;
}

// Print Morse code
void print_morse(char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
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

int main() {
    char str[] = "HELLO WORLD";
    char *morse_code = string_to_morse(str);
    printf("Morse code: %s\n", morse_code);
    print_morse(morse_code);
    return 0;
}