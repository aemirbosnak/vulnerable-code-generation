//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to delete the first occurrence of a given data element
void deleteFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current != NULL) {
        current->next = current->next->next;
    }
}

// Function to delete all occurrences of a given data element
void deleteAllOccurrences(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            current->next = current->next->next;
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Delete the first occurrence of 2
    deleteFirstOccurrence(&head, 2);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Delete all occurrences of 2
    deleteAllOccurrences(&head, 2);

    // Print the list again
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}