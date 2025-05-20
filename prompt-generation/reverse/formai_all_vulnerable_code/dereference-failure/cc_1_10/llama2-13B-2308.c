//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Define a function to insert a node at the beginning of the list
struct Node* insertNode(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Define a function to insert a node at the end of the list
struct Node* insertNodeAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(value);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return new_node;
}

// Define a function to delete the first node of the list
struct Node* deleteFirst(struct Node** head_ref) {
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
    return *head_ref;
}

// Define a function to delete the last node of the list
struct Node* deleteLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous != NULL) {
        previous->next = NULL;
    }
    free(current);
    return previous;
}

// Define a function to find the first node with a given value
struct Node* find(struct Node* head, int value) {
    while (head != NULL && head->data != value) {
        head = head->next;
    }
    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the list
    head = insertNodeAtEnd(&head, 1);
    head = insertNodeAtEnd(&head, 2);
    head = insertNodeAtEnd(&head, 3);

    // Delete nodes from the list
    head = deleteLast(&head);
    head = deleteFirst(&head);

    // Find nodes in the list
    struct Node* node = find(head, 2);
    printf("%d\n", node->data);

    return 0;
}