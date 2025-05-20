//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_code[] = {
    ".-       ", "-...     ", "-.-.-    ", "-..      ", ".", "..-..    ", "--.      ",
    "....     ", "..      ", ".---     ", "-.-      ", ".-..     ", "--      ", "-.      ",
    "...-     ", ".-       ", "--..     ", "-.       ", "---      ", ".--      ", "--.-     ",
    ".-.      ", "...      ", "-        ", "..-      ", "-..      ", ".       ", ".-.-.-   ",
    "--..--   ", "-....    ", "..--     ", ".-..-.   ", ".--.-    ", ".-...    ", "-..-    ",
    "-.--     ", "-.--.-   ", "..--..   ", "----      ", ".----     ", "-.-.--    ",
    "-..-     ", "-.--     ", ".-      ", ".-..    ", "-..     ", ".------   ",
    "--...--- ",  ".-.....   ",  "-.....   ",  "...--    ", "....-    ", "..--.-   ",
    ".----.    ", "-----     ", ".----.    ",     "--..--   ", "-...-.   ",  "....-.. "
};

// Convert a single character to Morse code
char *text_to_morse(char c) {
    int index = c - 'A';
    if (index < 0 || index > 25) {
        return NULL;
    }
    return morse_code[index];
}

// Convert a string of text to Morse code
char *text_to_morse_string(char *text) {
    char *morse_code = malloc(strlen(text) * 5);
    int i = 0;
    while (text[i] != '\0') {
        char *code = text_to_morse(text[i]);
        if (code == NULL) {
            free(morse_code);
            return NULL;
        }
        strcat(morse_code, code);
        strcat(morse_code, " ");
        i++;
    }
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    char text[] = "HELLO WORLD";
    char *morse_code = text_to_morse_string(text);
    if (morse_code == NULL) {
        printf("Error converting text to Morse code\n");
        return 1;
    }
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}