//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
struct AlienDictionary {
    char alienSymbol;
    char englishLetter;
};

// Create an array of AlienDictionary structs to store the dictionary
struct AlienDictionary dictionary[] = {
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
    {'Z', 'z'}
};

// Get the size of the Alien language dictionary
int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

// Function to translate an Alien word to English
char *translateAlienToEnglish(char *alienWord) {
    // Allocate memory for the English translation
    char *englishTranslation = malloc(strlen(alienWord) + 1);

    // Loop through each character in the Alien word
    for (int i = 0; i < strlen(alienWord); i++) {
        // Find the corresponding English letter in the dictionary
        for (int j = 0; j < dictionarySize; j++) {
            if (dictionary[j].alienSymbol == alienWord[i]) {
                englishTranslation[i] = dictionary[j].englishLetter;
                break;
            }
        }
    }

    // Add the null terminator to the English translation
    englishTranslation[strlen(alienWord)] = '\0';

    // Return the English translation
    return englishTranslation;
}

// Function to translate an English word to Alien
char *translateEnglishToAlien(char *englishWord) {
    // Allocate memory for the Alien translation
    char *alienTranslation = malloc(strlen(englishWord) + 1);

    // Loop through each character in the English word
    for (int i = 0; i < strlen(englishWord); i++) {
        // Find the corresponding Alien symbol in the dictionary
        for (int j = 0; j < dictionarySize; j++) {
            if (dictionary[j].englishLetter == englishWord[i]) {
                alienTranslation[i] = dictionary[j].alienSymbol;
                break;
            }
        }
    }

    // Add the null terminator to the Alien translation
    alienTranslation[strlen(englishWord)] = '\0';

    // Return the Alien translation
    return alienTranslation;
}

int main() {
    // Get the Alien word from the user
    char alienWord[101];
    printf("Enter an Alien word: ");
    scanf("%s", alienWord);

    // Translate the Alien word to English
    char *englishTranslation = translateAlienToEnglish(alienWord);

    // Print the English translation
    printf("English translation: %s\n", englishTranslation);

    // Get the English word from the user
    char englishWord[101];
    printf("Enter an English word: ");
    scanf("%s", englishWord);

    // Translate the English word to Alien
    char *alienTranslation = translateEnglishToAlien(englishWord);

    // Print the Alien translation
    printf("Alien translation: %s\n", alienTranslation);

    // Free the memory allocated for the translations
    free(englishTranslation);
    free(alienTranslation);

    return 0;
}