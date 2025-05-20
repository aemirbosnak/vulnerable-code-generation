//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Morse code character to ASCII code conversion table
struct morse_code {
    char character;
    char *morse_code;
};

struct morse_code morse_code_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', " "}
};

// Function to convert a character to its Morse code representation
char *character_to_morse(char character) {
    int i;
    for (i = 0; i < sizeof(morse_code_table) / sizeof(struct morse_code); i++) {
        if (toupper(character) == morse_code_table[i].character) {
            return morse_code_table[i].morse_code;
        }
    }
    return NULL;
}

// Function to convert a string to its Morse code representation
char *string_to_morse(char *string) {
    int i, j;
    char *morse_code = malloc(1000);
    morse_code[0] = '\0';
    for (i = 0; string[i] != '\0'; i++) {
        char *character_morse_code = character_to_morse(string[i]);
        if (character_morse_code != NULL) {
            strcat(morse_code, character_morse_code);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

// Function to print the Morse code representation of a string
void print_morse_code(char *morse_code) {
    int i;
    for (i = 0; morse_code[i] != '\0'; i++) {
        if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("-");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char string[] = "HELLO WORLD";
    char *morse_code = string_to_morse(string);
    print_morse_code(morse_code);
    return 0;
}