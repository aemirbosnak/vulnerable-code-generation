//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first occurrence of a given value in the list
void removeFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    if (current == NULL || current->data != data) {
        return; // not found
    }
    current->next = current->next->next;
    free(current);
}

// Function to remove the last occurrence of a given value in the list
void removeLastOccurrence(struct Node** head_ref, int data) {
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

// Function to search for a given value in the list
int search(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // found
        }
        current = current->next;
    }
    return 0; // not found
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove some nodes
    removeFirstOccurrence(&head, 2);
    removeLastOccurrence(&head, 5);

    // Search for some nodes
    printf("Node 1: %d\n", search(&head, 1));
    printf("Node 2: %d\n", search(&head, 2));
    printf("Node 3: %d\n", search(&head, 3));
    printf("Node 4: %d\n", search(&head, 4));

    return 0;
}