//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the graph
void insertNode(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        if (data < (*head_ref)->data) {
            (*head_ref)->left = new_node;
        } else {
            (*head_ref)->right = new_node;
        }
    }
}

// Function to traverse the graph
void traverse(Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        traverse(node->left);
        traverse(node->right);
    }
}

int main() {
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    traverse(head);

    return 0;
}