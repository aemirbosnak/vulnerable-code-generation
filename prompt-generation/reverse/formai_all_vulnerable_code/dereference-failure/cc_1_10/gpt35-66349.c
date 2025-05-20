//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* translate(char* input) {
    // Check for null input
    if (!input) return NULL;

    // Null-terminate the input string (just in case)
    input[strlen(input)] = '\0';

    // Allocate memory for the output string. It will be at most
    // twice the length of the input string (since each character
    // can map to a 2-letter alien symbol).
    char* output = calloc(2 * strlen(input), sizeof(char));
    int output_len = 0;

    for (int i = 0; i < strlen(input); i++) {
        // Determine the alien symbol for this character
        char alien[3];
        switch (input[i]) {
            case 'A':
                strncpy(alien, "ZM", sizeof(alien));
                break;
            case 'B':
                strncpy(alien, "XJ", sizeof(alien));
                break;
            case 'C':
                strncpy(alien, "KP", sizeof(alien));
                break;
            // Add more cases for other characters in the alphabet
            // ...
            default:
                // If the character is not recognized, skip it
                continue;
        }

        // Add the alien symbol to the output string
        strncpy(output + output_len, alien, sizeof(alien));
        output_len += 2;
    }

    // Null-terminate the output string
    output[output_len] = '\0';

    return output;
}

int main() {
    printf("Enter a message to translate to alien language:\n");

    // Read a line of input from the user
    char input[MAX_LEN];
    fgets(input, sizeof(input), stdin);

    // Translate the input message
    char* output = translate(input);

    // Print the translated message
    printf("Translated message: %s\n", output);

    // Free the memory allocated for the output string
    free(output);

    return 0;
}