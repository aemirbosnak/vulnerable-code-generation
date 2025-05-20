//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
    "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", "!", "@", "#", "$", "%", "^", "&", "*",
    "(", ")", "-", "+", "=", "/", "\\", "|", "[", "]",
    "{", "}"
};

// Define the English language dictionary
const char *english_dict[] = {
    "a", "bee", "see", "dee", "e", "ef", "gee", "aitch", "eye", "jay",
    "kay", "el", "em", "en", "o", "pee", "cue", "are", "ess", "tee",
    "you", "vee", "double-you", "ex", "why", "zee", "A", "Bee", "See", "Dee",
    "E", "Ef", "Gee", "Aitch", "Eye", "Jay", "Kay", "El", "Em", "En",
    "O", "Pee", "Cue", "Are", "Ess", "Tee", "You", "Vee", "Double-you", "Ex",
    "Why", "Zee", "zero", "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "exclamation mark", "at sign", "hash", "dollar sign", "percent", "caret", "ampersand", "asterisk",
    "left parenthesis", "right parenthesis", "hyphen", "plus", "equals", "slash", "backslash", "vertical bar", "left square bracket", "right square bracket",
    "left curly bracket", "right curly bracket"
};

// Function to translate a word from alien language to English
char *translate_alien_to_english(char *alien_word) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(alien_word) + 1);

    // Iterate over each character in the alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the index of the character in the alien dictionary
        int alien_index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char *); j++) {
            if (strcmp(alien_dict[j], alien_word[i]) == 0) {
                alien_index = j;
                break;
            }
        }

        // If the character is not found in the alien dictionary, return NULL
        if (alien_index == -1) {
            free(english_translation);
            return NULL;
        }

        // Get the English translation of the character
        english_translation[i] = english_dict[alien_index];
    }

    // Terminate the English translation with a null character
    english_translation[strlen(alien_word)] = '\0';

    // Return the English translation
    return english_translation;
}

// Function to translate a word from English to alien language
char *translate_english_to_alien(char *english_word) {
    // Allocate memory for the alien translation
    char *alien_translation = malloc(strlen(english_word) + 1);

    // Iterate over each character in the English word
    for (int i = 0; i < strlen(english_word); i++) {
        // Find the index of the character in the English dictionary
        int english_index = -1;
        for (int j = 0; j < sizeof(english_dict) / sizeof(char *); j++) {
            if (strcmp(english_dict[j], english_word[i]) == 0) {
                english_index = j;
                break;
            }
        }

        // If the character is not found in the English dictionary, return NULL
        if (english_index == -1) {
            free(alien_translation);
            return NULL;
        }

        // Get the alien translation of the character
        alien_translation[i] = alien_dict[english_index];
    }

    // Terminate the alien translation with a null character
    alien_translation[strlen(english_word)] = '\0';

    // Return the alien translation
    return alien_translation;
}

// Main function
int main() {
    // Get the alien word from the user
    char alien_word[100];
    printf("Enter the alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word to English
    char *english_translation = translate_alien_to_english(alien_word);

    // Print the English translation
    if (english_translation != NULL) {
        printf("The English translation is: %s\n", english_translation);
    } else {
        printf("Invalid alien word\n");
    }

    // Get the English word from the user
    char english_word[100];
    printf("Enter the English word: ");
    scanf("%s", english_word);

    // Translate the English word to alien language
    char *alien_translation = translate_english_to_alien(english_word);

    // Print the alien translation
    if (alien_translation != NULL) {
        printf("The alien translation is: %s\n", alien_translation);
    } else {
        printf("Invalid English word\n");
    }

    // Free the memory allocated for the translations
    free(english_translation);
    free(alien_translation);

    return 0;
}