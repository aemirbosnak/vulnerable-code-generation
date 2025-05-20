//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node structure
typedef struct Node {
    char *name;
    bool state;
    struct Node *next;
} Node;

// Create a new node
Node *create_node(char *name, bool state) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->name = strdup(name);
    new_node->state = state;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list
Node *insert_node(Node *head, char *name, bool state) {
    Node *new_node = create_node(name, state);
    new_node->next = head;
    return new_node;
}

// Delete a node from the list
Node *delete_node(Node *head, char *name) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        Node *next_node = head->next;
        free(head->name);
        free(head);
        return next_node;
    }

    head->next = delete_node(head->next, name);
    return head;
}

// Print the list of nodes
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->state ? "ON" : "OFF");
        current = current->next;
    }
}

// Main function
int main() {
    // Create a linked list of nodes
    Node *head = NULL;
    head = insert_node(head, "Light 1", false);
    head = insert_node(head, "Light 2", true);
    head = insert_node(head, "Light 3", false);

    // Print the list of nodes
    printf("Initial state:\n");
    print_list(head);

    // Turn on Light 1
    head = delete_node(head, "Light 1");
    head = insert_node(head, "Light 1", true);

    // Turn off Light 3
    head = delete_node(head, "Light 3");
    head = insert_node(head, "Light 3", false);

    // Print the updated list of nodes
    printf("\nUpdated state:\n");
    print_list(head);

    // Free the list of nodes
    while (head != NULL) {
        Node *next_node = head->next;
        free(head->name);
        free(head);
        head = next_node;
    }

    return 0;
}