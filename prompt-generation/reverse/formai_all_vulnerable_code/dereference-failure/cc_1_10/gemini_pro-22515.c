//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
} node_t;

// Create a new node with the given word
node_t *create_node(char *word) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list, in alphabetical order
void insert_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current_node = *head;
    node_t *previous_node = NULL;

    while (current_node != NULL && strcmp(current_node->word, new_node->word) < 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        previous_node->next = new_node;
        new_node->next = current_node;
    }
}

// Print the linked list of words
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%s\n", head->word);
        head = head->next;
    }
}

// Free the linked list of words
void free_list(node_t *head) {
    while (head != NULL) {
        node_t *next_node = head->next;
        free(head->word);
        free(head);
        head = next_node;
    }
}

int main() {
    // Create a linked list of words
    node_t *head = NULL;

    // Insert some words into the linked list
    insert_node(&head, create_node("apple"));
    insert_node(&head, create_node("banana"));
    insert_node(&head, create_node("cherry"));
    insert_node(&head, create_node("dog"));
    insert_node(&head, create_node("elephant"));

    // Print the linked list of words
    print_list(head);

    // Free the linked list of words
    free_list(head);

    return 0;
}