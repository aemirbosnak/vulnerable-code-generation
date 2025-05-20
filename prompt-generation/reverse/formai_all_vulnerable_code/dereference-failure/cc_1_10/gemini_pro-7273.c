//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node of the phone book
typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(char *name, char *number) {
    node_t *node = malloc(sizeof(node_t));
    node->name = name;
    node->number = number;
    node->next = NULL;
    return node;
}

// Insert a new node into the phone book
void insert_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Search for a name in the phone book
node_t *search_node(node_t *head, char *name) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Delete a node from the phone book
void delete_node(node_t **head, node_t *node) {
    if (*head == node) {
        *head = node->next;
    } else {
        node_t *current = *head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next;
    }
    free(node);
}

// Print the phone book
void print_phone_book(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

// Free the phone book
void free_phone_book(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->name);
        free(current->number);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create the head of the phone book
    node_t *head = NULL;

    // Insert some names and numbers into the phone book
    insert_node(&head, create_node("John", "555-1212"));
    insert_node(&head, create_node("Mary", "555-1213"));
    insert_node(&head, create_node("Bob", "555-1214"));

    // Print the phone book
    print_phone_book(head);

    // Search for a name in the phone book
    node_t *node = search_node(head, "John");
    if (node != NULL) {
        printf("Found %s: %s\n", node->name, node->number);
    } else {
        printf("Name not found.\n");
    }

    // Delete a node from the phone book
    delete_node(&head, node);

    // Print the phone book
    print_phone_book(head);

    // Free the phone book
    free_phone_book(head);

    return 0;
}