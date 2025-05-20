//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Struct for a node in the linked list
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

// Function to remove the node at the beginning of the list
struct Node* removeAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);

    return previous;
}

// Function to reverse the linked list
struct Node* reverseList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head_ref = previous;
    return previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the node at the beginning of the list
    struct Node* removed = removeAtBeginning(&head);
    printf("Removed node: %d\n", removed->data);

    // Reverse the linked list
    struct Node* reversed_head = reverseList(&head);
    printf("Reversed list: ");
    while (reversed_head != NULL) {
        printf("%d ", reversed_head->data);
        reversed_head = reversed_head->next;
    }
    printf("\n");

    return 0;
}