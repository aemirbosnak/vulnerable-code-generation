//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Structure to represent a node in the graph
struct Node {
    int data; // data stored in the node
    struct Node* next; // pointer to the next node in the list
    struct Node* prev; // pointer to the previous node in the list
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to add a node to the graph
void addNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->prev = new_node;
    }
    new_node->next->prev = new_node;
}

// Function to traverse the graph
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Example usage of the graph
int main() {
    struct Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    traverse(head);
    return 0;
}