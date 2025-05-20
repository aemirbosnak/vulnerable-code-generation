//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
/*
 * Morse Code Conversion Extravaganza
 *
 * Vintage Computing Edition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Morse code table - each character is represented by a sequence of dots ('.') and dashes ('-') */
static const char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--..", "...", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
    "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", "-----", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "-..-.",
    ".-..-", "-..-.", "-....-", "..--..", ".----.", "-.--.-", ".-.-.", "....-",
    "-....-", ".----.", "..---", "-..-.", ".-.-.-", "-.-.-."
};

/* Convert a single character to Morse code */
static char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char*) morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return (char*) morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return (char*) morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

/* Convert a string to Morse code */
static char* string_to_morse(const char* str) {
    int i, len = strlen(str);
    char* morse = malloc(len * 5 + 1); /* Allocate enough space for the Morse code representation */
    char* p = morse;

    for (i = 0; i < len; i++) {
        char* c = char_to_morse(str[i]);
        if (c) {
            strcpy(p, c);
            p += strlen(c);
        } else {
            *p++ = '?';
        }
    }

    *p = '\0';
    return morse;
}

/* Print a string in Morse code using a dot matrix printer */
static void print_morse_on_dot_matrix_printer(const char* morse) {
    int i, len = strlen(morse);

    printf("Printing Morse code on the dot matrix printer...\n");
    printf("===========================================\n");
    for (i = 0; i < len; i++) {
        char c = morse[i];
        if (c == '.') {
            printf(".");
        } else if (c == '-') {
            printf("-");
        } else if (c == ' ') {
            printf(" ");
        } else {
            printf("?");
        }
    }
    printf("\n");
    printf("===========================================\n");
}

int main(void) {
    char* text = "Hello, world!";
    char* morse = string_to_morse(text);

    printf("Original text: %s\n", text);
    printf("Morse code representation: %s\n", morse);

    printf("Let's print it on the dot matrix printer!\n");
    print_morse_on_dot_matrix_printer(morse);

    free(morse);
    return 0;
}