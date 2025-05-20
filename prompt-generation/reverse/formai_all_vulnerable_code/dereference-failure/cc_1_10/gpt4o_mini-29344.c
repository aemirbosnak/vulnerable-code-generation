//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store a word and its length
typedef struct {
    char *word;
    int length;
} DictionaryWord;

// Function declarations
void loadDictionary(DictionaryWord **dict, int *dictSize, const char *filename);
void checkSpelling(const char *text, DictionaryWord *dict, int dictSize);
void toLowerCase(char *str);
int isInDictionary(const char *word, DictionaryWord *dict, int dictSize);

// Main function
int main() {
    // Prepare to be thrilled! We're about to spell-check some text!
    printf("Welcome to the Ultimate Spell Checker! 🎉\n\n");

    DictionaryWord *dictionary = NULL;
    int dictSize = 0;

    // Load the dictionary, please provide a full stop for dramatic effects
    loadDictionary(&dictionary, &dictSize, "dictionary.txt");

    // Let's say we're checking a rather famous phrase
    const char *textToCheck = "Ths is an exampel of a spell cheker working!";

    printf("Checking the text: \"%s\"\n", textToCheck);
    checkSpelling(textToCheck, dictionary, dictSize);

    // Clean up
    for (int i = 0; i < dictSize; i++) {
        free(dictionary[i].word);
    }
    free(dictionary);
    
    printf("\nThank you for using the Ultimate Spell Checker! Goodbye! 👋\n");
    return 0;
}

// Load the dictionary from a file
void loadDictionary(DictionaryWord **dict, int *dictSize, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening dictionary file!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    int capacity = 10;
    *dict = malloc(capacity * sizeof(DictionaryWord));

    while (fgets(buffer, sizeof(buffer), file)) {
        // Removing newline character from string
        buffer[strcspn(buffer, "\n")] = 0;

        if (*dictSize >= capacity) {
            capacity *= 2;
            *dict = realloc(*dict, capacity * sizeof(DictionaryWord));
        }

        (*dict)[*dictSize].length = strlen(buffer);
        (*dict)[*dictSize].word = malloc((*dict)[*dictSize].length + 1);
        strcpy((*dict)[*dictSize].word, buffer);
        (*dictSize)++;
    }

    fclose(file);
    printf("Successfully loaded the dictionary with %d words! 🎊\n", *dictSize);
}

// Check the spelling of the provided text
void checkSpelling(const char *text, DictionaryWord *dict, int dictSize) {
    char *textCopy = malloc(strlen(text) + 1);
    strcpy(textCopy, text);
    char *word = strtok(textCopy, " !?.,;:");
    
    while (word) {
        char lowerWord[100];
        strcpy(lowerWord, word);
        toLowerCase(lowerWord);

        // Check if the word is in the dictionary
        if (!isInDictionary(lowerWord, dict, dictSize)) {
            printf("Misspelled word found: \"%s\" 😱\n", word);
        }

        word = strtok(NULL, " !?.,;:");
    }
    
    free(textCopy);
}

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (char *p = str; *p; p++) {
        *p = tolower(*p);
    }
}

// Determine if a word is in the dictionary
int isInDictionary(const char *word, DictionaryWord *dict, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dict[i].word) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}