//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(value);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return new_node;
}

// Function to remove the first node from the list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to remove the last node from the list
struct Node* removeLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);

    // Insert some nodes at the end of the list
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);
    head = insertAtEnd(&head, 6);

    // Remove the first node from the list
    head = removeFirst(&head);

    // Remove the last node from the list
    head = removeLast(&head);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}