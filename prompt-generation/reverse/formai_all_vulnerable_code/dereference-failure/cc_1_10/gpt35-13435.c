//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language mapping
char* alienChars[] = {"%", "#", "$", "&", "*", "(", ")", "+", "-", "/", "<", ">", "=", "?"};

// Define the English language mapping
char* englishChars[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Translate an alien character to English
char translate(char alienChar) {
    // Loop through the alien character mapping and find the matching English character
    for (int i = 0; i < sizeof(alienChars) / sizeof(char*); i++) {
        if (alienChar == alienChars[i][0]) {
            return englishChars[i][0];
        }
    }
    // If no match is found, return the same character
    return alienChar;
}

int main() {
    // Welcome message
    printf("Welcome to the C Alien Language Translator!\n");
    printf("-------------------------------------------\n\n");

    // Get the input from the user
    char* input = (char*)malloc(256 * sizeof(char));
    printf("Please enter an alien language text to translate to English:\n");
    scanf("%[^\n]s", input);

    // Translate the input to English
    int inputLength = strlen(input);
    char* output = (char*)malloc((inputLength + 1) * sizeof(char));
    for (int i = 0; i < inputLength; i++) {
        output[i] = translate(input[i]);
    }
    output[inputLength] = '\0';

    // Print the translated text
    printf("\nTranslated text:\n%s\n\n", output);

    // Cleanup
    free(input);
    free(output);

    // Exit
    return 0;
}