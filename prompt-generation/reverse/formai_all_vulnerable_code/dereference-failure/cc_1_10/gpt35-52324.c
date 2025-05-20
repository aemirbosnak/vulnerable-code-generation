//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
/******************************************************
 *                                                   *
 *  Alien Language Translator                        *
 *                                                   *
 *  Author: Your Name Here                           *
 *  Date: Today's Date                               *
 *                                                   *
 ******************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Struct to represent an Alien Language
typedef struct AlienLanguage {
    char name[MAX_LENGTH];
    char translation_table[26];
} AlienLanguage;

// Function to translate a given word from an alien language
char* translate_word(char word[], AlienLanguage alien_language) {
    int i;
    char* translated_word = (char*) malloc(strlen(word) + 1);
    for (i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a'; // Get the alphabetic index of the current letter
        if (index < 0 || index > 25) { // If it is not a valid alphabetic character
            translated_word[i] = word[i]; // Copy it directly
        } else {
            translated_word[i] = alien_language.translation_table[index]; // Translate it
        }
    }
    translated_word[i] = '\0'; // Add the null character at the end
    return translated_word;
}

int main() {
    AlienLanguage alien_language;

    // Read the name and translation table of the alien language from the standard input
    printf("Enter the name of the alien language: ");
    scanf("%s", alien_language.name);
    printf("Enter the translation table of the alien language (26 lowercase letters without spaces): ");
    scanf("%s", alien_language.translation_table);

    // Print a welcome message and the name of the alien language
    printf("\nWelcome to the Alien Language Translator!\n\n");
    printf("You are now translating words from the \"%s\" language.\n\n", alien_language.name);

    // Read words from the standard input and translate them
    char word[MAX_LENGTH];
    while (1) {
        printf("Enter a word to translate (or 'quit' to exit): ");
        scanf("%s", word);
        if (strcmp(word, "quit") == 0) { // If the user inputs 'quit', exit the loop
            break;
        } else { // Otherwise, translate the word and print the result
            char* translated_word = translate_word(word, alien_language);
            printf("Translated word: %s\n\n", translated_word);
            free(translated_word);
        }
    }

    // Print a goodbye message
    printf("Thank you for using the Alien Language Translator!\n");

    return 0;
}