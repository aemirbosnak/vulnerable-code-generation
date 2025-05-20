//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a happy little word node
typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node;

// Create a happy little word list
typedef struct word_list {
    word_node *head;
    int size;
} word_list;

// Create a new happy little word node
word_node *new_word_node(char *word) {
    word_node *new_node = malloc(sizeof(word_node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Create a new happy little word list
word_list *new_word_list() {
    word_list *new_list = malloc(sizeof(word_list));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Add a happy little word to the list
void add_word(word_list *list, char *word) {
    word_node *new_node = new_word_node(word);
    if (!list->head) {
        list->head = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

// Count the happy little words in a string
void count_words(word_list *list, char *str) {
    char *word = strtok(str, " ");
    while (word) {
        add_word(list, word);
        word = strtok(NULL, " ");
    }
}

// Print the happy little word list
void print_word_list(word_list *list) {
    word_node *current = list->head;
    while (current) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the happy little word list
void free_word_list(word_list *list) {
    word_node *current = list->head;
    while (current) {
        word_node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // Create a happy little word list
    word_list *list = new_word_list();

    // Count the happy little words in a string
    count_words(list, "Hello, world! This is a test string.");

    // Print the happy little word list
    print_word_list(list);

    // Free the happy little word list
    free_word_list(list);

    return 0;
}