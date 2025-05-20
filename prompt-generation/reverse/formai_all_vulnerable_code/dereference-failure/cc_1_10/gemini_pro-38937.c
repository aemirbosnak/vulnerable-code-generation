//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the alien language alphabet
char *alien_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the translation table
char *translation_table[] = {
    "bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789bc"
};

// Translate a string from the alien language to English
char *translate_alien_to_english(char *alien_string) {
    char *english_string = malloc(strlen(alien_string) + 1);

    for (int i = 0; i < strlen(alien_string); i++) {
        char alien_character = alien_string[i];
        int index = strchr(alien_alphabet, alien_character) - alien_alphabet;

        if (index >= 0) {
            english_string[i] = translation_table[0][index];
        } else {
            english_string[i] = alien_character;
        }
    }

    english_string[strlen(alien_string)] = '\0';

    return english_string;
}

// Translate a string from English to the alien language
char *translate_english_to_alien(char *english_string) {
    char *alien_string = malloc(strlen(english_string) + 1);

    for (int i = 0; i < strlen(english_string); i++) {
        char english_character = english_string[i];
        int index = strchr(translation_table[0], english_character) - translation_table[0];

        if (index >= 0) {
            alien_string[i] = alien_alphabet[index];
        } else {
            alien_string[i] = english_character;
        }
    }

    alien_string[strlen(english_string)] = '\0';

    return alien_string;
}

// Main function
int main() {
    char *alien_string = "bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *english_string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789bc";

    // Translate the alien string to English
    char *translated_english_string = translate_alien_to_english(alien_string);

    // Print the translated English string
    printf("Alien string: %s\n", alien_string);
    printf("Translated English string: %s\n", translated_english_string);

    // Translate the English string to alien language
    char *translated_alien_string = translate_english_to_alien(english_string);

    // Print the translated alien language string
    printf("English string: %s\n", english_string);
    printf("Translated alien language string: %s\n", translated_alien_string);

    return 0;
}