//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Define the symbol table for the Alien Language
#define SYMBOL_COUNT 10
const char *symbol_table[] = {"%", "*", "+", "-", "/", "<", ">", "(", ")", ";"};

// Define helper functions for lookup and conversion
int lookup_symbol(char c) {
    for (int i = 0; i < SYMBOL_COUNT; i++) {
        if (c == symbol_table[i][0]) {
            return i;
        }
    }
    return -1;
}

char *convert_to_alien_language(char *input) {
    int len = strlen(input);
    char *output = (char*) malloc(sizeof(char) * (len * 2 + 1));
    int output_index = 0;
    for (int i = 0; i < len; i++) {
        int symbol_index = lookup_symbol(input[i]);
        if (symbol_index >= 0) {
            output[output_index++] = '<';
            for (int j = 0; j < symbol_index+1; j++) {
                output[output_index++] = '*';
            }
            output[output_index++] = '>';
        } else {
            output[output_index++] = input[i];
        }
    }
    output[output_index] = '\0';
    return output;
}

char *convert_from_alien_language(char *input) {
    int len = strlen(input);
    char *output = (char*) malloc(sizeof(char) * (len + 1));
    int output_index = 0;
    int is_converting_symbol = 0;
    int symbol_count = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            is_converting_symbol = 1;
            symbol_count = 0;
        } else if (input[i] == '>') {
            is_converting_symbol = 0;
            output[output_index++] = symbol_table[symbol_count-1][0];
        } else if (is_converting_symbol && input[i] == '*') {
            symbol_count++;
        } else {
            output[output_index++] = input[i];
        }
    }
    output[output_index] = '\0';
    return output;
}

int main() {
    // Translate input to the Alien Language
    char input[100];
    printf("Enter input in English: ");
    scanf("%[^\n]", input);
    char *alien_language = convert_to_alien_language(input);
    printf("Input in Alien Language: %s\n", alien_language);

    // Translate Alien Language back to English
    char *english = convert_from_alien_language(alien_language);
    printf("Translated back to English: %s\n", english);

    // Cleanup memory
    free(alien_language);
    free(english);

    return 0;
}