//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a list
struct Node* insertNode(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to delete a node from a list
struct Node* deleteNode(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        return current;
    }

    return NULL;
}

// Function to find a node in a list
struct Node* findNode(struct Node* head, int value) {
    struct Node* current = head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    return current;
}

// Example usage:
int main() {
    struct Node* head = NULL;

    // Insert some nodes
    head = insertNode(&head, 1);
    head = insertNode(&head, 2);
    head = insertNode(&head, 3);

    // Delete a node
    head = deleteNode(&head, 2);

    // Find a node
    struct Node* node = findNode(head, 3);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}