//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1024

// Morse code character table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.--"
};

// Convert a character to Morse code
char *char_to_morse(char c)
{
    int index = c - 'A';
    if (index < 0 || index >= 26) {
        return NULL;
    }
    return morse_table[index];
}

// Convert a string to Morse code
char *text_to_morse(char *text)
{
    int text_len = strlen(text);
    char *morse_code = malloc(text_len * 5 + 1);
    if (morse_code == NULL) {
        return NULL;
    }

    int morse_code_len = 0;
    for (int i = 0; i < text_len; i++) {
        char *morse_char = char_to_morse(text[i]);
        if (morse_char != NULL) {
            strcpy(morse_code + morse_code_len, morse_char);
            morse_code_len += strlen(morse_char);
            morse_code[morse_code_len++] = ' ';
        }
    }
    morse_code[morse_code_len] = '\0';

    return morse_code;
}

// Main function
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    if (strlen(text) > MAX_TEXT_LEN) {
        printf("Error: Text too long. Maximum length is %d characters.\n", MAX_TEXT_LEN);
        return EXIT_FAILURE;
    }

    char *morse_code = text_to_morse(text);
    if (morse_code == NULL) {
        printf("Error: Could not convert text to Morse code.\n");
        return EXIT_FAILURE;
    }

    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return EXIT_SUCCESS;
}