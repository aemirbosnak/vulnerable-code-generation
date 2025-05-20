//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
struct Node {
    int label;    // Label of the node
    struct Node* next; // Next node in the graph
    struct Node* prev; // Previous node in the graph
};

// Function to create a new node
struct Node* newNode(int label) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to insert a node into the graph
void insertNode(struct Node** head_ref, int label) {
    struct Node* new_node = newNode(label);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
        new_node->prev = *head_ref;
        *head_ref = new_node;
    }
}

// Function to print the graph
void printGraph(struct Node* head) {
    if (head == NULL) {
        printf("Graph is empty.\n");
        return;
    }
    printf("Graph: \n");
    struct Node* current = head;
    while (current != NULL) {
        printf(" %d", current->label);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the graph
void traverseGraph(struct Node* head) {
    if (head == NULL) {
        printf("Graph is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf(" %d", current->label);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    printGraph(head);
    traverseGraph(head);
    return 0;
}