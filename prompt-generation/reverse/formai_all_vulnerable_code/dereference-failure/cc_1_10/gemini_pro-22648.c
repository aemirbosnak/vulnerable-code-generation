//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
};

// Define the English language dictionary
const char *english_dictionary[] = {
    "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel",
    "india", "juliet", "kilo", "lima", "mike", "november", "oscar", "papa",
    "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey",
    "x-ray", "yankee", "zulu"
};

// Translate an alien word to English
char *alien_to_english(const char *alien_word) {
    // Allocate memory for the translated word
    char *english_word = malloc(strlen(alien_word) + 1);

    // Translate each character in the alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the index of the character in the alien dictionary
        int alien_index = -1;
        for (int j = 0; j < 26; j++) {
            if (strcmp(alien_word[i], alien_dictionary[j]) == 0) {
                alien_index = j;
                break;
            }
        }

        // If the character is not found in the alien dictionary, return NULL
        if (alien_index == -1) {
            free(english_word);
            return NULL;
        }

        // Append the corresponding English character to the translated word
        english_word[i] = english_dictionary[alien_index];
    }

    // Terminate the translated word with a null character
    english_word[strlen(alien_word)] = '\0';

    // Return the translated word
    return english_word;
}

// Translate an English word to alien
char *english_to_alien(const char *english_word) {
    // Allocate memory for the translated word
    char *alien_word = malloc(strlen(english_word) + 1);

    // Translate each character in the English word
    for (int i = 0; i < strlen(english_word); i++) {
        // Find the index of the character in the English dictionary
        int english_index = -1;
        for (int j = 0; j < 26; j++) {
            if (strcmp(english_word[i], english_dictionary[j]) == 0) {
                english_index = j;
                break;
            }
        }

        // If the character is not found in the English dictionary, return NULL
        if (english_index == -1) {
            free(alien_word);
            return NULL;
        }

        // Append the corresponding alien character to the translated word
        alien_word[i] = alien_dictionary[english_index];
    }

    // Terminate the translated word with a null character
    alien_word[strlen(english_word)] = '\0';

    // Return the translated word
    return alien_word;
}

// Test the alien language translator
int main() {
    // Test the alien_to_english function
    char *alien_word = "abc";
    char *english_word = alien_to_english(alien_word);
    printf("%s -> %s\n", alien_word, english_word);
    free(english_word);

    // Test the english_to_alien function
    english_word = "alpha";
    alien_word = english_to_alien(english_word);
    printf("%s -> %s\n", english_word, alien_word);
    free(alien_word);

    return 0;
}