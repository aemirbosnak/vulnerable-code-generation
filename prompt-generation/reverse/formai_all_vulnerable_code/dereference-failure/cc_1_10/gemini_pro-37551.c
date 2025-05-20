//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style:
// - Use all caps for variables and constants
// - Use Hungarian notation for variable names
// - Indent with 8 spaces
// - Use braces for all blocks, even single-line blocks
// - Use semicolons at the end of every statement

#define MAX_WORD_LENGTH 256

typedef struct {
    char *word;
    int length;
} WORD;

typedef struct {
    WORD *words;
    int num_words;
} DICTIONARY;

// Create a new dictionary
DICTIONARY *dict_new() {
    DICTIONARY *dict = malloc(sizeof(DICTIONARY));
    if (dict == NULL) {
        return NULL;
    }
    dict->words = NULL;
    dict->num_words = 0;
    return dict;
}

// Free a dictionary
void dict_free(DICTIONARY *dict) {
    if (dict == NULL) {
        return;
    }
    for (int i = 0; i < dict->num_words; i++) {
        free(dict->words[i].word);
    }
    free(dict->words);
    free(dict);
}

// Load a dictionary from a file
int dict_load(DICTIONARY *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    // Read the dictionary into a buffer
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, file) != NULL) {
        // Remove the newline character from the end of the word
        buffer[strlen(buffer) - 1] = '\0';

        // Add the word to the dictionary
        WORD word;
        word.word = strdup(buffer);
        if (word.word == NULL) {
            fclose(file);
            return -1;
        }
        word.length = strlen(word.word);
        dict->words = realloc(dict->words, (dict->num_words + 1) * sizeof(WORD));
        if (dict->words == NULL) {
            free(word.word);
            fclose(file);
            return -1;
        }
        dict->words[dict->num_words] = word;
        dict->num_words++;
    }

    fclose(file);
    return 0;
}

// Check if a word is in the dictionary
int dict_contains(DICTIONARY *dict, const char *word) {
    for (int i = 0; i < dict->num_words; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Spell check a word
int spell_check(DICTIONARY *dict, const char *word) {
    if (dict_contains(dict, word)) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new dictionary
    DICTIONARY *dict = dict_new();
    if (dict == NULL) {
        return -1;
    }

    // Load the dictionary from a file
    if (dict_load(dict, "words.txt") != 0) {
        dict_free(dict);
        return -1;
    }

    // Spell check a word
    if (spell_check(dict, "hello")) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    // Free the dictionary
    dict_free(dict);

    return 0;
}