//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the alien language dictionary
const char *alien_language_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ".", ","
};

// Function to translate a string from English to the alien language
char *translate_to_alien_language(const char *english_string) {
    // Allocate memory for the translated string
    char *alien_string = malloc(strlen(english_string) + 1);

    // Translate each character in the English string to its alien language equivalent
    for (int i = 0; i < strlen(english_string); i++) {
        for (int j = 0; j < sizeof(alien_language_dictionary) / sizeof(char *); j++) {
            if (english_string[i] == alien_language_dictionary[j][0]) {
                alien_string[i] = alien_language_dictionary[j][1];
                break;
            }
        }
    }

    // Add a null terminator to the end of the translated string
    alien_string[strlen(english_string)] = '\0';

    // Return the translated string
    return alien_string;
}

// Function to translate a string from the alien language to English
char *translate_from_alien_language(const char *alien_string) {
    // Allocate memory for the translated string
    char *english_string = malloc(strlen(alien_string) + 1);

    // Translate each character in the alien language string to its English equivalent
    for (int i = 0; i < strlen(alien_string); i++) {
        for (int j = 0; j < sizeof(alien_language_dictionary) / sizeof(char *); j++) {
            if (alien_string[i] == alien_language_dictionary[j][1]) {
                english_string[i] = alien_language_dictionary[j][0];
                break;
            }
        }
    }

    // Add a null terminator to the end of the translated string
    english_string[strlen(alien_string)] = '\0';

    // Return the translated string
    return english_string;
}

// Main function
int main() {
    // Get the English string from the user
    char english_string[100];
    printf("Enter an English string: ");
    scanf("%s", english_string);

    // Translate the English string to the alien language
    char *alien_string = translate_to_alien_language(english_string);

    // Print the translated string
    printf("Alien language string: %s\n", alien_string);

    // Translate the alien language string to English
    char *translated_english_string = translate_from_alien_language(alien_string);

    // Print the translated English string
    printf("Translated English string: %s\n", translated_english_string);

    // Free the memory allocated for the translated strings
    free(alien_string);
    free(translated_english_string);

    return 0;
}