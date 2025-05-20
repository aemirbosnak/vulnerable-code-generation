//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

// Morse code table
char *morse_table[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "...",  "-",    ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", ".----.", "--..--", ".-.-.-",
    "..--..", "...-..-", "....--", ".....-", "------", ".-",    "...---...", "...-..-",
    "-.--.", "-.-.-.", "-...-", "-.--",  ".----.", "-....-", ".-..-.", ".-..", ".-.",
    "....",  "-----",  ".----", "..---", "---..", "----.", ".--.",  "..--",  ".-.-.", ".-..",
    "--..-", "-....", "-..-.", "-.-.--", "..-...", "--...", "-...-", ".-...", "...-",
    "..-",  ".--.",  "---",   ".--. ", ".-.-.-", ".-.-",  "--..--", ".-...."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return "       ";
    } else {
        return "";
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *text) {
    int len = strlen(text);
    char *morse_code = malloc(len * 5 + 1);
    int i, j;
    int pos = 0;

    for (i = 0; i < len; i++) {
        char *morse = char_to_morse(text[i]);
        for (j = 0; j < strlen(morse); j++) {
            morse_code[pos++] = morse[j];
        }
        morse_code[pos++] = ' ';
    }

    morse_code[pos] = '\0';

    return morse_code;
}

int main() {
    char text[MAX_TEXT_SIZE];
    char *morse_code;

    printf("Enter a text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);

    morse_code = string_to_morse(text);

    printf("Morse code: %s\n", morse_code);

    return 0;
}