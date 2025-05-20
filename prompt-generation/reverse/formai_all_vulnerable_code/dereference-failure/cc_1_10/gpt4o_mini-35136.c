//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 10000
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024

char *dictionary[DICTIONARY_SIZE];
int wordCount = 0;

// Function to load the dictionary from a file
void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(dictionary[wordCount], MAX_WORD_LENGTH, file) && wordCount < DICTIONARY_SIZE) {
        dictionary[wordCount][strcspn(dictionary[wordCount], "\n")] = '\0'; // Remove newline
        wordCount++;
    }
    fclose(file);
}

// Function to check if a word is in the dictionary
int checkWord(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcasecmp(dictionary[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to clean a word from punctuation and convert it to lowercase
void cleanWord(char *word, char *cleaned) {
    int j = 0;
    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) {
            cleaned[j++] = tolower(word[i]);
        }
    }
    cleaned[j] = '\0'; // Null-terminate the cleaned string
}

// Function to spell check the text file
void spellCheckFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char cleaned[MAX_WORD_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            cleanWord(token, cleaned);
            if (strlen(cleaned) > 0 && !checkWord(cleaned)) {
                printf("Misspelled word: %s\n", cleaned);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dictionaryFile = argv[1];
    const char *textFile = argv[2];

    loadDictionary(dictionaryFile);
    spellCheckFile(textFile);

    return EXIT_SUCCESS;
}