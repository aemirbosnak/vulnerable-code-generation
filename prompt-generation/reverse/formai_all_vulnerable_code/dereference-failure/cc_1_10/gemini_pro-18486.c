//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure for storing a linked list of nodes
typedef struct node {
    int value;
    struct node *next;
} node_t;

// Function to create a new node with the given value
node_t *create_node(int value) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;  // Error handling
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
node_t *insert_at_beginning(node_t *head, int value) {
    node_t *new_node = create_node(value);
    if (new_node == NULL) {
        return NULL;  // Error handling
    }
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of the linked list
node_t *insert_at_end(node_t *head, int value) {
    node_t *new_node = create_node(value);
    if (new_node == NULL) {
        return NULL;  // Error handling
    }
    if (head == NULL) {
        return new_node;
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to delete a node from the linked list by value
node_t *delete_by_value(node_t *head, int value) {
    if (head == NULL) {
        return NULL;  // Error handling
    }
    node_t *current = head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some values into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);

    // Print the linked list
    printf("Original linked list: ");
    print_list(head);

    // Delete a value from the linked list
    head = delete_by_value(head, 2);

    // Print the linked list
    printf("Linked list after deleting 2: ");
    print_list(head);

    return 0;
}