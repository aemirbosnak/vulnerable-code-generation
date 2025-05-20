//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---.",
    "----", "..--", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "...-..-", "....-.",
    ".....-", "-....-", "--...--", "---..-.", "----..-", "-----.", ".-.-.", "-...", "---.", ".-.-.-",
    "--..--", "-.-.-.", "...-..-", ".-..-.", "..--.-", ".-....", "-.....", "-....-", "--....", "---...",
    "----..", "-----.", ".-.-.-", "-....-", "--..--", "...-..-", ".-..-.", "....---", "-.....-", "-....-",
    "--....", "---..."
};

// Convert a single character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_string(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5 + 1); // Allocate enough space for the Morse code representation
    int i;
    for (i = 0; i < len; i++) {
        char *m = to_morse(s[i]);
        if (m != NULL) {
            strcat(morse, m);
            strcat(morse, " ");
        }
    }
    morse[len * 5] = '\0'; // Null-terminate the string
    return morse;
}

// Print the Morse code representation of a string
void print_morse(char *s) {
    printf("%s\n", s);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *morse = to_morse_string(argv[1]);
    print_morse(morse);
    free(morse);
    return EXIT_SUCCESS;
}