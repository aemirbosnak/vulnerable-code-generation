//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct Node {
    int data; // data stored in each node
    struct Node* next; // pointer to next node in the graph
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node into the graph
void insertNode(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
    }
    (*head_ref) = new_node;
}

// Function to traverse the graph
void traverse(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes into the graph
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Traverse the graph
    traverse(head);

    return 0;
}