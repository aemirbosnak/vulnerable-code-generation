//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;
}

// Function to remove the first node from the list
struct Node* removeFirst(struct Node** head_ref) {
    struct Node* node = *head_ref;
    if (node == NULL) {
        return NULL;
    }
    *head_ref = node->next;
    if (*head_ref == NULL) {
        free(node);
    }
    return node;
}

// Function to remove the last node from the list
struct Node* removeLast(struct Node** head_ref) {
    struct Node* node = *head_ref;
    if (node == NULL) {
        return NULL;
    }
    struct Node* current = node;
    while (current->prev != NULL) {
        current = current->prev;
    }
    current->next = NULL;
    *head_ref = current->prev;
    free(current);
    return node;
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

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove some nodes
    removeFirst(&head);
    removeLast(&head);

    // Traverse the list
    traverse(head);

    return 0;
}