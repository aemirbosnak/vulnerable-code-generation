//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32; // Convert to uppercase
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else {
        return NULL; // Not a valid character
    }
}

// Convert a string to Morse code
char *to_morse_str(char *str) {
    char *morse_str = malloc(strlen(str) * 5 + 1); // Allocate enough space for the Morse code
    int i;
    for (i = 0; i < strlen(str); i++) {
        char *morse_char = to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_str, morse_char);
            strcat(morse_str, " "); // Add a space between characters
        }
    }
    morse_str[strlen(morse_str) - 1] = '\0'; // Remove the trailing space
    return morse_str;
}

// Print Morse code in a real-life style
void print_morse(char *morse_str) {
    int i;
    for (i = 0; i < strlen(morse_str); i++) {
        if (morse_str[i] == '.') {
            printf("Dit ");
        } else if (morse_str[i] == '-') {
            printf("Dah ");
        } else if (morse_str[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *str = "SOS";
    char *morse_str = to_morse_str(str);
    print_morse(morse_str);
    free(morse_str);
    return 0;
}