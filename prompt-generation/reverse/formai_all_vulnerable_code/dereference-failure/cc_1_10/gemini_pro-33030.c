//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Array of characters that correspond to the morse code table
char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

// Function to convert a character to morse code
char *char_to_morse(char character) {
    int index = strchr(characters, character) - characters;
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else if (index >= 26 && index < 36) {
        return morse_table[index - 26];
    } else {
        return NULL;
    }
}

// Function to convert a string to morse code
char *string_to_morse(char *string) {
    char *morse_code = malloc(strlen(string) * 5);
    int i, j;
    for (i = 0, j = 0; i < strlen(string); i++) {
        char *morse = char_to_morse(string[i]);
        if (morse != NULL) {
            strcpy(morse_code + j, morse);
            j += strlen(morse);
            morse_code[j++] = ' ';
        }
    }
    morse_code[j - 1] = '\0';
    return morse_code;
}

// Function to print morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    char *string = "SOS";
    char *morse_code = string_to_morse(string);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}