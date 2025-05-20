//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Alien character mapping
const char *alienAlphabet[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ".", ",", "!",
    "?", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
};

const char *translatedAlphabet[] = {
    "@", "#", "$", "%", "^", "&", "*", "(", ")", "!",
    "~", "`", "-", "=", "+", "[", "]", "{", "}", "|", ";",
    ":", "\"", "'", "<", ">", "?", " ", ".", "/", "\\",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
};

// Function to translate to alien language
char* translateToAlien(const char *input) {
    size_t len = strlen(input);
    char *output = (char *)malloc(len * 3); // Allocate enough space
    output[0] = '\0'; // Initialize the output string

    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        // If character is lower-case letter, convert
        if (ch >= 'a' && ch <= 'z') {
            strcat(output, translatedAlphabet[ch - 'a']);
        } else if (ch >= 'A' && ch <= 'Z') { // If upper-case, convert to lower-case
            strcat(output, translatedAlphabet[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') { // If digit, directly translate
            strcat(output, translatedAlphabet[ch - '0' + 26]);
        } else {
            switch (ch) {
                case ' ':
                    strcat(output, " ");
                    break;
                case '.':
                    strcat(output, translatedAlphabet[26]);
                    break;
                case ',':
                    strcat(output, translatedAlphabet[27]);
                    break;
                case '!':
                    strcat(output, translatedAlphabet[28]);
                    break;
                case '?':
                    strcat(output, translatedAlphabet[29]);
                    break;
                default:
                    strcat(output, "?"); // If unknown, provide a placeholder
            }
        }
    }
    return output; // Return the translated string
}

// Function to clean input
void cleanInput(char *input) {
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] < ' ' || input[i] > '~') { // ASCII range check
            input[i] = ' '; // Replace invalid chars with space
        }
    }
}

// Main function
int main() {
    char input[256];
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter text to translate (max 255 characters): ");
    fgets(input, sizeof(input), stdin);

    cleanInput(input); // Clean the input text

    // Removing the new line character from fgets
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char *translatedText = translateToAlien(input);
    printf("Translated text (to Alien Language): %s\n", translatedText);
    
    free(translatedText); // Free allocated memory
    return 0;
}