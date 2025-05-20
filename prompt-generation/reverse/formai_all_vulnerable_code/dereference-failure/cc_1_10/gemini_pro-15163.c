//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the dictionary of Cat Language to English words
const char *cat_to_english_dict[] = {
    "meow", "food",
    "purr", "happy",
    "hiss", "angry",
    "chirp", "excited",
    "yowl", "sad",
    "meow", "hungry",
    "rub", "affectionate",
    "scratch", "playful",
    "bite", "aggressive",
    "groom", "clean",
    "sleep", "tired",
    "stare", "curious",
    "wag", "friendly",
    "meow", "attention",
    "meow", "love",
    "meow", "goodbye"
};

// Function to translate Cat Language to English
char *cat_to_english(const char *cat_language) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(cat_language) + 1);

    // Initialize the English translation to empty string
    strcpy(english_translation, "");

    // Loop through the dictionary and find the matching English word
    for (int i = 0; i < sizeof(cat_to_english_dict) / sizeof(char *); i += 2) {
        if (strcmp(cat_language, cat_to_english_dict[i]) == 0) {
            strcpy(english_translation, cat_to_english_dict[i + 1]);
            break;
        }
    }

    // Return the English translation
    return english_translation;
}

// Function to translate English to Cat Language
char *english_to_cat(const char *english_word) {
    // Allocate memory for the Cat Language translation
    char *cat_language_translation = malloc(strlen(english_word) + 1);

    // Initialize the Cat Language translation to empty string
    strcpy(cat_language_translation, "");

    // Loop through the dictionary and find the matching Cat Language word
    for (int i = 0; i < sizeof(cat_to_english_dict) / sizeof(char *); i += 2) {
        if (strcmp(english_word, cat_to_english_dict[i + 1]) == 0) {
            strcpy(cat_language_translation, cat_to_english_dict[i]);
            break;
        }
    }

    // Return the Cat Language translation
    return cat_language_translation;
}

// Main function
int main() {
    // Get the Cat Language input from the user
    char cat_language[100];
    printf("Enter the Cat Language: ");
    scanf("%s", cat_language);

    // Translate the Cat Language to English
    char *english_translation = cat_to_english(cat_language);

    // Print the English translation
    printf("English Translation: %s\n", english_translation);

    // Get the English input from the user
    char english_word[100];
    printf("Enter the English word: ");
    scanf("%s", english_word);

    // Translate the English word to Cat Language
    char *cat_language_translation = english_to_cat(english_word);

    // Print the Cat Language translation
    printf("Cat Language Translation: %s\n", cat_language_translation);

    // Free the allocated memory
    free(english_translation);
    free(cat_language_translation);

    return 0;
}