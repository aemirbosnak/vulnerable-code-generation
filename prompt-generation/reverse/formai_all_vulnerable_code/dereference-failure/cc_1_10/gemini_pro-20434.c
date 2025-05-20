//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code dictionary
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *to_morse_code(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32; // Convert to uppercase
    }

    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_code_string(char *s) {
    char *morse_code_string = malloc(strlen(s) * 5); // Allocate enough space for the Morse code string
    int i;

    for (i = 0; i < strlen(s); i++) {
        char *morse_code_char = to_morse_code(s[i]);

        if (morse_code_char != NULL) {
            strcat(morse_code_string, morse_code_char);
            strcat(morse_code_string, " "); // Separate each Morse code character with a space
        }
    }

    return morse_code_string;
}

// Print a string in Morse code
void print_morse_code(char *s) {
    char *morse_code_string = to_morse_code_string(s);

    printf("%s\n", morse_code_string);

    free(morse_code_string); // Free the memory allocated for the Morse code string
}

int main() {
    char *s = "Hello, world!";

    printf("Original string: %s\n", s);
    printf("Morse code: ");
    print_morse_code(s);

    return 0;
}