//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

// Define the alien language mapping for each letter
const char *alien_mapping[26] = {
    "☀️", "🌙", "🌟", "🔆", "💫", "🌍", 
    "🌏", "🌎", "🌌", "🌈", "🍀", "🌻", 
    "🐉", "🚀", "⚡", "💧", "🔥", "🌊", 
    "🍄", "🌿", "🍬", "🍭", "🌸", "⭐", 
    "🌼", "🎨", "🎵", "🌏"
};

// Function to convert English to Alien Language
void translate_to_alien(char *input) {
    char *output = malloc(MAX_INPUT_LENGTH * 4); // Allocate memory for the output
    int output_index = 0;

    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {  // Lowercase letters
            output_index += sprintf(output + output_index, "%s", alien_mapping[ch - 'a']);
        } else if (ch >= 'A' && ch <= 'Z') {  // Uppercase letters
            output_index += sprintf(output + output_index, "%s", alien_mapping[ch - 'A']);
        } else {  // Non-alphabetical characters remain unchanged
            output[output_index++] = ch;
        }
    }
    output[output_index] = '\0';

    printf("Translated to Alien Language: %s\n", output);
    free(output);  // Free allocated memory
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence to translate into Alien Language (or 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        translate_to_alien(input);
    }

    return 0;
}