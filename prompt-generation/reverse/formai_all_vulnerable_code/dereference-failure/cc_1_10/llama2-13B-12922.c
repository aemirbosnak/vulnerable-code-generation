//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a word
typedef struct {
    char *word;
    int frequency;
} Word;

// Define a list to store words
typedef struct {
    Word *words;
    int size;
    int capacity;
} WordList;

// Function to add a word to the list
void add_word(WordList *list, char *word) {
    // Check if the word is already in the list
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].frequency++;
            return;
        }
    }

    // If the word is not in the list, add it
    Word new_word;
    new_word.word = word;
    new_word.frequency = 1;
    if (list->size == list->capacity) {
        // Increase the capacity of the list
        list->capacity *= 2;
        Word *new_words = realloc(list->words, list->capacity * sizeof(Word));
        if (new_words == NULL) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        list->words = new_words;
    }
    list->words[list->size++] = new_word;
}

// Function to check if a word is in the list
int contains_word(WordList *list, char *word) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print the list of words
void print_list(WordList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s (%d)\n", list->words[i].word, list->words[i].frequency);
    }
}

int main() {
    // Create a list of words
    WordList *list = calloc(1, sizeof(WordList));
    add_word(list, "the");
    add_word(list, "quick");
    add_word(list, "brown");
    add_word(list, "fox");
    add_word(list, "jumps");
    add_word(list, "over");
    add_word(list, "the");
    add_word(list, "lazy");
    add_word(list, "dog");

    // Check if the word "the" is in the list
    if (contains_word(list, "the")) {
        printf("The word 'the' is in the list.\n");
    } else {
        printf("The word 'the' is not in the list.\n");
    }

    // Print the list of words
    print_list(list);

    return 0;
}