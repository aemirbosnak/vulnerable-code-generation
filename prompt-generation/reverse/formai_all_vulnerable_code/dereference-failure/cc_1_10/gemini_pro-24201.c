//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int translate(char *input);
void print_translation(int translation);

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an input
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    // Translate the input
    int translation = translate(argv[1]);

    // Print the translation
    print_translation(translation);

    return 0;
}

// Translate the input
int translate(char *input) {
    int translation = 0;

    // Loop through the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current character is a consonant
        if (strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", input[i]) != NULL) {
            // Add the value of the consonant to the translation
            translation += input[i] - 'a' + 1;
        }
        // Check if the current character is a vowel
        else if (strchr("aeiouAEIOU", input[i]) != NULL) {
            // Add the value of the vowel to the translation
            translation += input[i] - 'a' + 5;
        }
    }

    return translation;
}

// Print the translation
void print_translation(int translation) {
    printf("The translation is: %d\n", translation);
}