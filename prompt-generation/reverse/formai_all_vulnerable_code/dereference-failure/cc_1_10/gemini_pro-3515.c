//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-.", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", ".-.-.-",
    "--..--", "..--..", "...-..-", "....-.."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 4 + 1);
    int i;
    for (i = 0; i < len; i++) {
        char *c_morse = char_to_morse(s[i]);
        if (c_morse == NULL) {
            free(morse);
            return NULL;
        }
        strcat(morse, c_morse);
        strcat(morse, " ");
    }
    return morse;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    char *morse = string_to_morse(text);
    if (morse == NULL) {
        printf("Error: Invalid character in text.\n");
        return 1;
    }

    printf("Morse code: %s\n", morse);
    free(morse);
    return 0;
}