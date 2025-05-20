//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
static const char *morse_table[] = {
    ".-", "..-", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--. ", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "~",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return (char *)morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return (char *)morse_table[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
static char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    if (morse_code == NULL) {
        return NULL;
    }

    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcpy(morse_code + j, morse);
            j += strlen(morse);
            morse_code[j++] = ' ';
        }
    }

    morse_code[j - 1] = '\0';
    return morse_code;
}

// Print the Morse code for a string
static void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *morse_code = string_to_morse(argv[1]);
    if (morse_code == NULL) {
        fprintf(stderr, "Error: Could not convert string to Morse code.\n");
        return EXIT_FAILURE;
    }

    print_morse_code(morse_code);
    free(morse_code);
    return EXIT_SUCCESS;
}