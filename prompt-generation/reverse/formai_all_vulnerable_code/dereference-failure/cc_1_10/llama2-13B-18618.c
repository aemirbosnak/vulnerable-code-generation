//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void insertAtStart(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first occurrence of a node from a linked list
struct Node* removeFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
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

// Function to remove the last occurrence of a node from a linked list
struct Node* removeLastOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        previous->next = current->next;
        free(current);
        return current;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove the first occurrence of 3 from the list
    removeFirstOccurrence(&head, 3);

    // Remove the last occurrence of 5 from the list
    removeLastOccurrence(&head, 5);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}