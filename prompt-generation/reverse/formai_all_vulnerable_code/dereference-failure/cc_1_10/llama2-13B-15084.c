//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Definition of Linked List Node
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

// Function to remove the first node of the list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
    return *head_ref;
}

// Function to remove the last node of the list
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

    // Insert some nodes
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);

    // Remove some nodes
    head = removeFirst(&head);
    head = removeLast(&head);

    // Check if the list is empty
    if (isEmpty(&head)) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    return 0;
}