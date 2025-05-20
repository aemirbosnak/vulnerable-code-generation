//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty language dictionary
static char *alien_dictionary[] = {
        "AA", "BB", "CC", "DD", "EE", "FF", "GG", "HH", "II", "JJ",
        "KK", "LL", "MM", "NN", "OO", "PP", "QQ", "RR", "SS", "TT",
        "UU", "VV", "WW", "XX", "YY", "ZZ", "11", "22", "33", "44",
        "55", "66", "77", "88", "99"
};

// Function to translate a single word from Alien to English
static char *alien_to_english(const char *alien_word) {
    int i;
    for (i = 0; i < sizeof(alien_dictionary) / sizeof(char *); i++) {
        if (strcmp(alien_word, alien_dictionary[i]) == 0) {
            return alien_dictionary[i];
        }
    }
    // If the word was not found in the dictionary, return NULL
    return NULL;
}

// Function to translate a whole sentence from Alien to English
static char *alien_to_english_sentence(const char *alien_sentence) {
    char *english_sentence = NULL;
    char *alien_word = NULL;
    int i;
    // Tokenize the alien sentence into individual words
    char *alien_words = strtok(alien_sentence, " ");
    while (alien_words != NULL) {
        // Translate each word from Alien to English
        alien_word = alien_to_english(alien_words);
        if (alien_word != NULL) {
            // Append the translated word to the English sentence
            english_sentence = realloc(english_sentence, strlen(english_sentence) + strlen(alien_word) + 2);
            strcat(english_sentence, alien_word);
            strcat(english_sentence, " ");
        }
        // Get the next word from the alien sentence
        alien_words = strtok(NULL, " ");
    }
    // Return the English sentence
    return english_sentence;
}

int main(void) {
    // Get the Alien sentence from the user
    char alien_sentence[100];
    printf("Enter an Alien sentence: ");
    fgets(alien_sentence, sizeof(alien_sentence), stdin);

    // Translate the Alien sentence to English
    char *english_sentence = alien_to_english_sentence(alien_sentence);
    if (english_sentence != NULL) {
        // Print the English sentence
        printf("English translation: %s", english_sentence);
        // Free the allocated memory
        free(english_sentence);
    } else {
        // If the sentence contains any unknown words, print an error message
        printf("Error: Unknown words in the Alien sentence.\n");
    }

    return 0;
}