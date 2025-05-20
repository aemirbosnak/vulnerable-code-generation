//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--.", "---.",
    "-----", ".-", "...-", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--.", "---.",
    "-----"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
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
    char *morse_code = malloc(strlen(str) * 5);
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcpy(morse_code + j, morse_char);
            j += strlen(morse_char);
            morse_code[j++] = ' ';
        }
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Function to print a string in Morse code
void print_morse_code(char *morse_code) {
    int i;
    for (i = 0; morse_code[i] != '\0'; i++) {
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

int main() {
    char *str = "Hello, world!";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}