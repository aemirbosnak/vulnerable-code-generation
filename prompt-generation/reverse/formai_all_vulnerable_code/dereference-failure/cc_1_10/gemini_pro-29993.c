//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MORSE_CODE_LEN 256

char* morse_code_table[MORSE_CODE_LEN] = {
    [ 'A' ] = ".-",
    [ 'B' ] = "-...",
    [ 'C' ] = "-.-.",
    [ 'D' ] = "-..",
    [ 'E' ] = ".",
    [ 'F' ] = "..-.",
    [ 'G' ] = "--.",
    [ 'H' ] = "....",
    [ 'I' ] = "..",
    [ 'J' ] = ".---",
    [ 'K' ] = "-.-",
    [ 'L' ] = ".-..",
    [ 'M' ] = "--",
    [ 'N' ] = "-.",
    [ 'O' ] = "---",
    [ 'P' ] = ".--.",
    [ 'Q' ] = "--.-",
    [ 'R' ] = ".-.",
    [ 'S' ] = "...",
    [ 'T' ] = "-",
    [ 'U' ] = "..-",
    [ 'V' ] = "...-",
    [ 'W' ] = ".--",
    [ 'X' ] = "-..-",
    [ 'Y' ] = "-.--",
    [ 'Z' ] = "--..",
    [ '0' ] = "-----",
    [ '1' ] = ".----",
    [ '2' ] = "..---",
    [ '3' ] = "...--",
    [ '4' ] = "....-",
    [ '5' ] = ".....",
    [ '6' ] = "-....",
    [ '7' ] = "--...",
    [ '8' ] = "---..",
    [ '9' ] = "----.",
    [ ' ' ] = "   "
};

char* text_to_morse_code(char* text) {
    int text_len = strlen(text);
    char* morse_code = malloc(text_len * 4 + 1);
    int morse_code_len = 0;

    for (int i = 0; i < text_len; i++) {
        char* code = morse_code_table[text[i]];
        if (code != NULL) {
            strcat(morse_code, code);
            morse_code_len += strlen(code);
            morse_code[morse_code_len++] = ' ';
        }
    }

    morse_code[morse_code_len] = '\0';
    return morse_code;
}

int main() {
    char* text = "HELLO WORLD";
    char* morse_code = text_to_morse_code(text);
    printf("%s\n", morse_code);
    free(morse_code);
    return 0;
}