//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define EDGE_LIST_SIZE 100

// Graph structure
typedef struct node {
    int label;    // Node label
    struct node* next; // Next node in the list
    struct node* prev; // Previous node in the list
    int weight;   // Edge weight
} Node;

// Graph representation
typedef struct graph {
    Node* nodes; // Array of nodes
    int num_nodes; // Number of nodes in the graph
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->nodes = (Node*) malloc(MAX_NODES * sizeof(Node));
    g->num_nodes = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int label) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->weight = 0;
    if (g->num_nodes == MAX_NODES) {
        printf("Error: Maximum number of nodes reached\n");
        return;
    }
    g->nodes[g->num_nodes] = *new_node;
    g->num_nodes++;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int from, int to, int weight) {
    Node* from_node = g->nodes + from;
    Node* to_node = g->nodes + to;
    from_node->weight = weight;
    to_node->next = from_node;
    from_node->prev = to_node;
    if (from == to) {
        printf("Error: Self-loop not allowed\n");
        return;
    }
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node* node = g->nodes + i;
        printf("%d: %d -> ", node->label, node->next->label);
        for (int j = 0; j < node->weight; j++) {
            printf("%d ", node->next->label);
        }
        printf("\n");
    }
}

int main() {
    Graph* g = new_graph();
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_edge(g, 1, 2, 2);
    add_edge(g, 2, 3, 3);
    add_edge(g, 3, 4, 4);
    print_graph(g);
    return 0;
}