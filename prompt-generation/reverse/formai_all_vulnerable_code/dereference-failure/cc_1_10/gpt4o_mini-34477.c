//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum length for the input and output
#define MAX_LEN 256

// Alien Language Mapping
const char *english[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " "
};

const char *alien[] = {
    "za", "yb", "xc", "wd", "ve", "uf", "tg", "sh", "ri", "qj", "pk", "ol", "mn", "nq", "po", "iq", "hr", "gs", "ft", "eu", "dv", "cz", "by", "ax", "zm", " "
};

// Function to translate English to Alien Language
void translateToAlien(const char *input, char *output) {
    size_t len = strlen(input);
    output[0] = '\0'; // Initialize output
    
    for (size_t i = 0; i < len; i++) {
        char c = tolower(input[i]); // Convert to lowercase
        if (c >= 'a' && c <= 'z') {
            // Find the index in the english array
            int index = c - 'a';
            strcat(output, alien[index]); // Append the alien equivalent
        } else if (c == ' ') {
            strcat(output, alien[26]); // Space
        }
    }
}

// Main function
int main() {
    char input[MAX_LEN];
    char output[MAX_LEN * 2]; // Output might be longer due to additional characters
    int continueTranslation = 1;

    printf("Welcome to the Alien Language Translator!\n");

    while (continueTranslation) {
        printf("Please enter a sentence to translate (or 'exit' to quit): ");
        fgets(input, MAX_LEN, stdin);

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            continueTranslation = 0;
            break;
        }

        // Translate to alien language
        translateToAlien(input, output);

        // Display the result
        printf("Translated to Alien Language: %s\n\n", output);
    }

    printf("Thank you for using the Alien Language Translator!\n");
    return 0;
}