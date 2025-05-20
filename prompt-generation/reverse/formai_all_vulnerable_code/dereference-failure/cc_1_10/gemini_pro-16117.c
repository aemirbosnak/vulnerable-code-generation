//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
// This dictionary maps each Alien character to its corresponding English character
const char *alienDictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " "
};

// Define the English language dictionary
// This dictionary maps each English character to its corresponding Alien character
const char *englishDictionary[] = {
    "e", "t", "a", "o", "i", "n", "s", "h", "r", "d",
    "l", "c", "u", "m", "w", "f", "g", "y", "p", "b",
    "v", "k", "j", "x", "q", "z", " "
};

// Translate an Alien word to English
char *translateAlienToEnglish(char *alienWord) {
    // Allocate memory for the translated word
    char *englishWord = malloc(strlen(alienWord) + 1);

    // Initialize the translated word
    strcpy(englishWord, "");

    // Translate each character in the Alien word
    for (int i = 0; i < strlen(alienWord); i++) {
        // Find the corresponding English character in the dictionary
        for (int j = 0; j < 27; j++) {
            if (strcmp(alienDictionary[j], &alienWord[i]) == 0) {
                // Append the English character to the translated word
                strcat(englishWord, englishDictionary[j]);
            }
        }
    }

    // Return the translated word
    return englishWord;
}

// Translate an English word to Alien
char *translateEnglishToAlien(char *englishWord) {
    // Allocate memory for the translated word
    char *alienWord = malloc(strlen(englishWord) + 1);

    // Initialize the translated word
    strcpy(alienWord, "");

    // Translate each character in the English word
    for (int i = 0; i < strlen(englishWord); i++) {
        // Find the corresponding Alien character in the dictionary
        for (int j = 0; j < 27; j++) {
            if (strcmp(englishDictionary[j], &englishWord[i]) == 0) {
                // Append the Alien character to the translated word
                strcat(alienWord, alienDictionary[j]);
            }
        }
    }

    // Return the translated word
    return alienWord;
}

// Main function
int main() {
    // Get the Alien word from the user
    char *alienWord = malloc(100);
    printf("Enter an Alien word: ");
    scanf("%s", alienWord);

    // Translate the Alien word to English
    char *englishWord = translateAlienToEnglish(alienWord);

    // Print the English translation
    printf("English translation: %s\n", englishWord);

    // Free the allocated memory
    free(alienWord);
    free(englishWord);

    return 0;
}