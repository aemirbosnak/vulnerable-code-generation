//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1024
#define MAX_MORSE_LEN 4096

// Morse code character mappings
char* morse_codes[] = {
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-..",   // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--..",   // Z
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    "-.--.-", // CH
    "-..-.",  // NG
    "--..--", // SH
    "....-",  // TH
    "-----.", // WH
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_codes[index];
    } else if (c >= '0' && c <= '9') {
        return morse_codes[index + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char* text_to_morse(char* text) {
    char* morse_code = malloc(MAX_MORSE_LEN);
    morse_code[0] = '\0';
    int i = 0;
    while (text[i] != '\0') {
        char* morse_char = char_to_morse(text[i]);
        if (morse_char != NULL) {
            strcat(morse_code, morse_char);
            strcat(morse_code, " ");
        }
        i++;
    }
    return morse_code;
}

// Main function
int main() {
    char text[MAX_TEXT_LEN];
    printf("Enter the text to convert to Morse code: ");
    fgets(text, MAX_TEXT_LEN, stdin);

    char* morse_code = text_to_morse(text);
    printf("Morse code: %s\n", morse_code);

    free(morse_code);
    return 0;
}