//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "--..--", "|",
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    char *morse_code = NULL;
    if (c >= 'A' && c <= 'Z') {
        morse_code = morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        morse_code = morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        morse_code = morse_table[c - '0' + 26];
    } else if (c == ' ') {
        morse_code = " ";
    }
    return morse_code;
}

// Function to convert a string to Morse code
char *string_to_morse(char *s) {
    char *morse_code = NULL;
    int i, len;
    len = strlen(s);
    for (i = 0; i < len; i++) {
        char *ch_morse_code = char_to_morse(s[i]);
        if (ch_morse_code != NULL) {
            morse_code = realloc(morse_code, (strlen(morse_code) + strlen(ch_morse_code) + 2) * sizeof(char));
            strcat(morse_code, ch_morse_code);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string to convert>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];
    char *morse_code = string_to_morse(text);
    printf("Morse code: %s\n", morse_code);
    free(morse_code);
    return 0;
}