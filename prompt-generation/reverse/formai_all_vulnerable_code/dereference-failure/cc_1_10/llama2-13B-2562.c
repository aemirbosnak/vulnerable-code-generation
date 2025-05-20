//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct node {
    int label; // node label
    struct node* next; // next node in the graph
} Node;

// Define the graph functions
Node* create_node(int label) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->label = label;
    node->next = NULL;
    return node;
}

void add_node(Node** head_ref, int label) {
    Node* new_node = create_node(label);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void add_edge(Node** head_ref, int label_a, int label_b) {
    Node* a = create_node(label_a);
    Node* b = create_node(label_b);
    a->next = b;
    b->next = *head_ref;
    *head_ref = a;
}

void traverse(Node* head) {
    while (head != NULL) {
        printf("%d ", head->label);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Create the graph
    add_node(&head, 1);
    add_node(&head, 2);
    add_edge(&head, 1, 2);
    add_edge(&head, 2, 3);
    add_edge(&head, 3, 4);

    // Traverse the graph
    traverse(head);

    return 0;
}