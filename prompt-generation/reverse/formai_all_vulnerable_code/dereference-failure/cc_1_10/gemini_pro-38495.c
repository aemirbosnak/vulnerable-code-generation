//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
static const char *morse_code[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..-",  "....-",
    "..",   ".----", "..---", "...--", "...",  ".----.", "-....", "--...", "-.-.-", "---",
    ".--.", "--...", "---..", "----.", "-----", ".-",    "...-", "...",    ".--",  "..--",
    "-..-", "-.--.", "--..", ".-..", "..",    ".---", "----", ".----.", "-....", "----.",
    "-----", "-....-", "--...", "-.--.", ".-..", "..-",   "--..", "-...",  "....", "--.----",
    "..---", ".-.-.-", "-....-", "---...", "-..---", "--..--", ".-....", ".-..---", "---..",
    "--..--", "-....-", ".-..",  "..---", "-..---", "--..--", "..--.-", "-....-", "-..",   ".---",
    "-.--.", "-..-.", "--..--", ".-....", ".-..---", "---..",  "--..--", "-....-", "-..---",
    "--..--", "..--.-", "-....-"
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return (char *)morse_code[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
static char *string_to_morse(const char *str) {
    size_t len = strlen(str);
    char *morse = malloc(len * 5 + 1);
    if (!morse) {
        return NULL;
    }
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *m = char_to_morse(str[i]);
        if (!m) {
            free(morse);
            return NULL;
        }
        strcpy(morse + j, m);
        j += strlen(m);
        morse[j++] = ' ';
    }
    morse[j] = '\0';
    return morse;
}

// Print Morse code
static void print_morse(const char *morse) {
    while (*morse) {
        if (*morse == ' ') {
            putchar(' ');
        } else if (*morse == '.') {
            putchar('.');
        } else if (*morse == '-') {
            putchar('-');
        }
        morse++;
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *morse = string_to_morse(argv[1]);
    if (!morse) {
        fprintf(stderr, "Error: could not convert string to Morse code\n");
        return EXIT_FAILURE;
    }
    print_morse(morse);
    free(morse);
    return EXIT_SUCCESS;
}