//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Function to read the dictionary into an array of strings
int read_dictionary(char *dictionary_file, char *words[MAX_WORDS]) {
    FILE *fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        return -1;
    }

    int num_words = 0;
    while (fgets(words[num_words], MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the word
        words[num_words][strlen(words[num_words]) - 1] = '\0';
        num_words++;
    }

    fclose(fp);
    return num_words;
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word, char *words[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check the spelling of a word
int check_spelling(char *word, char *words[MAX_WORDS], int num_words) {
    // Check if the word is in the dictionary
    if (is_in_dictionary(word, words, num_words)) {
        return 1;
    }

    // Check for common misspellings
    char *misspellings[] = {"teh", "teh", "teh", "teh", "teh"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, misspellings[i]) == 0) {
            return 1;
        }
    }

    // Check for phonetic misspellings
    char *phonetic_misspellings[] = {"fonetik", "fonetik", "fonetik", "fonetik", "fonetik"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, phonetic_misspellings[i]) == 0) {
            return 1;
        }
    }

    // Check for typographical errors
    char *typographical_errors[] = {"typos", "typos", "typos", "typos", "typos"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, typographical_errors[i]) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary and does not match any common misspellings or typographical errors
    return 0;
}

int main() {
    // Read the dictionary into an array of strings
    char *words[MAX_WORDS];
    int num_words = read_dictionary("dictionary.txt", words);

    // Check the spelling of a word
    char *word = "teh";
    int is_correct = check_spelling(word, words, num_words);

    // Print the result
    if (is_correct) {
        printf("The word \"%s\" is spelled correctly.\n", word);
    } else {
        printf("The word \"%s\" is not spelled correctly.\n", word);
    }

    return 0;
}