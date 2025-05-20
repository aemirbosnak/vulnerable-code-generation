//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
    return current->next;
}

// Function to delete a node from the list
struct Node* deleteNode(struct Node** head_ref, int data) {
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

// Function to traverse the list
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    // Delete nodes from the list
    deleteNode(&head, 3);
    deleteNode(&head, 5);

    // Traverse the list
    traverse(head);

    return 0;
}