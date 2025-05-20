//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Character to Morse code conversion table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a single character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return strdup(morse_table[c - 'A']);
    } else if (c >= 'a' && c <= 'z') {
        return strdup(morse_table[c - 'a']);
    } else if (c == ' ') {
        return strdup(" ");
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);  // Allocate enough space for the Morse code
    int i;

    morse_code[0] = '\0';

    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_code, morse_char);
            strcat(morse_code, " ");
        }
    }

    return morse_code;
}

// Function to print the Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    int i;

    for (i = 0; i < len; i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf(".");
        } else if (morse_code[i] == '-') {
            printf("-");
        }
    }

    printf("\n");
}

// Main function
int main() {
    char *text = "Hello, world!";
    char *morse_code;

    morse_code = string_to_morse(text);
    print_morse_code(morse_code);

    free(morse_code);

    return 0;
}