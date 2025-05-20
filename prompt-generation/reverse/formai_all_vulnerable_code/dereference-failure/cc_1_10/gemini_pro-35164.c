//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language alphabet and its English equivalents
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char english_equivalents[] = "fdghjklqwertypboiu zxcvbnmasdfghjklqwertyuiop0123456789";

// Function to translate a single Alien character to its English equivalent
char translate_character(char alien_char) {
    int index = strchr(alien_alphabet, alien_char) - alien_alphabet;
    return english_equivalents[index];
}

// Function to translate an entire Alien word to English
char *translate_word(char *alien_word) {
    int word_length = strlen(alien_word);
    char *english_word = malloc(word_length + 1);
    for (int i = 0; i < word_length; i++) {
        english_word[i] = translate_character(alien_word[i]);
    }
    english_word[word_length] = '\0';
    return english_word;
}

// Function to translate an entire Alien sentence to English
char *translate_sentence(char *alien_sentence) {
    // Split the sentence into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(alien_sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word and concatenate them into the English sentence
    char *english_sentence = malloc(1000);
    english_sentence[0] = '\0';
    for (int i = 0; i < num_words; i++) {
        char *translated_word = translate_word(words[i]);
        strcat(english_sentence, translated_word);
        free(translated_word);
        if (i < num_words - 1) {
            strcat(english_sentence, " ");
        }
    }

    return english_sentence;
}

int main() {
    // Get the Alien sentence from the user
    char alien_sentence[1000];
    printf("Enter an Alien sentence: ");
    fgets(alien_sentence, 1000, stdin);

    // Translate the sentence to English
    char *english_sentence = translate_sentence(alien_sentence);

    // Print the English translation
    printf("English translation: %s\n", english_sentence);

    // Free the allocated memory
    free(english_sentence);

    return 0;
}