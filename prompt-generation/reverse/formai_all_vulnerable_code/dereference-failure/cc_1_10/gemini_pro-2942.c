//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: genius
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char morse_codes[][10] = {
    {'.', '-', '-', '-', '-', '.'}, // A
    {'-', '...', '-', '-', '-', '.'}, // B
    {'-', '-', '.-', '-', '-', '.'}, // C
    {'-', '-', '-', '.', '.', '.'}, // D
    {'.', '.', '.', '-', '-', '.'}, // E
    {'-', '-', '.-.', '-', '-', '.'}, // F
    {'-', '--', '-', '-', '-', '.'}, // G
    {'.', '.', '.', '.', '.', '.'}, // H
    {'.', '.', '-', '-', '-', '.'}, // I
    {'.', '-', '-', '-', '-', '-'}, // J
    {'-', '-', '-', '-', '.', '-'}, // K
    {'.', '-', '-', '.-', '-', '.'}, // L
    {'-', '-', '-', '-', '-', '-'}, // M
    {'-', '-', '.', '-', '-', '.'}, // N
    {'-', '--', '-', '-', '-', '-'}, // O
    {'.', '--', '--', '-', '-', '.'}, // P
    {'-', '-', '--', '-', '-', '.'}, // Q
    {'.', '-', '-', '.', '-', '.'}, // R
    {'.', '.', '.', '-', '-', '.'}, // S
    {'-', '-', '-', '-', '-', '-'}, // T
    {'.', '.', '-', '-', '-', '.'}, // U
    {'.', '.', '.', '-', '-', '-'}, // V
    {'.', '-', '-', '-', '-', '-'}, // W
    {'-', '-', '-', '-', '-', '|'}, // X
    {'-', '-', '.', '-', '-', '-'}, // Y
    {'-', '--', '-', '-', '-', '-'}, // Z
};

char *to_morse(char *text) {
    int text_len = strlen(text);
    char *morse_code = malloc(text_len * 5);

    int morse_index = 0;
    for (int i = 0; i < text_len; i++) {
        char letter = text[i];
        if (letter == ' ') {
            morse_code[morse_index++] = ' ';
        } else {
            int char_index = toupper(letter) - 'A';
            for (int j = 0; j < 6; j++) {
                morse_code[morse_index++] = morse_codes[char_index][j];
            }
            morse_code[morse_index++] = ' ';
        }
    }

    return morse_code;
}

int main() {
    char text[] = "HELLO WORLD";
    char *morse_code = to_morse(text);

    printf("Morse code: %s\n", morse_code);

    return 0;
}