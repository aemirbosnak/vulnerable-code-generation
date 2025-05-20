//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-..", "--..",  "-....",
    "..--", "...",   ".----", "..---", ".----", "---..", "----.", "-----", "....-", ".....",
    "-....", "--...", "---...", "----.", "-----", "-.-.--", ".-.-.-", "--..--", ".-..-.", "---...",
    "----.", ".----.", "-.--.-", "-....-", "-.--.-", "-.--.-", ".-.-.-", "-....-", "---...", "----.",
    "-----", "-.-.--", ".-.-.-", "--..--", ".-..-.", "---...", "----.", ".----.", "-.--.-", "-....-",
    "-.--.-", "-.--.-", ".-.-.-", "-....-", "---...", "----.", "-----", "-.-.--", ".-.-.-", "--..--",
    "-----", "-----", "-----", "-----", "-----", "-----", "-----", "-----", "-----", "-----",
    "-----", "-----", "-----", "-----", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = toupper(c);
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse, char_to_morse(s[i]));
        strcat(morse, " ");
    }
    return morse;
}

// Main function
int main() {
    char *s = "Hello World";
    char *morse = string_to_morse(s);
    printf("%s\n", morse);
    return 0;
}