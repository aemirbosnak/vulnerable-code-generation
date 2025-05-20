//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5 + 1); // Allow 5 characters per letter (plus 1 for null terminator)
    int i;
    int j = 0;
    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(s[i]);
        if (morse_char != NULL) {
            strcpy(morse + j, morse_char);
            j += strlen(morse_char);
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';
    return morse;
}

// Print a string in Morse code
void print_morse(char *s) {
    int len = strlen(s);
    int i;
    for (i = 0; i < len; i++) {
        if (s[i] == '.') {
            printf("·");
        } else if (s[i] == '-') {
            printf("—");
        } else if (s[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *text = "HELLO WORLD";
    char *morse = string_to_morse(text);
    printf("Text: %s\n", text);
    printf("Morse code: ");
    print_morse(morse);
    free(morse);
    return 0;
}