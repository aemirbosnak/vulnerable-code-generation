//FormAI DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a new node to the end of the linked list
void append(struct Node** headRef, int data) {
    struct Node* node = newNode(data);
    struct Node* current = *headRef;
    if (current == NULL) {
        *headRef = node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    printf("[ ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Add some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Print the linked list
    printf("Linked list before modification:\n");
    printList(head);

    // Modify the linked list by removing the second node
    struct Node* nodeToRemove = head->next;
    head->next = nodeToRemove->next;
    free(nodeToRemove);

    // Print the linked list again
    printf("Linked list after modification:\n");
    printList(head);

    return 0;
}