//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Morse code table */
static const char *morse_table[] = {
    ".-",    "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",  ".---",
    "-.-",   ".-..", "--",   "-.",   "...", "-..-", "-.--",  "--..",  ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "..--..",
    ".----.", "...--.-", ".-.-.-", "--..--", "-....-", "..--.-.", ".-..-.", ".-.--.-",
    "--..--", "-.-.-.---", "-...-.-", ".-.-.-.", "...-..-", "-.--.-.---", ".-.-.--",
    "--..--", ".-.-.-.", "-..--.-.-.-", "-.-.-.-.-.-", ".-.-.-.-..", "-.-.-.-....-",
    "-.-.-.-.....", "-.-.-.-......", "....-....-....-....", ".-..-.--.", ".-..-.--.-.",
    "-.--.---.", "-.-..-.--.", "-.-.-.--.-"
};

/* Convert a character to Morse code */
static char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return NULL;
    }
}

/* Convert a string to Morse code */
static char *string_to_morse(const char *str) {
    char *morse_code = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse) {
            int new_len = (morse_code ? strlen(morse_code) : 0) + strlen(morse) + 1;
            morse_code = realloc(morse_code, new_len);
            strcat(morse_code, morse);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

int main(void) {
    const char *text = "SOS";
    char *morse_code = string_to_morse(text);
    if (morse_code) {
        printf("Morse code for '%s': %s\n", text, morse_code);
        free(morse_code);
    } else {
        printf("Invalid text '%s'\n", text);
    }
    return 0;
}