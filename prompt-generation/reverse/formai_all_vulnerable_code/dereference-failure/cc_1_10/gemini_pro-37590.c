//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
const char* morse_map[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
    "-----", "-.-.--", "..--..", "...---", "....--", ".....-", "-....-",
    "--...--", "---..--", "----..--", "-----.--"
};

// Convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return (char*)morse_map[c - 'A'];
    }
    if (c >= '0' && c <= '9') {
        return (char*)morse_map[c - '0' + 26];
    }
    switch (c) {
        case ' ':
            return " ";
        case '.':
            return ".-.-.-";
        case ',':
            return "--..--";
        case '?':
            return "..--..";
        case '/':
            return "-..-.";
        case '-':
            return "-....-";
        case '(':
            return "-.--.";
        case ')':
            return "-.--.-";
        default:
            return "";
    }
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5 + 1); // 5 characters per Morse code character plus 1 for null terminator
    int i;
    int pos = 0;
    for (i = 0; i < len; i++) {
        char* morse = char_to_morse(str[i]);
        strcat(morse_code, morse);
        pos += strlen(morse);
        morse_code[pos++] = ' ';
    }
    morse_code[pos] = '\0';
    return morse_code;
}

// Print the Morse code for a string
void print_morse_code(char* morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    char* str = "HELLO WORLD";
    char* morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}