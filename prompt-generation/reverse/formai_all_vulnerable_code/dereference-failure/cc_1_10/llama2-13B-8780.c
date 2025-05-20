//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct node {
    int data; // data stored in each node
    struct node* next; // pointer to next node in list
} Node;

// Graph functions
Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNode(Node** head_ref, int data) {
    Node* new_node = createNode(data);
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

void printGraph(Node* head) {
    if (head == NULL) {
        printf("Graph is empty\n");
        return;
    }
    printf("Graph contains the following nodes:\n");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print graph
    printGraph(head);

    return 0;
}