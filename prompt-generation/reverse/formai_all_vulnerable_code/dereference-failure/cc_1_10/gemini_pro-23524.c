//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|",
    "---...", "...-..-", ".-.-.-", "..--..", "-....-", "-..---", "-.-.--", "--..--", ".-..-.",
    "...-...", "---...", ".-.-.", "-....-", "-.-.--", "-.--.-", ".-...", "-.--.", "-.--.-", "-..-.",
    "--..--", "----."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return "";  // Unknown character
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5 + 1);  // Allocate enough space for the Morse code
    int i;
    int pos = 0;
    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        strcpy(morse + pos, morse_char);
        pos += strlen(morse_char);
        morse[pos++] = ' ';  // Add a space between characters
    }
    morse[pos] = '\0';  // Null-terminate the string
    return morse;
}

// Print the Morse code representation of a string
void print_morse(char *morse) {
    printf("%s\n", morse);
}

int main() {
    char *str = "HELLO WORLD";
    char *morse = string_to_morse(str);
    print_morse(morse);
    free(morse);
    return 0;
}