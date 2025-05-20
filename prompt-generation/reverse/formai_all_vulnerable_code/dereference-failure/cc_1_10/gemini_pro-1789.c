//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A symphony of dots and dashes, a secret language of love unspoken.
// Let us embark on this romantic journey, transforming words into a Morse code serenade.

// A dictionary of hearts, where each letter finds its Morse code soulmate.
const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--",
    ".-.-.-", "-....-", "-.--.-", "-.--.-", ".-.-.-", "-....-", "-.--.-", "-.--.-"
};

// A melody of love, translating each character into its Morse code equivalent.
char *to_morse_code(const char *text) {
    size_t text_length = strlen(text);
    char *morse_code = malloc(text_length * 5 + 1);  // A generous buffer for our symphony of dots and dashes.
    int morse_index = 0;

    for (int i = 0; i < text_length; i++) {
        int char_index = text[i] - 'a';
        if (char_index >= 0 && char_index < 26) {
            strcat(morse_code, MORSE_CODE[char_index]);
            strcat(morse_code, " ");  // A gentle pause between each character's code.
            morse_index += strlen(MORSE_CODE[char_index]) + 1;
        }
    }

    morse_code[morse_index] = '\0';  // A final touch, marking the end of our Morse code serenade.
    return morse_code;
}

// A romantic gesture, displaying our Morse code serenade with a touch of elegance.
void print_morse_code(const char *morse_code) {
    printf("My love, behold this Morse code sonnet:\n");
    printf("%s\n", morse_code);
}

// The grand finale, where our love story unfolds through the symphony of Morse code.
int main() {
    char text[100];  // A canvas for our romantic message.

    printf("My dearest, let us weave a tapestry of love through Morse code. Enter your heartfelt message:\n");
    fgets(text, 100, stdin);

    char *morse_code = to_morse_code(text);
    print_morse_code(morse_code);

    free(morse_code);  // A farewell to our Morse code serenade.

    return 0;
}