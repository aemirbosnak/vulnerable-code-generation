//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", "|", "|---|", "|-..|", "||..|", "|..||", "|...|", "|||||",
    "|----", "|----|", "||---|", "|..--", "||.-|", "|...-|", "||||-", "|----|"
};

// Function to convert a character to Morse code
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
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *s) {
    char *morse_code_string = malloc(strlen(s) * 5);
    int i;
    for (i = 0; i < strlen(s); i++) {
        char *morse_code_char = char_to_morse(s[i]);
        if (morse_code_char == NULL) {
            free(morse_code_string);
            return NULL;
        }
        strcat(morse_code_string, morse_code_char);
        strcat(morse_code_string, " ");
    }
    return morse_code_string;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string to convert>\n", argv[0]);
        return 1;
    }
    char *morse_code_string = string_to_morse(argv[1]);
    if (morse_code_string == NULL) {
        fprintf(stderr, "Error: Invalid character in string\n");
        return 1;
    }
    printf("%s\n", morse_code_string);
    free(morse_code_string);
    return 0;
}