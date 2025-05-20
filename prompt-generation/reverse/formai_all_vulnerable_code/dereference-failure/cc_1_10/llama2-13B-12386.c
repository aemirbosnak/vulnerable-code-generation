//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave Linked List Structure
typedef struct BraveNode {
    int data;
    struct BraveNode *next;
} BraveNode;

// Brave Linked List Functions

// Function to insert a node at the beginning of the list
BraveNode* insertAtBeginning(BraveNode** head_ref, int data) {
    BraveNode* new_node = (BraveNode*) malloc(sizeof(BraveNode));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert a node at the end of the list
BraveNode* insertAtEnd(BraveNode** head_ref, int data) {
    BraveNode* current = *head_ref;
    BraveNode* new_node = (BraveNode*) malloc(sizeof(BraveNode));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

// Function to delete the first node of the list
BraveNode* deleteFirst(BraveNode** head_ref) {
    BraveNode* current = *head_ref;
    BraveNode* previous = NULL;

    if (*head_ref == NULL) {
        return NULL;
    }

    if (current->next == NULL) {
        *head_ref = NULL;
        free(current);
        return NULL;
    }

    previous = current;
    current = current->next;
    previous->next = current->next;
    current->next = NULL;

    return previous;
}

// Function to delete the last node of the list
BraveNode* deleteLast(BraveNode** head_ref) {
    BraveNode* current = *head_ref;
    BraveNode* next = NULL;

    if (*head_ref == NULL) {
        return NULL;
    }

    while (current->next != NULL) {
        next = current->next;
        current = next;
    }

    current->next = NULL;
    free(next);

    return current;
}

int main() {
    BraveNode* head = NULL;

    // Insert nodes at the beginning of the list
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);

    // Delete the first node of the list
    head = deleteFirst(&head);

    // Delete the last node of the list
    head = deleteLast(&head);

    // Print the list
    BraveNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}