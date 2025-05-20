//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "-....", "--...",
    "---..", "----.", "-----", "|", " "  // Space character
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;  // Convert to uppercase
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c == ' ') {
        return morse_table[36];  // Space character
    } else {
        return NULL;  // Invalid character
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);  // Allocate enough space for the Morse code (5 characters per character)
    if (morse_code == NULL) {
        return NULL;  // Error allocating memory
    }
    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++) {
        char *morse = char_to_morse(str[i]);
        if (morse == NULL) {
            free(morse_code);
            return NULL;  // Invalid character
        }
        strcpy(morse_code + j, morse);
        j += strlen(morse);
        morse_code[j++] = ' ';  // Add a space between characters
    }
    morse_code[j] = '\0';  // Terminate the string
    return morse_code;
}

// Print the Morse code
void print_morse(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    char str[] = "Hello World!";

    char *morse_code = string_to_morse(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code\n");
        return EXIT_FAILURE;
    }

    print_morse(morse_code);

    free(morse_code);

    return EXIT_SUCCESS;
}