//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

// Morse code table
char morse_table[][16] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--.."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    memset(morse_code, 0, len * 5);
    for (int i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
    }
    return morse_code;
}

// Print the Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        printf("%c", morse_code[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char *str = "HELLO WORLD";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}