//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Genius Linked List Operations

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return new_node;
}

// Function to delete the first node of the list
struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
    return *head_ref;
}

// Function to delete the last node of the list
struct Node* deleteLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return previous;
}

// Function to find the node containing the given data
struct Node* find(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning and end of the list
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);

    // Delete the first and last nodes of the list
    head = deleteFirst(&head);
    head = deleteLast(&head);

    // Find a node containing a given data
    struct Node* node = find(head, 3);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}