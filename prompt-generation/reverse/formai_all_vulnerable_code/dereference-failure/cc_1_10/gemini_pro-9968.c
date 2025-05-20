//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code table
static const char *morse_table[] = {
    ".-",    "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".----", "--.-", "-.",   "...",  "-",    "..-",  "...-",
    ".--",  "-.--", "--..",  ".----", "--.-", ".-..", "--",   "-....", "..--",
    "....-", ".....", "-....-", "--...", "---",   ".----.", "-.--.", ".-..-.",
    "--..--", ".-....", ".-..-.", "---...", "----.", "-----"
};

// Function to convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }

    int index = c - 'a';
    if (index >= 0 && index < 26) {
        return strdup(morse_table[index]);
    }

    return NULL;
}

// Function to convert a string to Morse code
char *str_to_morse(const char *str) {
    size_t len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    if (!morse_code) {
        return NULL;
    }

    char *ptr = morse_code;
    for (size_t i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (!morse) {
            free(morse_code);
            return NULL;
        }

        strcpy(ptr, morse);
        ptr += strlen(morse);
        *ptr++ = ' ';
    }

    *ptr = '\0';
    return morse_code;
}

// Function to print Morse code
void print_morse(const char *morse_code) {
    while (*morse_code) {
        if (*morse_code == ' ') {
            printf(" ");
        } else if (*morse_code == '.') {
            printf("·");
        } else if (*morse_code == '-') {
            printf("-");
        }

        morse_code++;
    }
}

// Main function
int main(void) {
    const char *text = "Hello, world!";

    char *morse_code = str_to_morse(text);
    if (!morse_code) {
        return EXIT_FAILURE;
    }

    printf("Text: %s\n", text);
    printf("Morse code: ");
    print_morse(morse_code);
    printf("\n");

    free(morse_code);
    return EXIT_SUCCESS;
}