//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define ALIEN_LANGUAGE_LENGTH 5
#define DICTIONARY_SIZE 10

// Alien language structure to hold word mappings
typedef struct {
    char earthWord[MAX_LENGTH];
    char alienWord[ALIEN_LANGUAGE_LENGTH];
} AlienDictionary;

// Sample dictionary of Earth words to Alien words
AlienDictionary dictionary[DICTIONARY_SIZE] = {
    {"hello", "hvx10"},
    {"world", "zeta2"},
    {"friend", "quz5a"},
    {"alien", "xylor"},
    {"language", "jneb4"},
    {"planet", "xiq32"},
    {"star", "b1a"},
    {"dark", "plq5"},
    {"light", "iit10"},
    {"code", "zafg7"}
};

// Function to translate Earth words to Alien language
void translateToAlien(const char *earthWord, char *alienWord) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(earthWord, dictionary[i].earthWord) == 0) {
            strcpy(alienWord, dictionary[i].alienWord);
            return;
        }
    }
    // If no match is found
    strcpy(alienWord, "unknown");
}

// Function to display translations
void displayTranslations(const char *earthText) {
    char *token;
    char alienTranslation[MAX_LENGTH] = "";
    char alienWord[ALIEN_LANGUAGE_LENGTH];

    // Split the input text into words
    token = strtok((char *)earthText, " ");
    while (token != NULL) {
        translateToAlien(token, alienWord);
        strcat(alienTranslation, alienWord);
        strcat(alienTranslation, " ");
        token = strtok(NULL, " ");
    }

    printf("Earth: %s\n", earthText);
    printf("Alien: %s\n", alienTranslation);
}

// Main function to interact with user
int main() {
    char earthText[MAX_LENGTH];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a sentence in Earth language (max 255 characters):\n");

    // Read input from user
    if (fgets(earthText, sizeof(earthText), stdin) != NULL) {
        // Remove trailing newline character
        size_t length = strlen(earthText);
        if (length > 0 && earthText[length - 1] == '\n') {
            earthText[length - 1] = '\0';
        }
    }

    // Display translation
    displayTranslations(earthText);
    
    return 0;
}