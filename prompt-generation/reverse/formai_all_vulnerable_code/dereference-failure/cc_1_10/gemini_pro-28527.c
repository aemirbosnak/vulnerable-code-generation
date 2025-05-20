//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
typedef struct {
    char alien_char;
    char english_char;
} AlienDictionaryEntry;

AlienDictionaryEntry alien_dictionary[] = {
    {'A', 'a'},
    {'B', 'b'},
    {'C', 'c'},
    {'D', 'd'},
    {'E', 'e'},
    {'F', 'f'},
    {'G', 'g'},
    {'H', 'h'},
    {'I', 'i'},
    {'J', 'j'},
    {'K', 'k'},
    {'L', 'l'},
    {'M', 'm'},
    {'N', 'n'},
    {'O', 'o'},
    {'P', 'p'},
    {'Q', 'q'},
    {'R', 'r'},
    {'S', 's'},
    {'T', 't'},
    {'U', 'u'},
    {'V', 'v'},
    {'W', 'w'},
    {'X', 'x'},
    {'Y', 'y'},
    {'Z', 'z'},
    {' ', ' '}
};

// Function to translate an Alien word into English
char *alien_to_english(char *alien_word) {
    // Allocate memory for the English translation
    char *english_word = malloc(strlen(alien_word) + 1);

    // Iterate over each character in the Alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the corresponding English character in the dictionary
        for (int j = 0; j < sizeof(alien_dictionary) / sizeof(AlienDictionaryEntry); j++) {
            if (alien_word[i] == alien_dictionary[j].alien_char) {
                english_word[i] = alien_dictionary[j].english_char;
                break;
            }
        }
    }

    // Add the null terminator to the English translation
    english_word[strlen(alien_word)] = '\0';

    // Return the English translation
    return english_word;
}

// Function to translate an English word into Alien
char *english_to_alien(char *english_word) {
    // Allocate memory for the Alien translation
    char *alien_word = malloc(strlen(english_word) + 1);

    // Iterate over each character in the English word
    for (int i = 0; i < strlen(english_word); i++) {
        // Find the corresponding Alien character in the dictionary
        for (int j = 0; j < sizeof(alien_dictionary) / sizeof(AlienDictionaryEntry); j++) {
            if (english_word[i] == alien_dictionary[j].english_char) {
                alien_word[i] = alien_dictionary[j].alien_char;
                break;
            }
        }
    }

    // Add the null terminator to the Alien translation
    alien_word[strlen(english_word)] = '\0';

    // Return the Alien translation
    return alien_word;
}

// Main function
int main() {
    // Define the Alien and English words
    char alien_word[] = "ABC";
    char english_word[] = "abc";

    // Translate the Alien word into English
    char *english_translation = alien_to_english(alien_word);

    // Print the English translation
    printf("English translation: %s\n", english_translation);

    // Free the memory allocated for the English translation
    free(english_translation);

    // Translate the English word into Alien
    char *alien_translation = english_to_alien(english_word);

    // Print the Alien translation
    printf("Alien translation: %s\n", alien_translation);

    // Free the memory allocated for the Alien translation
    free(alien_translation);

    return 0;
}