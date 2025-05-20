//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256
#define DICTIONARY_FILE "dictionaries/words.dat"

// Structure to store word information
typedef struct {
    char *word;
    size_t length;
} word_t;

// Function to check if a word is a typo
int is_typo(char *word) {
    size_t i;
    for (i = 0; i < strlen(word); i++) {
        if (isupper(word[i]) && word[i] != word[i + 1]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is in the dictionary
int is_word_in_dict(char *word) {
    size_t index = 0;
    char *ptr = NULL;
    FILE *dict_file = fopen(DICTIONARY_FILE, "r");

    // Check if the dictionary file exists
    if (!dict_file) {
        printf("Error: Dictionary file not found\n");
        return 0;
    }

    // Read the dictionary file line by line
    while ((ptr = fgets(word, MAX_WORD_LENGTH, dict_file)) != NULL) {
        // Check if the current word is the one we're looking for
        if (strcmp(word, word) == 0) {
            // Found the word in the dictionary, return 1
            return 1;
        }

        // Check if the current word is a typo
        if (is_typo(word)) {
            // Typo found, return 0
            return 0;
        }

        // Increment the index for the next word
        index++;
    }

    // If we reached the end of the file without finding the word, return 0
    return 0;
}

// Function to perform spell checking
int spell_check(char *text) {
    size_t i;
    word_t words[10];
    int words_found = 0;

    // Split the text into individual words
    char *word = strtok(text, " ");

    // Loop through each word
    for (i = 0; word != NULL; i++) {
        // Check if the word is in the dictionary
        if (is_word_in_dict(word)) {
            // Word found in the dictionary, increment the words found count
            words_found++;

            // Store the word in the words array
            words[i].word = word;
            words[i].length = strlen(word);
        } else {
            // Word not found in the dictionary, mark it as a typo
            words[i].word = word;
            words[i].length = strlen(word);
            words[i].word[0] = '*';
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Print the words found in the dictionary
    for (i = 0; i < words_found; i++) {
        printf("%d) %s (%d letters)\n", i + 1, words[i].word, words[i].length);
    }

    // Print the typos found
    for (i = 0; i < words_found; i++) {
        if (words[i].word[0] == '*') {
            printf("%d) %s (%d letters) - Typo\n", i + 1, words[i].word, words[i].length);
        }
    }

    return words_found;
}

int main() {
    char text[100];
    printf("Enter a sentence or phrase to check the spelling: ");
    fgets(text, 100, stdin);

    // Perform spell checking
    int words_found = spell_check(text);

    // Print the result
    if (words_found > 0) {
        printf("The following words were found in the dictionary:\n");
    } else {
        printf("No words were found in the dictionary.\n");
    }

    return 0;
}