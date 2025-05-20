//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " ",      // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else if (c >= '0' && c <= '9') {
        return morse_table[26 + (c - '0')];
    } else if (c == ' ') {
        return morse_table[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(const char *str) {
    char *morse_code = malloc(strlen(str) * 5); // Allocate enough space for the Morse code
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcpy(morse_code + index, morse);
            index += strlen(morse);
            morse_code[index++] = ' '; // Add a space between characters
        }
    }
    morse_code[index - 1] = '\0'; // Remove the last space
    return morse_code;
}

// Print the Morse code
void print_morse_code(const char *morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}