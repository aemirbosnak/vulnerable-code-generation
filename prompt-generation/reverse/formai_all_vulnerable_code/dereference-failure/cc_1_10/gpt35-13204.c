//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>

// A simple example of a singly linked list data structure

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    // Create the first node of the list
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 1;

    // Create the second node
    Node* second = (Node*) malloc(sizeof(Node));
    second->data = 2;
    head->next = second;

    // Create the third node
    Node* third = (Node*) malloc(sizeof(Node));
    third->data = 3;
    second->next = third;

    // Print the list
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Add a new node to the end of the list
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = 4;
    new_node->next = NULL;
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    // Print the list again
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the memory used by the nodes
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}