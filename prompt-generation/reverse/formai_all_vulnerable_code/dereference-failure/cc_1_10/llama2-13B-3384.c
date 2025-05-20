//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
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

// Function to remove the first node from the list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* node = *head_ref;
    *head_ref = node->next;
    free(node);
    return node;
}

// Function to remove the last node from the list
struct Node* removeLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head_ref = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
    return previous;
}

// Function to check if the list is empty
int isEmpty(struct Node** head_ref) {
    return *head_ref == NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove nodes from the list
    removeFirst(&head);
    removeLast(&head);

    // Check if the list is empty
    if (isEmpty(&head)) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }

    return 0;
}