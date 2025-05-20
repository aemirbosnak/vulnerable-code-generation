//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list
struct node {
    char *value;
    struct node *next;
};

// Create a new node with the given value
struct node *create_node(char *value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = strdup(value);
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the end of the linked list
void insert_node(struct node **head, char *value) {
    struct node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Print the linked list
void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->value);
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main() {
    // Create a linked list of words
    struct node *head = NULL;
    insert_node(&head, "Hello");
    insert_node(&head, "world");
    insert_node(&head, "!");

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}