//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
struct Node {
    int data; // node data
    struct Node* next; // next node in the graph
};

struct Edge {
    int src; // source node
    int dest; // destination node
};

// Graph functions
void add_node(struct Node** graph, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *graph;
    *graph = new_node;
}

void add_edge(struct Node** graph, int src, int dest) {
    struct Edge* new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    new_edge->src = src;
    new_edge->dest = dest;
    struct Node* src_node = *(graph + src);
    struct Node* dest_node = *(graph + dest);
    src_node->next = dest_node;
    dest_node->next = new_edge;
}

void traverse(struct Node** graph) {
    struct Node* current = *graph;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* graph = NULL;

    // Add nodes and edges to the graph
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_node(&graph, 4);
    add_edge(&graph, 3, 4);

    // Traverse the graph
    traverse(&graph);

    return 0;
}