//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
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
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
}

// Function to remove the first occurrence of a given value from the list
struct Node* removeFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        return current;
    }
    return NULL;
}

// Function to remove the last occurrence of a given value from the list
struct Node* removeLastOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        previous->next = current->next;
        free(current);
        return current;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Remove the first occurrence of 2
    struct Node* removed = removeFirstOccurrence(&head, 2);
    if (removed != NULL) {
        printf("Removed node: %d\n", removed->data);
    }

    // Remove the last occurrence of 4
    removed = removeLastOccurrence(&head, 4);
    if (removed != NULL) {
        printf("Removed node: %d\n", removed->data);
    }

    // Print the remaining nodes
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}