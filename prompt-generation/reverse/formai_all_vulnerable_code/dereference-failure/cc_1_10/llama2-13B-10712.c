//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first occurrence of a given value in the linked list
void removeFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    if (current == NULL) {
        return;
    }
    if (current->data == data) {
        *head_ref = current->next;
        free(current);
    } else {
        removeFirstOccurrence(current->next, data);
    }
}

// Function to remove all occurrences of a given value in the linked list
void removeAllOccurrences(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            removeFirstOccurrence(current->next, data);
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove all occurrences of 3 from the linked list
    removeAllOccurrences(&head, 3);

    // Print the remaining nodes in the linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}