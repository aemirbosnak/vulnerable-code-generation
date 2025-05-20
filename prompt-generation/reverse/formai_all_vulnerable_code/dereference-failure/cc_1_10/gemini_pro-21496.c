//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
char *morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Character to Morse code conversion function
char *text_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_codes[index];
    } else {
        return NULL;
    }
}

// Text to Morse code translation function
char *translate_text_to_morse(char *text) {
    int text_len = strlen(text);
    int morse_len = 0;
    for (int i = 0; i < text_len; i++) {
        char *morse_code = text_to_morse(text[i]);
        if (morse_code != NULL) {
            morse_len += strlen(morse_code) + 1;
        }
    }

    char *morse_code = malloc(morse_len);
    int morse_index = 0;
    for (int i = 0; i < text_len; i++) {
        char *morse_code = text_to_morse(text[i]);
        if (morse_code != NULL) {
            strcat(morse_code, " ");
            morse_index += strlen(morse_code) + 1;
        }
    }

    return morse_code;
}

// Main function
int main() {
    char *text = "HELLO WORLD";
    char *morse_code = translate_text_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse_code);

    free(morse_code);
    return 0;
}