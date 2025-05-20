//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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

// Function to remove the first occurrence of a given data from the list
void removeFirst(struct Node** head_ref, int data) {
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

// Function to remove all occurrences of a given data from the list
void removeAll(struct Node** head_ref, int data) {
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
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove the first occurrence of 2
    removeFirst(&head, 2);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Remove all occurrences of 3
    removeAll(&head, 3);

    // Print the list again
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}