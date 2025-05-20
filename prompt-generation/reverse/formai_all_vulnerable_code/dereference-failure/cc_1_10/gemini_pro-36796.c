//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language vocabulary
const char *alien_vocabulary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ","
};

// Define the number of words in the alien language vocabulary
const int num_alien_words = sizeof(alien_vocabulary) / sizeof(char *);

// Define the maximum length of an alien word
const int max_alien_word_length = 10;

// Function to translate an alien word into English
char *translate_alien_word(const char *alien_word) {
    // Allocate memory for the translated word
    char *english_word = malloc(max_alien_word_length + 1);

    // Initialize the translated word
    english_word[0] = '\0';

    // Loop through the alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the corresponding English word in the vocabulary
        for (int j = 0; j < num_alien_words; j++) {
            if (strcmp(alien_word[i], alien_vocabulary[j]) == 0) {
                // Append the corresponding English word to the translated word
                strcat(english_word, alien_vocabulary[j]);
                break;
            }
        }
    }

    // Return the translated word
    return english_word;
}

// Function to translate an alien sentence into English
char *translate_alien_sentence(const char *alien_sentence) {
    // Allocate memory for the translated sentence
    char *english_sentence = malloc(strlen(alien_sentence) + 1);

    // Initialize the translated sentence
    english_sentence[0] = '\0';

    // Loop through the alien sentence
    for (int i = 0; i < strlen(alien_sentence); i++) {
        // Find the corresponding English word in the vocabulary
        for (int j = 0; j < num_alien_words; j++) {
            if (strcmp(alien_sentence[i], alien_vocabulary[j]) == 0) {
                // Append the corresponding English word to the translated sentence
                strcat(english_sentence, alien_vocabulary[j]);
                break;
            }
        }
    }

    // Return the translated sentence
    return english_sentence;
}

// Main function
int main() {
    // Get the alien word or sentence to be translated
    char alien_input[max_alien_word_length + 1];
    printf("Enter an alien word or sentence to be translated: ");
    scanf("%s", alien_input);

    // Translate the alien word or sentence
    char *english_output;
    if (strlen(alien_input) == 1) {
        english_output = translate_alien_word(alien_input);
    } else {
        english_output = translate_alien_sentence(alien_input);
    }

    // Print the translated word or sentence
    printf("Translated output: %s\n", english_output);

    // Free the allocated memory
    free(english_output);

    return 0;
}