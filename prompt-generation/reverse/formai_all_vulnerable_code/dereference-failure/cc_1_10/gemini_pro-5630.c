//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100

// Morse code table
char morse_table[][6] = {
    {'.', '-', '-', '-', '-', '-'}, // A
    {'-', '.', '.', '.', '.', '-'}, // B
    {'-', '.', '-', '-', '.', '-'}, // C
    {'-', '.', '.', '-', '-', '.'}, // D
    {' ', '.', '.', '.', '.', '.'}, // E
    {'.', '.', '-', '-', '.', '-'}, // F
    {'-', '-', '.', '.', '-', '.'}, // G
    {'.', '.', '.', '.', '.', '.'}, // H
    {'.', '.', '.', '.', '.', '.'}, // I
    {'.', '-', '-', '-', '-', '-'}, // J
    {'-', '-', '-', '-', '.', '-'}, // K
    {'.', '-', '.', '.', '-', '.'}, // L
    {'-', '-', '.', '-', '.', '-'}, // M
    {'-', '-', '-', '-', '.', '-'}, // N
    {'-', '--', '-', '-', '-', '-'}, // O
    {'.', '--', '-', '-', '-', '.'}, // P
    {'-', '--', '.', '-', '-', '.'}, // Q
    {'.', '-', '-', '.', '-', '.'}, // R
    {'.', '.', '.', '.', '.', '-'}, // S
    {'-', '.', '.', '.', '.', '-'}, // T
    {'.', '.', '-', '.', '.', '-'}, // U
    {'.', '.', '.', '-', '-', '.'}, // V
    {'.', '-', '-', '-', '.', '-'}, // W
    {'-', '-', '-', '.', '.', '-'}, // X
    {'-', '-', '.', '-', '-', '.'}, // Y
    {'-', '-', '.', '-', '.', '-'}  // Z
};

// Function to convert a character to Morse code
void char_to_morse(char character, char *morse_code) {
    int index = character - 'A';
    if (index >= 0 && index < 26) {
        strcpy(morse_code, morse_table[index]);
    } else {
        strcpy(morse_code, " ");
    }
}

// Function to convert a text string to Morse code
void text_to_morse(char *text, char *morse_code) {
    int i, j;
    char morse_character[6];

    for (i = 0, j = 0; i < strlen(text); i++) {
        char_to_morse(text[i], morse_character);
        strcat(morse_code, morse_character);
        if (text[i] != ' ') {
            strcat(morse_code, " ");
        }
    }
}

// Main function
int main() {
    char text[MAX_TEXT_LENGTH];
    char morse_code[MAX_TEXT_LENGTH * 5];

    printf("Enter the text to be converted to Morse code: ");
    scanf("%[^\n]%*c", text);

    text_to_morse(text, morse_code);

    printf("Morse code: %s\n", morse_code);

    return 0;
}