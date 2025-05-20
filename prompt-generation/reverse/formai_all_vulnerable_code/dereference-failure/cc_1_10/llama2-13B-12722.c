//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_COUNT 100
#define MIN_WORD_LEN 3

// Structure to store word count and list of words
typedef struct {
    int word_count;
    char **word_list;
} word_count_t;

// Function to initialize word count and list of words
void init_word_count(word_count_t *word_count) {
    word_count->word_count = 0;
    word_count->word_list = calloc(MAX_WORD_COUNT, sizeof(char *));
}

// Function to add a word to the list and increment word count
void add_word(word_count_t *word_count, const char *word) {
    // Check if word is not null and has at least MIN_WORD_LEN characters
    if (word != NULL && strlen(word) >= MIN_WORD_LEN) {
        // Check if word is not already in the list
        for (int i = 0; i < word_count->word_count; i++) {
            if (strcmp(word_count->word_list[i], word) == 0) {
                // Word already in list, just increment count
                word_count->word_count++;
                return;
            }
        }
        // Word not in list, add it and increment count
        word_count->word_list[word_count->word_count] = strdup(word);
        word_count->word_count++;
    }
}

// Function to print the word count and list of words
void print_word_count(word_count_t *word_count) {
    printf("Word Count: %d\n", word_count->word_count);
    for (int i = 0; i < word_count->word_count; i++) {
        printf("%d. %s\n", i + 1, word_count->word_list[i]);
    }
}

int main() {
    word_count_t word_count;
    init_word_count(&word_count);

    // Add some words to the list
    add_word(&word_count, "Hello");
    add_word(&word_count, "World");
    add_word(&word_count, "C++");

    // Print the word count and list of words
    print_word_count(&word_count);

    return 0;
}