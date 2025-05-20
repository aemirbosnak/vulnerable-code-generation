//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to append a node to the end of the list
void appendNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current = *head_ref;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = NULL;
}

// Function to insert a node at a specific position in the list
void insertNode(struct Node** head_ref, int position, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current = *head_ref;
    int i = 0;

    while (i < position - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    current->next = new_node;
    new_node->next = NULL;
}

// Function to search for a node in the list
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to remove a node from the list
void removeNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Example 1: Append a node to the end of the list
    appendNode(&head, 5);
    appendNode(&head, 10);
    appendNode(&head, 15);

    // Example 2: Insert a node at position 2
    insertNode(&head, 2, 20);

    // Example 3: Search for a node
    struct Node* node = searchNode(head, 10);
    if (node != NULL) {
        printf("Found node with value %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Example 4: Remove a node
    removeNode(&head, 15);

    return 0;
}