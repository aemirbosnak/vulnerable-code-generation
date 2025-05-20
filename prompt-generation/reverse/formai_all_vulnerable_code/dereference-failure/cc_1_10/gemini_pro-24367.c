//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
// Embrace the enigmatic whispers of Morse code, as we gracefully translate text into its enigmatic symphony.

// Unveiling the enigmatic tapestry of headers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A celestial map of Morse code, where each character finds its celestial abode.
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// A celestial guide, mapping characters to their Morse code counterparts.
int char_to_morse(char ch) {
    for (int i = 0; i < 26; i++) {
        if (ch == 'a' + i || ch == 'A' + i) {
            return i;
        }
    }
    return -1;
}

// A cosmic translator, weaving text into the ethereal fabric of Morse code.
char *text_to_morse(char *text) {
    int len = strlen(text);
    char *morse_code_str = malloc(len * 4); // Ample space for the Morse code representation.
    int index = 0;
    for (int i = 0; i < len; i++) {
        int code_index = char_to_morse(text[i]);
        if (code_index != -1) {
            strcat(morse_code_str, morse_code[code_index]);
            strcat(morse_code_str, " ");  // A cosmic separator, guiding the reading of Morse code.
            index += strlen(morse_code[code_index]) + 1;
        }
    }
    return morse_code_str;
}

// A celestial symphony, echoing the whispered secrets of Morse code.
void print_morse_code(char *morse_code_str) {
    printf("Behold, the enigmatic symphony of Morse code:\n%s\n", morse_code_str);
}

// Our celestial journey begins here.
int main() {
    char text[] = "Hello, World!"; // Our earthly message, yearning for cosmic translation.
    char *morse_code_str = text_to_morse(text); // Unveiling the hidden tapestry of Morse code.
    print_morse_code(morse_code_str); // Resonating the symphony of Morse code through the void.
    free(morse_code_str); // Releasing the celestial echoes back into the cosmic abyss.
    return 0;
}