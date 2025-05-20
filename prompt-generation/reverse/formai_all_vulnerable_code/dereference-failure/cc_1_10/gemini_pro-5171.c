//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a node for the linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Create a new node
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list
void insert_node(node **head, char *word) {
    node *new_node = create_node(word);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Search for a word in the linked list
node *search_node(node *head, char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Increment the count of a word in the linked list
void increment_count(node *node) {
    node->count++;
}

// Print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Get the next word from the file
char *get_next_word(FILE *file) {
    char *word = malloc(MAX_WORD_LENGTH);
    int c;
    int i = 0;
    while ((c = fgetc(file)) != EOF && !isspace(c)) {
        word[i++] = c;
    }
    word[i] = '\0';
    return word;
}

// Count the words in the file
void count_words(FILE *file) {
    node *head = NULL;
    char *word;
    while ((word = get_next_word(file)) != NULL) {
        node *node = search_node(head, word);
        if (node != NULL) {
            increment_count(node);
        } else {
            insert_node(&head, word);
        }
    }
    print_list(head);
    free_list(head);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }
    count_words(file);
    fclose(file);
    return EXIT_SUCCESS;
}