//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: dynamic
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
void insertAtStart(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(value);
}

// Function to remove the first occurrence of a value in the list
void removeValue(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL && current->data != value) {
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
    }
}

// Function to find the first node that has a given value in the list
struct Node* findValue(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;

    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove some nodes from the list
    removeValue(&head, 2);
    removeValue(&head, 3);

    // Find a node in the list
    struct Node* node = findValue(&head, 4);
    if (node != NULL) {
        printf("Found node with value %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}