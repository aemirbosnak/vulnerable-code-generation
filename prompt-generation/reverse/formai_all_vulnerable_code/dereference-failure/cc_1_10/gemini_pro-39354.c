//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.", "---.", "-.-.-",
    "--.--", ".-.-.", "---", ".--.-", ".-...", "-..-.", ".-..", "..--..",
    "....-", "..---", "...--", "....-.", ".....", "-....", "--...", "---..",
    "----.", "-----"

};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    int i, j, len;
    char *morse_code_string = malloc(1000);
    memset(morse_code_string, 0, 1000);

    len = strlen(text);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 26; j++) {
            if (text[i] == 'a' + j || text[i] == 'A' + j) {
                strcat(morse_code_string, morse_code[j]);
                strcat(morse_code_string, " ");
                break;
            }
        }

        if (text[i] == ' ') {
            strcat(morse_code_string, "  ");
        }
    }

    return morse_code_string;
}

// Main function
int main() {
    char text[] = "Hello, world!";
    char *morse_code_string;

    printf("Text: %s\n", text);

    morse_code_string = text_to_morse(text);

    printf("Morse code: %s\n", morse_code_string);

    free(morse_code_string);

    return 0;
}