//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for a linked list of words
typedef struct node {
    char *word;
    struct node *next;
} node_t;

// Create a new node with the given word
node_t *new_node(char *word) {
    node_t *node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->next = NULL;
    return node;
}

// Insert a new node into the linked list in alphabetical order
void insert_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else if (strcmp(new_node->word, (*head)->word) < 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL && strcmp(new_node->word, current->next->word) > 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Print the linked list of words
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

// Free the linked list of words
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a linked list of words
    node_t *head = NULL;
    insert_node(&head, new_node("apple"));
    insert_node(&head, new_node("banana"));
    insert_node(&head, new_node("cherry"));
    insert_node(&head, new_node("dog"));
    insert_node(&head, new_node("elephant"));

    // Print the linked list of words
    print_list(head);

    // Free the linked list of words
    free_list(head);

    return 0;
}