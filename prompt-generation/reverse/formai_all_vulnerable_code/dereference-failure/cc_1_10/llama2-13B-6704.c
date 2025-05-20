//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: secure
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
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(value);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
}

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
}

// Function to remove the last node from the list
void removeLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = NULL;
    free(last);
}

// Function to check if the list is empty
int isEmpty(struct Node** head_ref) {
    return *head_ref == NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove the first node from the list
    removeFirst(&head);

    // Remove the last node from the list
    removeLast(&head);

    // Check if the list is empty
    if (isEmpty(&head)) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }

    return 0;
}