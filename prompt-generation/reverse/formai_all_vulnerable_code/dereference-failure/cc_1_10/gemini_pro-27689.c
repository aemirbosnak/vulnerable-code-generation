//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-.-", "---.", ".-.-", ".-.",
    "...", "-", "..-", "-.--", "-..-"
};

// Convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32; // Convert to uppercase
    }

    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
    char* morse_code = malloc(strlen(str) * 5 + 1); // Allocate enough space for the Morse code
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        char* morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_code, morse_char);
            strcat(morse_code, " ");
        }
    }

    morse_code[strlen(morse_code) - 1] = '\0'; // Remove the trailing space
    return morse_code;
}

// Print the Morse code
void print_morse_code(char* morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    // Get the input string
    char str[101];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char* morse_code = string_to_morse(str);

    // Print the Morse code
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}