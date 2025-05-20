//FormAI DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
// This program demonstrates a dynamic memory management technique in C,
// inspired by the analytical engine designed by Ada Lovelace.

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} node;

node* add_node(node* head, int value) {
    // Dynamically allocate memory for new node
    node* new_node = (node*)malloc(sizeof(node));

    // Set value and point new node to previous head
    new_node->value = value;
    new_node->next = head;

    // Return new head of the linked list
    return new_node;
}

node* delete_node(node* head, int value) {
    // Keep track of previous node
    node* prev = NULL;

    // Traverse the linked list
    node* curr = head;
    while (curr != NULL) {
        // Check if value matches
        if (curr->value == value) {
            // Update links to remove node from list
            if (prev == NULL) {
                // First node is being removed
                head = curr->next;
            } else {
                // Middle or last node is being removed
                prev->next = curr->next;
            }

            // Free memory for the removed node
            free(curr);

            // Return new head of the linked list
            return head;
        }

        // Move on to next node
        prev = curr;
        curr = curr->next;
    }

    // Return the original head if no node was removed
    return head;
}

int main() {
    // Initialize head of linked list to NULL
    node* head = NULL;

    // Add five nodes to the linked list
    head = add_node(head, 5);
    head = add_node(head, 4);
    head = add_node(head, 3);
    head = add_node(head, 2);
    head = add_node(head, 1);

    // Remove the third node from the linked list
    head = delete_node(head, 3);

    // Print the values in the linked list
    node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }

    return 0;
}