//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.--.-", "..--..",
};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    int text_len = strlen(text);
    char *morse_code_str = malloc(text_len * 5);  // Allocate memory for Morse code string

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < text_len; i++) {
        char ch = text[i];

        // Ignore non-alphabetic characters
        if (ch < 'A' || ch > 'Z') {
            continue;
        }

        // Get the Morse code for the character
        char *morse_code_char = morse_code[ch - 'A'];

        // Append the Morse code to the string
        while (*morse_code_char) {
            morse_code_str[j++] = *morse_code_char++;
            morse_code_str[j++] = ' ';
        }
    }

    morse_code_str[j] = '\0';  // Null-terminate the Morse code string

    return morse_code_str;
}

// Main function
int main() {
    char *text = "HELLO WORLD";
    char *morse_code_str = text_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse Code: %s\n", morse_code_str);

    free(morse_code_str);  // Free the memory allocated for Morse code string

    return 0;
}