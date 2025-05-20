//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Define a function to print out the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a new node with value 1
    struct Node* node1 = newNode(1);

    // Create a new node with value 2
    struct Node* node2 = newNode(2);

    // Create a new node with value 3
    struct Node* node3 = newNode(3);

    // Set the next pointer of node1 to point to node2
    node1->next = node2;

    // Set the next pointer of node2 to point to node3
    node2->next = node3;

    // Print out the linked list
    printList(node1);

    // Free the memory of the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}