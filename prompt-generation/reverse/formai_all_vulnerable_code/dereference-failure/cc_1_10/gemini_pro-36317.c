//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Morse code alphabet
char *morse[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Convert a character to its Morse code equivalent
char *to_morse(char c) {
    c = toupper(c);
    if (c < 'A' || c > 'Z') {
        return NULL;
    }
    return morse[c - 'A'];
}

// Convert a string to its Morse code equivalent
char *to_morse_str(char *str) {
    char *morse_str = malloc(strlen(str) * 5);
    int i;
    for (i = 0; i < strlen(str); i++) {
        char *morse_char = to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_str, morse_char);
            strcat(morse_str, " ");
        }
    }
    return morse_str;
}

// Print the Morse code equivalent of a string
void print_morse(char *str) {
    char *morse_str = to_morse_str(str);
    printf("%s\n", morse_str);
    free(morse_str);
}

// Get a line of text from the user
char *get_line() {
    char *line = malloc(100);
    fgets(line, 100, stdin);
    return line;
}

// Main function
int main() {
    printf("Enter a line of text: ");
    char *line = get_line();
    print_morse(line);
    free(line);
    return 0;
}