//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a dynamic array to store the words
char **words;
int num_words = 0;

// Allocate memory for a new word
char *new_word(int len) {
    char *word = malloc(len + 1);
    if (word == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for word\n");
        exit(EXIT_FAILURE);
    }
    return word;
}

// Add a new word to the array
void add_word(char *word) {
    words = realloc(words, (num_words + 1) * sizeof(char *));
    if (words == NULL) {
        fprintf(stderr, "Error: Could not reallocate memory for words\n");
        exit(EXIT_FAILURE);
    }
    words[num_words++] = word;
}

// Free the memory allocated for the words
void free_words() {
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
}

// Get the next word from the input
char *get_word(FILE *fp) {
    char c;
    int len = 0;
    char *word = NULL;

    // Skip any whitespace
    while ((c = fgetc(fp)) != EOF && isspace(c))
        ;

    // Check if we reached the end of the file
    if (c == EOF) {
        return NULL;
    }

    // Allocate memory for the word
    word = new_word(1);

    // Read the word character by character
    while ((c = fgetc(fp)) != EOF && !isspace(c)) {
        word[len++] = c;
        word = realloc(word, len + 1);
        if (word == NULL) {
            fprintf(stderr, "Error: Could not reallocate memory for word\n");
            exit(EXIT_FAILURE);
        }
    }

    // Add a null terminator to the word
    word[len] = '\0';

    return word;
}

// Count the number of occurrences of a word in the array
int count_occurrences(char *word) {
    int count = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            count++;
        }
    }
    return count;
}

// Print the words and their occurrences
void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], count_occurrences(words[i]));
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a filename
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the words from the file
    char *word;
    while ((word = get_word(fp)) != NULL) {
        add_word(word);
    }

    // Close the file
    fclose(fp);

    // Print the words and their occurrences
    print_words();

    // Free the memory allocated for the words
    free_words();

    return EXIT_SUCCESS;
}