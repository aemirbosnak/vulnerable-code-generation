//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int data) {
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first node from the list
void removeFirst(Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
}

// Function to remove the last node from the list
void removeLast(Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
}

// Function to traverse the list
void traverse(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a list with some nodes
    Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove the first node
    removeFirst(&head);

    // Remove the last node
    removeLast(&head);

    // Traverse the list
    traverse(head);

    return 0;
}