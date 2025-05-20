//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 10000

// Create a node for the dictionary
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct node *next;
} node;

// Create a linked list for the dictionary
typedef struct linked_list {
    node *head;
    node *tail;
    int size;
} linked_list;

// Create a new node for the dictionary
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a word into the dictionary
void insert_word(linked_list *dictionary, char *word) {
    // Check if the word is already in the dictionary
    node *current_node = dictionary->head;
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            current_node->frequency++;
            return;
        }
        current_node = current_node->next;
    }

    // If the word is not in the dictionary, create a new node and insert it
    node *new_node = create_node(word);
    if (dictionary->head == NULL) {
        dictionary->head = new_node;
        dictionary->tail = new_node;
    } else {
        dictionary->tail->next = new_node;
        dictionary->tail = new_node;
    }
    dictionary->size++;
}

// Print the dictionary
void print_dictionary(linked_list *dictionary) {
    node *current_node = dictionary->head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->frequency);
        current_node = current_node->next;
    }
}

// Free the dictionary
void free_dictionary(linked_list *dictionary) {
    node *current_node = dictionary->head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(dictionary);
}

int main() {
    // Create a new dictionary
    linked_list *dictionary = malloc(sizeof(linked_list));
    dictionary->head = NULL;
    dictionary->tail = NULL;
    dictionary->size = 0;

    // Open the file
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Read the file line by line
    char line[1000];
    while (fgets(line, 1000, file)) {
        // Tokenize the line
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Insert the word into the dictionary
            insert_word(dictionary, token);

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Print the dictionary
    print_dictionary(dictionary);

    // Free the dictionary
    free_dictionary(dictionary);

    return 0;
}