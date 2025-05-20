//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet.
const char *MORSE_CODE[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
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
};

// Convert a character to Morse code.
char *to_morse(char c) {
    char *morse_code = NULL;

    // Convert the character to uppercase.
    c = toupper(c);

    // Find the character in the Morse code alphabet.
    for (int i = 0; i < 26; i++) {
        if (c == 'A' + i) {
            morse_code = strdup(MORSE_CODE[i]);
            break;
        }
    }

    // If the character is not in the alphabet, return NULL.
    return morse_code;
}

// Convert a string to Morse code.
char *to_morse_string(char *str) {
    // Allocate memory for the Morse code string.
    char *morse_code = malloc(strlen(str) * 5);
    if (morse_code == NULL) {
        return NULL;
    }

    // Convert each character in the string to Morse code.
    char *ptr = morse_code;
    for (int i = 0; i < strlen(str); i++) {
        char *morse_code_char = to_morse(str[i]);
        if (morse_code_char == NULL) {
            free(morse_code);
            return NULL;
        }
        strcpy(ptr, morse_code_char);
        ptr += strlen(morse_code_char);
        free(morse_code_char);
        *ptr++ = ' ';
    }

    // Remove the trailing space.
    *--ptr = '\0';

    // Return the Morse code string.
    return morse_code;
}

// Print the Morse code string.
void print_morse_code(char *morse_code) {
    // Print the Morse code string, with spaces between the characters.
    printf("%s\n", morse_code);
}

int main() {
    // Get the input string.
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code.
    char *morse_code = to_morse_string(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code.\n");
        return EXIT_FAILURE;
    }

    // Print the Morse code string.
    print_morse_code(morse_code);

    // Free the memory allocated for the Morse code string.
    free(morse_code);

    return EXIT_SUCCESS;
}