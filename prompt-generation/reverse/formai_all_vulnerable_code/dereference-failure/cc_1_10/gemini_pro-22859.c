//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the word list.
#define MAX_WORDS 1000

// Define the maximum length of a word.
#define MAX_WORD_LENGTH 100

// Define the structure of a word.
typedef struct {
    char *word;
    int count;
} word_t;

// Define the structure of the word list.
typedef struct {
    word_t *words;
    int count;
} word_list_t;

// Create a new word list.
word_list_t *new_word_list() {
    word_list_t *word_list = malloc(sizeof(word_list_t));
    word_list->words = malloc(sizeof(word_t) * MAX_WORDS);
    word_list->count = 0;
    return word_list;
}

// Free a word list.
void free_word_list(word_list_t *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        free(word_list->words[i].word);
    }
    free(word_list->words);
    free(word_list);
}

// Add a word to the word list.
void add_word_to_list(word_list_t *word_list, char *word) {
    // Check if the word is already in the list.
    for (int i = 0; i < word_list->count; i++) {
        if (strcmp(word_list->words[i].word, word) == 0) {
            word_list->words[i].count++;
            return;
        }
    }

    // If the word is not in the list, add it.
    if (word_list->count >= MAX_WORDS) {
        fprintf(stderr, "Error: word list is full.\n");
        exit(1);
    }

    // Allocate memory for the word.
    word_list->words[word_list->count].word = malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(word_list->words[word_list->count].word, word);

    // Initialize the word's count to 1.
    word_list->words[word_list->count].count = 1;

    // Increment the count of words in the list.
    word_list->count++;
}

// Sort the word list by word count.
void sort_word_list(word_list_t *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        for (int j = i + 1; j < word_list->count; j++) {
            if (word_list->words[i].count < word_list->words[j].count) {
                word_t temp = word_list->words[i];
                word_list->words[i] = word_list->words[j];
                word_list->words[j] = temp;
            }
        }
    }
}

// Print the word list.
void print_word_list(word_list_t *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        printf("%s: %d\n", word_list->words[i].word, word_list->words[i].count);
    }
}

// Get the next word from the input stream.
char *get_next_word(FILE *input) {
    char *word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int c;

    // Skip whitespace.
    while ((c = fgetc(input)) != EOF && isspace(c)) {
        ;
    }

    // Check if we reached the end of the file.
    if (c == EOF) {
        return NULL;
    }

    // Read the word.
    int i = 0;
    while ((c = fgetc(input)) != EOF && !isspace(c)) {
        word[i++] = c;
    }

    // Null-terminate the word.
    word[i] = '\0';

    // Return the word.
    return word;
}

// Main function.
int main(int argc, char **argv) {
    // Check if a filename was provided.
    if (argc != 2) {
        fprintf(stderr, "Error: no filename provided.\n");
        exit(1);
    }

    // Open the file.
    FILE *input = fopen(argv[1], "r");

    // Check if the file was opened successfully.
    if (input == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        exit(1);
    }

    // Create a new word list.
    word_list_t *word_list = new_word_list();

    // Read the file and add the words to the word list.
    char *word;
    while ((word = get_next_word(input)) != NULL) {
        add_word_to_list(word_list, word);
        free(word);
    }

    // Close the file.
    fclose(input);

    // Sort the word list.
    sort_word_list(word_list);

    // Print the word list.
    print_word_list(word_list);

    // Free the word list.
    free_word_list(word_list);

    return 0;
}