//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", " ", "/"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else if (c == ' ') {
        return morse_table[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 6 + 1); // 6 characters per character + 1 for null terminator
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcat(morse_code, morse);
            strcat(morse_code, " ");
            index++;
        }
    }
    morse_code[index * 6] = '\0';
    return morse_code;
}

// Print Morse code in a visually appealing way
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("- ");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, MAX_LENGTH, stdin);

    char *morse_code = string_to_morse(input);
    printf("Morse code: ");
    print_morse_code(morse_code);

    free(morse_code);
    return 0;
}