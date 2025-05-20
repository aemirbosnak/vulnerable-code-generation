//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
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

// Function to remove the node at the beginning of the list
struct Node* removeFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* current = *head_ref;
    *head_ref = current->next;
    free(current);
    return current;
}

// Function to get the middle node of the list
struct Node* getMiddleNode(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    return previous;
}

// Function to rotate the list by one position
void rotateList(struct Node** head_ref, int number_of_positions) {
    if (number_of_positions == 0) {
        return;
    }

    struct Node* head = *head_ref;
    struct Node* previous = NULL;
    struct Node* current = head;

    for (int i = 0; i < number_of_positions; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = head;
    head->next = NULL;
}

int main() {
    struct Node* head = NULL;

    // Example usage of the functions
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Rotate the list by 2 positions
    rotateList(&head, 2);

    // Get the middle node of the list
    struct Node* middle = getMiddleNode(head);
    printf("Middle node: %d\n", middle->data);

    // Remove the node at the beginning of the list
    struct Node* removed = removeFromBeginning(&head);
    printf("Removed node: %d\n", removed->data);

    return 0;
}