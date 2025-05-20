//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Graph implementation
typedef struct {
    Node* head;
    Node* tail;
} Graph;

// Graph creation function
Graph* create_graph(int num_nodes) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->head = NULL;
    g->tail = NULL;
    for (int i = 0; i < num_nodes; i++) {
        Node* n = (Node*) malloc(sizeof(Node));
        n->data = i;
        n->next = NULL;
        if (i == 0) {
            g->head = n;
        } else if (i == num_nodes - 1) {
            g->tail = n;
        } else {
            g->head->next = n;
        }
        g->head = n;
    }
    return g;
}

// Graph traversal function
void traverse_graph(Graph* g) {
    Node* current = g->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Example usage
int main() {
    Graph* g = create_graph(10);
    traverse_graph(g);
    return 0;
}