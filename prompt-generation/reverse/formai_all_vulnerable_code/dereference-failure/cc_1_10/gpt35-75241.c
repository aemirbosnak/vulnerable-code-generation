//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

char* normalize_word(char* word);
int word_index(char* word, char* words[], int count);

int main(int argc, char* argv[]) {
    FILE* file;
    char* words[MAX_WORDS] = { 0 };
    int freq[MAX_WORDS] = { 0 };
    char current_word[MAX_WORD_LENGTH];

    if(argc < 2) {
        printf("Usage: %s <filename>", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    int count = 0;

    while(fscanf(file, "%s", current_word) != EOF) {
        char* normalized_word = normalize_word(current_word);
        if(normalized_word == NULL) {
            continue;
        }

        int index = word_index(normalized_word, words, count);
        if(index == -1) {
            // A new word
            words[count] = malloc(sizeof(char) * strlen(normalized_word));
            strcpy(words[count], normalized_word);
            freq[count] = 1;
            ++count;
        } else {
            // An old word
            ++freq[index];
        }
    }

    fclose(file);

    // Print results
    printf("Word Frequency Count:\n");
    for(int i = 0; i < count; ++i) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    // Clean up
    for(int i = 0; i < count; ++i) {
        free(words[i]);
    }

    return 0;
}

// Helper function to 'normalize' a word: remove punctuation and make lowercase
char* normalize_word(char* word) {
    int len = strlen(word);
    char* processed_word = malloc(sizeof(char) * MAX_WORD_LENGTH);

    int j = 0;
    for(int i = 0; i < len; ++i) {
        if(ispunct(word[i])) {
            continue;
        }
        processed_word[j++] = tolower(word[i]);
    }
    processed_word[j] = '\0';

    if(strlen(processed_word) == 0) {
        free(processed_word);
        return NULL;
    }

    return processed_word;
}

// Returns the index of the word in the 'words' array, or -1 if it isn't there
int word_index(char* word, char* words[], int count) {
    for(int i = 0; i < count; ++i) {
        if(strcmp(word, words[i]) == 0) {
            return i;
        }
    }
    return -1;
}