//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to hold the word count detail
typedef struct WordCount {
    char *word;
    int count;
} WordCount;

// Function prototypes
int is_word_char(char c);
int add_word(WordCount **words, int *size, const char *word);
void free_word_counts(WordCount *words, int size);
void print_word_counts(WordCount *words, int size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount *words = malloc(100 * sizeof(WordCount));
    if (!words) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    int word_count_size = 0;
    char buffer[256];

    while (fscanf(file, "%255s", buffer) != EOF) {
        // Clean up any punctuation attached to the word
        char clean_word[256] = {0};
        int index = 0;

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (is_word_char(buffer[i])) {
                clean_word[index++] = tolower(buffer[i]);
            }
        }
        
        clean_word[index] = '\0';
        
        // Ignore empty results after cleaning
        if (strlen(clean_word) > 0) {
            add_word(&words, &word_count_size, clean_word);
        }
    }
    
    fclose(file);
    print_word_counts(words, word_count_size);
    free_word_counts(words, word_count_size);
    
    return EXIT_SUCCESS;
}

// Determine if the character is part of a word (letter or number)
int is_word_char(char c) {
    return isalnum(c) || c == '\'';
}

// Add a word count to the list or increment the count if it exists
int add_word(WordCount **words, int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp((*words)[i].word, word) == 0) {
            (*words)[i].count++;
            return 0; // Successfully incremented
        }
    }

    // If we did not modify an existing word, create a new one
    if (*size % 100 == 0) { // Expand the array in blocks of 100
        *words = realloc(*words, (*size + 100) * sizeof(WordCount));
        if (!*words) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    (*words)[*size].word = strdup(word);
    (*words)[*size].count = 1;
    (*size)++;

    return 0; // Successfully added new word
}

// Free the allocated memory for word counts
void free_word_counts(WordCount *words, int size) {
    for (int i = 0; i < size; i++) {
        free(words[i].word);
    }
    free(words);
}

// Print the word counts in a readable format
void print_word_counts(WordCount *words, int size) {
    printf("Word Count:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}