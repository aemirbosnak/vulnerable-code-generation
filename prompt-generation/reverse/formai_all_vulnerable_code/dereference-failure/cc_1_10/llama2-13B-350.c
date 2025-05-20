//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the graph structure
typedef struct node {
    int label;
    struct node* next;
    struct node* prev;
} Node;

// Define the graph functions
Node* create_node(int label) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void add_edge(Node** head_ref, int label1, int label2) {
    Node* node1 = create_node(label1);
    Node* node2 = create_node(label2);
    node1->next = node2;
    node2->prev = node1;
    *head_ref = node1;
}

void print_graph(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->label);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Create the graph
    add_edge(&head, 1, 2);
    add_edge(&head, 2, 3);
    add_edge(&head, 3, 4);
    add_edge(&head, 4, 5);

    // Print the graph
    print_graph(head);

    return 0;
}