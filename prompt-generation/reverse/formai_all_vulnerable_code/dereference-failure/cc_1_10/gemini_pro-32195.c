//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse alphabet
char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--..", "-----", ".-.-.-", "..-.-", "---...", "-.-.-.", "-....-",
    "....-", ".....", "-....-", "--...", "---..", "----.", "----", "..--..", "-....-",
    "--...--", "-.-.-.---", ".-.-.-.", "-.--.-", "-....-", "..--..", "-....-", "-.-.--",
    "---...", "----.", "----.", ".-.-.-", "-.--.-", "-....-", "..--..", "-....-",
    "--...--", "-.-.-.---", ".-.-.-.", "-.--.-", "-....-", "..--..", "-....-", "-.-.--",
    "---...", "----.", "----.", ".-.-.-", "-.--.-", "-....-", "..--..", "-....-",
    "--...--", "-.-.-.---", ".-.-.-.", "-.--.-", "-....-", "..--..", "-....-", "-.-.--",
    "---...", "----.", "----.", ".-.-.-", "-.--.-", "-....-", "..--..", "-....-",
    "--...--", "-.-.-.---", ".-.-.-.", "-.--.-", "-....-", "..--..", "-....-", "-.-.--",
    "---...", "----.", "----."
};

// Morse alphabet length
int morse_alphabet_length = sizeof(morse_alphabet) / sizeof(morse_alphabet[0]);

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_alphabet[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_alphabet[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_alphabet[c - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *to_morse_string(char *s) {
    char *morse_string = malloc(strlen(s) * 5);
    int i;
    for (i = 0; i < strlen(s); i++) {
        strcat(morse_string, to_morse(s[i]));
        strcat(morse_string, " ");
    }
    return morse_string;
}

// Print the Morse code representation of a string
void print_morse(char *s) {
    char *morse_string = to_morse_string(s);
    printf("%s\n", morse_string);
    free(morse_string);
}

int main() {
    char s[] = "HELLO WORLD";
    print_morse(s);
    return 0;
}