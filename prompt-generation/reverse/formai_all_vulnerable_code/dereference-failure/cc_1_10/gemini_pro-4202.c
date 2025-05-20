//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
// Alien Language Translator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language alphabet and its English equivalents
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char english_equivalents[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to translate an alien word into English
char* translate_alien_word(char* alien_word) {
    // Allocate memory for the translated word
    char* english_word = malloc(strlen(alien_word) + 1);

    // Iterate over each character in the alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the index of the character in the alien alphabet
        int index = strchr(alien_alphabet, alien_word[i]) - alien_alphabet;

        // If the character is not found in the alien alphabet, return an error message
        if (index == -1) {
            free(english_word);
            return "Invalid alien word";
        }

        // Translate the character to its English equivalent
        english_word[i] = english_equivalents[index];
    }

    // Add a null terminator to the end of the translated word
    english_word[strlen(alien_word)] = '\0';

    // Return the translated word
    return english_word;
}

// Function to test the alien language translator
int main() {
    // Define some alien words
    char* alien_words[] = {"aof", "bdg", "ceh", "dif", "egj"};

    // Translate each alien word into English
    for (int i = 0; i < 5; i++) {
        char* english_word = translate_alien_word(alien_words[i]);

        // Print the translated word
        printf("%s -> %s\n", alien_words[i], english_word);

        // Free the memory allocated for the translated word
        free(english_word);
    }

    return 0;
}