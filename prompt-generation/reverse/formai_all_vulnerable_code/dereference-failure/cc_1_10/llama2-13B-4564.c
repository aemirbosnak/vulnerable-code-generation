//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Declare a function to create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Declare a function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a new node with data 1
    struct Node* node1 = newNode(1);

    // Create a new node with data 2
    struct Node* node2 = newNode(2);

    // Create a new node with data 3
    struct Node* node3 = newNode(3);

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;

    // Print the linked list
    printList(node1);

    // Double the data of each node
    struct Node* current = node1;
    while (current != NULL) {
        current->data *= 2;
        current = current->next;
    }

    // Print the linked list again
    printList(node1);

    return 0;
}