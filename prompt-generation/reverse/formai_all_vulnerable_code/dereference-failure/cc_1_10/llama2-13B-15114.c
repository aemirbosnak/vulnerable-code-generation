//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
}

// Function to remove the first occurrence of a given value in the list
void removeFirstOccurrence(struct Node** head_ref, int data) {
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
    }
}

// Function to find the first node with a given value in the list
struct Node* findFirst(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove the first occurrence of 3 in the list
    removeFirstOccurrence(&head, 3);

    // Find the first node with value 5 in the list
    struct Node* five = findFirst(&head, 5);
    printf("First node with value 5: %d\n", five->data);

    return 0;
}