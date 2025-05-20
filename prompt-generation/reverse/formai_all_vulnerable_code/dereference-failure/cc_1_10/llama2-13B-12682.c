//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node into the graph
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the graph
void printGraph(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the graph
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the graph
    printGraph(head);

    return 0;
}