//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
char *alien_dict[] = {
    "Ack", "Bargle", "Cargle", "Doogle", "Eep", "Fizzle", "Gloop", "Honk", "Ickle", "Jibber",
    "Klingon", "Loopy", "Moop", "Noop", "Oodle", "Poodle", "Quibble", "Rattle", "Sprocket", "Toodle",
    "Ubble", "Vubble", "Wibble", "Xylophone", "Yackety", "Zany"
};

// Function to translate a word from English to Alien
char *translate_word(char *word) {
    // Get the length of the word
    int len = strlen(word);

    // Allocate memory for the translated word
    char *translated_word = malloc(len + 1);

    // Translate each character in the word
    for (int i = 0; i < len; i++) {
        char c = word[i];
        int index = c - 'a';
        translated_word[i] = alien_dict[index];
    }

    // Add the null terminator to the end of the translated word
    translated_word[len] = '\0';

    // Return the translated word
    return translated_word;
}

// Function to translate a sentence from English to Alien
char *translate_sentence(char *sentence) {
    // Get the length of the sentence
    int len = strlen(sentence);

    // Allocate memory for the translated sentence
    char *translated_sentence = malloc(len + 1);

    // Translate each word in the sentence
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        char *translated_word = translate_word(word);
        strcat(translated_sentence, translated_word);
        strcat(translated_sentence, " ");
        word = strtok(NULL, " ");
    }

    // Add the null terminator to the end of the translated sentence
    translated_sentence[len] = '\0';

    // Return the translated sentence
    return translated_sentence;
}

// Main function
int main() {
    // Get the English sentence from the user
    char sentence[100];
    printf("Enter an English sentence: ");
    gets(sentence);

    // Translate the sentence to Alien
    char *translated_sentence = translate_sentence(sentence);

    // Print the translated sentence
    printf("Alien translation: %s\n", translated_sentence);

    // Free the memory allocated for the translated sentence
    free(translated_sentence);

    return 0;
}