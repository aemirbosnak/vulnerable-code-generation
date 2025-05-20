//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Morse code lookup table
static char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "?";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5 + 1);
    int i, j, k;

    k = 0;
    for (i = 0; i < len; i++) {
        char *m = char_to_morse(str[i]);
        for (j = 0; j < strlen(m); j++) {
            morse[k++] = m[j];
            morse[k++] = ' ';
        }
    }
    morse[k] = '\0';

    return morse;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *morse = string_to_morse(argv[1]);
    printf("%s\n", morse);

    free(morse);
    return EXIT_SUCCESS;
}