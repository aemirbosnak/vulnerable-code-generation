//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a function to convert a string to alien language
void alien_convert(char* input, char* output) {
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is an alphabet
        if (isalpha(input[i])) {
            // Convert the alphabet to its corresponding alien language character
            char alien_char = 'A' + (input[i] - 'a');
            // Append the alien character to the output string
            output[i] = alien_char;
        } else {
            // Keep the non-alphabet characters as they are
            output[i] = input[i];
        }
    }
}

// Define a function to translate an input string to alien language
void translate(char* input) {
    // Allocate memory for the output string
    char* output = (char*) malloc(strlen(input) + 1);
    if (output == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Convert the input string to alien language
    alien_convert(input, output);

    // Print the translated string
    printf("Translated string: %s\n", output);

    // Free the allocated memory
    free(output);
}

int main() {
    // Prompt the user to enter a string to translate
    printf("Enter a string to translate: ");
    char* input = (char*) malloc(100);
    scanf("%s", input);

    // Call the translate function
    translate(input);

    return 0;
}