//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-"
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *text_to_morse(char *s) {
    int len = strlen(s);
    char *morse_code = malloc(len * 5 + 1);
    int i;
    int j;
    char *ptr;

    ptr = morse_code;
    for (i = 0; i < len; i++) {
        char *morse = char_to_morse(s[i]);
        if (morse != NULL) {
            strcpy(ptr, morse);
            ptr += strlen(morse);
        }
    }
    *ptr = '\0';

    return morse_code;
}

// Print Morse code
void print_morse(char *s) {
    int len = strlen(s);
    int i;

    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            printf(" ");
        } else if (s[i] == '.') {
            printf(".");
        } else if (s[i] == '-') {
            printf("-");
        }
    }
    printf("\n");
}

int main() {
    char *text = "Hello World!";
    char *morse_code = text_to_morse(text);
    print_morse(morse_code);
    free(morse_code);
    return 0;
}