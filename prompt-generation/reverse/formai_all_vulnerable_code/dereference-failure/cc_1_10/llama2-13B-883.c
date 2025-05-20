//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Definition of the graph structure
typedef struct Node {
    int data;    // data stored in the node
    struct Node* next; // pointer to the next node in the list
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the graph
void printGraph(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node into the graph
void insertNode(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to search a node in the graph
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;

    // Insert nodes into the graph
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Search for a node in the graph
    Node* found = searchNode(head, 3);
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    // Print the graph
    printGraph(head);

    return 0;
}