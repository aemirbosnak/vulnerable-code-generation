//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "..--", "-....", "--...",
    "---..", "----.", "-----", " ", " "
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Maximum 5 characters per character
    int i, j, k;
    for (i = 0, j = 0; i < len; i++) {
        char *c_morse = char_to_morse(str[i]);
        if (c_morse != NULL) {
            for (k = 0; k < strlen(c_morse); k++) {
                morse_code[j++] = c_morse[k];
                morse_code[j++] = ' ';
            }
        }
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Function to print Morse code
void print_morse(char *morse_code) {
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
    char str[] = "Hello World";
    char *morse_code = string_to_morse(str);
    print_morse(morse_code);
    free(morse_code);
    return 0;
}