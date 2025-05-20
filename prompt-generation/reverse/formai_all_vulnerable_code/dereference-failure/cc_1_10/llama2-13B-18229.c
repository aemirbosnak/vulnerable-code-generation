//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Brave-style linked list operations

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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

// Function to delete the first occurrence of a given data in the list
struct Node* deleteFirst(struct Node** head_ref, int data) {
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
        return previous;
    }
    return NULL;
}

// Function to delete all occurrences of a given data in the list
struct Node* deleteAll(struct Node** head_ref, int data) {
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
            return previous;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Test cases
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);

    // Delete all occurrences of 3
    head = deleteAll(&head, 3);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}