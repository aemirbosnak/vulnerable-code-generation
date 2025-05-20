//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to traverse the linked list
void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("%d -> ", head->data);

    // Traverse the linked list
    traverse(head->next);

    printf("\n");
}

int main() {
    // Create a new node with data 1
    Node* node1 = newNode(1);

    // Create a new node with data 2
    Node* node2 = newNode(2);

    // Create a new node with data 3
    Node* node3 = newNode(3);

    // Set the next node of node1 to node2
    node1->next = node2;

    // Set the next node of node2 to node3
    node2->next = node3;

    // Traverse the linked list
    traverse(node1);

    return 0;
}