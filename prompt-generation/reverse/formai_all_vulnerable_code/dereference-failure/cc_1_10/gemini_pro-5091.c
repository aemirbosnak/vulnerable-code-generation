//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "?";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *string) {
    int len = strlen(string);
    char *morse_string = malloc(len * 5 + 1); // 5 characters per character + 1 for null terminator
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_string, char_to_morse(string[i]));
    }
    return morse_string;
}

// Print the Morse code representation of a string
void print_morse_code(char *morse_string) {
    int len = strlen(morse_string);
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", morse_string[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char *string = "Hello, world!";
    char *morse_string = string_to_morse(string);
    print_morse_code(morse_string);
    free(morse_string);
    return 0;
}