//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code alphabet
char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "-----", "|", " "
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_alphabet[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_alphabet[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_alphabet[c - '0' + 26];
    } else if (c == ' ') {
        return morse_alphabet[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5 + 1);
    int i;
    int j;
    for (i = 0; i < strlen(str); i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char == NULL) {
            continue;
        }
        for (j = 0; j < strlen(morse_char); j++) {
            morse_code[i * 5 + j] = morse_char[j];
        }
        morse_code[i * 5 + j] = ' ';
    }
    morse_code[strlen(str) * 5] = '\0';
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code) {
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
    char *str = "Hello World";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    return 0;
}