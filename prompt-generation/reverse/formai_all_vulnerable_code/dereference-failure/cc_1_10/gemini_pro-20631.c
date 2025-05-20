//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to store a linked list of integers
typedef struct node {
    int data;
    struct node *next;
} node;

// Allocate memory for a new node and initialize its data field
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(node **head, int data) {
    if (*head == NULL) {
        *head = create_node(data);
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(data);
}

// Insert a new node after a specific node in the linked list
void insert_after_node(node *prev_node, int data) {
    if (prev_node == NULL) {
        fprintf(stderr, "Error: Previous node cannot be NULL\n");
        exit(1);
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the linked list
void delete_node(node **head, node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        node *current = *head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
    }
    free(node_to_delete);
}

// Print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the entire linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create an empty linked list
    node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after_node(head, 15);

    // Print the linked list
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next);

    // Print the linked list again
    print_list(head);

    // Free the entire linked list
    free_list(head);

    return 0;
}