//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a dictionary of Alien words and their Earth equivalents.
const char *alien_dictionary[] = {
    "floop", "hello",
    "blorf", "goodbye",
    "slithy", "friend",
    "tove", "enemy"
};

// Define the maximum length of a word in the Alien language.
#define MAX_WORD_LENGTH 20

// Create a function to translate an Alien word to Earth English.
char *translate_alien(const char *alien_word) {
    // Create a buffer to store the translated word.
    char *translated_word = malloc(MAX_WORD_LENGTH);

    // Loop through the dictionary to find the translation.
    for (int i = 0; i < sizeof(alien_dictionary) / sizeof(alien_dictionary[0]); i += 2) {
        if (strcmp(alien_word, alien_dictionary[i]) == 0) {
            strcpy(translated_word, alien_dictionary[i + 1]);
            break;
        }
    }

    // If the word was not found in the dictionary, return NULL.
    if (translated_word[0] == '\0') {
        return NULL;
    }

    // Return the translated word.
    return translated_word;
}

// Create a function to translate a sentence from Alien to English.
char *translate_sentence(const char *alien_sentence) {
    // Create a buffer to store the translated sentence.
    char *translated_sentence = malloc(strlen(alien_sentence) * MAX_WORD_LENGTH);

    // Split the sentence into words.
    char *token = strtok(alien_sentence, " ");

    // Loop through the words in the sentence.
    while (token != NULL) {
        // Translate the word.
        char *translated_word = translate_alien(token);

        // Append the translated word to the sentence.
        strcat(translated_sentence, translated_word);
        strcat(translated_sentence, " ");

        // Get the next word.
        token = strtok(NULL, " ");
    }

    // Remove the trailing space from the sentence.
    translated_sentence[strlen(translated_sentence) - 1] = '\0';

    // Return the translated sentence.
    return translated_sentence;
}

// Create a main function to test the translator.
int main() {
    // Get the Alien sentence from the user.
    char alien_sentence[MAX_WORD_LENGTH];
    printf("Enter an Alien sentence to translate: ");
    scanf("%s", alien_sentence);

    // Translate the sentence.
    char *translated_sentence = translate_sentence(alien_sentence);

    // Print the translated sentence.
    printf("The translated sentence is: %s\n", translated_sentence);

    // Free the memory allocated for the translated sentence.
    free(translated_sentence);

    return 0;
}