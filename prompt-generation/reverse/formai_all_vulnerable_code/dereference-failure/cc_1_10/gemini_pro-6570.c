//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style:
// - No comments
// - No error checking
// - No indentation

// Morse code table
static const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..-", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--..", ".-..", "..--", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
static char *to_morse(char c) {
    if (c < 'A' || c > 'Z') {
        return NULL;
    }
    return (char *)morse_table[c - 'A'];
}

// Convert a string to Morse code
static char *to_morse_str(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5 + 1); // 5 characters per letter, plus null terminator
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *m = to_morse(str[i]);
        if (m) {
            strcpy(morse + j, m);
            j += strlen(m);
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';
    return morse;
}

// Print the Morse code representation of a character
static void print_morse(char c) {
    char *m = to_morse(c);
    if (m) {
        printf("%s", m);
    }
}

// Print the Morse code representation of a string
static void print_morse_str(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        print_morse(str[i]);
        printf(" ");
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *morse = to_morse_str(argv[1]);
    printf("%s\n", morse);

    free(morse);
    return 0;
}