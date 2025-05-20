//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-",    "-...",  "-.-.",  "-..",    ".",     "..-.",  "--.",   "....",  "..",    ".---",
    "-.-",   ".-..",  "--",    "-.",     "...",   "-",     "..-",   ".--.",  "-..-",  "-.--",
    "--..",  ".----", "..---",  ".----.", "-----",  ".----.", ".-..-.", "--..--", "-....-", "--...-",
    "---...", "----.", "-----.", "-....-", "-----",  "---..", "---...", "----.", ".----.", "-....",
    "--...", "...--", "....-", "..--..", "-..-.", ".-..",  "--..--", "...--",  "...---", "...--",
    "-.--.",  "-.--.-", ".-...",  "-..-.",  "-.--",  ".----", "..---",  ".----.", "-..---", "-....",
    "-.-.--", "-.-.--", "--..--", "-.-.-",  "--.--",  "-...-", "-....-", "-----",  "-----",  "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5 + 1); // Each character can be up to 5 Morse code units plus a space
    int i;
    int j = 0;
    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(s[i]);
        if (morse_char != NULL) {
            strcpy(morse + j, morse_char);
            j += strlen(morse_char);
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';
    return morse;
}

// Print the Morse code for a string
void print_morse(char *s) {
    printf("%s\n", s);
}

int main() {
    char *s = "Hello, world!";
    char *morse = string_to_morse(s);
    print_morse(morse);
    free(morse);
    return 0;
}