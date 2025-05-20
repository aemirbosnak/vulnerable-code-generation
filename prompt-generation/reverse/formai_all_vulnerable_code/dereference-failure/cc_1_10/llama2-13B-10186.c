//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first occurrence of a given value in the list
void deleteNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to find the first occurrence of a given value in the list
struct Node* findNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    // Delete all occurrences of 2
    deleteNode(&head, 2);

    // Find the first occurrence of 3
    struct Node* three = findNode(head, 3);
    if (three != NULL) {
        printf("Found 3 at position %d\n", three->next == NULL ? 0 : 1);
    } else {
        printf("Not found\n");
    }

    return 0;
}