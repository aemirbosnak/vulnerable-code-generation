//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
typedef struct {
    char character;
    char *code;
} MorseCode;

MorseCode morse_code_table[] = {
    { 'A', ".-" },
    { 'B', "-..." },
    { 'C', "-.-." },
    { 'D', "-.." },
    { 'E', "." },
    { 'F', "..-." },
    { 'G', "--." },
    { 'H', "...." },
    { 'I', ".." },
    { 'J', ".---" },
    { 'K', "-.-" },
    { 'L', ".-.." },
    { 'M', "--" },
    { 'N', "-." },
    { 'O', "---" },
    { 'P', ".--." },
    { 'Q', "--.-" },
    { 'R', ".-." },
    { 'S', "..." },
    { 'T', "-" },
    { 'U', "..-"},
    { 'V', "...-" },
    { 'W', ".--" },
    { 'X', "-..-"},
    { 'Y', "-.--" },
    { 'Z', "--.." },
    { '0', "-----" },
    { '1', ".----" },
    { '2', "..---" },
    { '3', "...--" },
    { '4', "....-" },
    { '5', "....." },
    { '6', "-...." },
    { '7', "--..." },
    { '8', "---.." },
    { '9', "----." },
    { ' ', " " }
};

// Convert a character to its Morse code representation
char *to_morse_code(char character) {
    for (int i = 0; i < sizeof(morse_code_table) / sizeof(MorseCode); i++) {
        if (morse_code_table[i].character == character) {
            return morse_code_table[i].code;
        }
    }

    return NULL;
}

// Convert a string to its Morse code representation
char *to_morse_code_string(char *string) {
    char *morse_code_string = malloc(strlen(string) * 5); // Allocate enough space for the Morse code representation
    int index = 0;

    for (int i = 0; i < strlen(string); i++) {
        char *morse_code = to_morse_code(string[i]);
        if (morse_code != NULL) {
            strcpy(&morse_code_string[index], morse_code);
            index += strlen(morse_code);
            morse_code_string[index++] = ' '; // Add a space between each character's Morse code representation
        }
    }

    morse_code_string[index] = '\0'; // Terminate the string

    return morse_code_string;
}

// Print a string in Morse code
void print_morse_code(char *string) {
    char *morse_code_string = to_morse_code_string(string);

    for (int i = 0; i < strlen(morse_code_string); i++) {
        if (morse_code_string[i] == '.') {
            printf("Dit ");
        } else if (morse_code_string[i] == '-') {
            printf("Dah ");
        } else if (morse_code_string[i] == ' ') {
            printf(" ");
        }
    }

    printf("\n");

    free(morse_code_string);
}

int main() {
    char *string = "Hello World!";

    printf("Original string: %s\n", string);
    printf("Morse code representation: ");
    print_morse_code(string);

    return 0;
}