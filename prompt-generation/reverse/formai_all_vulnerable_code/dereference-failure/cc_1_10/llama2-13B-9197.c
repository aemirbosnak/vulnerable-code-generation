//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GRAPH_MAX_NODES 100
#define GRAPH_MAX_EDGES 200

// Graph structure definition
typedef struct node {
    int label; // node label
    struct node* next; // next node in the graph
    struct node* prev; // previous node in the graph
} Node;

// Graph definition
typedef struct graph {
    Node* nodes; // array of nodes
    int num_nodes; // number of nodes in the graph
    int num_edges; // number of edges in the graph
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->nodes = (Node*) malloc(GRAPH_MAX_NODES * sizeof(Node));
    g->num_nodes = 0;
    g->num_edges = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int label) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (g->num_nodes == GRAPH_MAX_NODES) {
        printf("Oops! Maximum number of nodes reached! :O\n");
        return;
    }
    g->nodes[g->num_nodes] = *new_node;
    g->num_nodes++;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int label1, int label2) {
    if (g->num_edges == GRAPH_MAX_EDGES) {
        printf("Oops! Maximum number of edges reached! :O\n");
        return;
    }
    Node* node1 = g->nodes + g->num_nodes - 1;
    Node* node2 = g->nodes + g->num_nodes - 2;
    if (node1->label == label1 && node2->label == label2) {
        node1->next = node2;
        node2->prev = node1;
        g->num_edges++;
    } else {
        printf("Error! Node labels do not match! :S\n");
    }
}

// Function to traverse the graph
void traverse(Graph* g) {
    Node* current = g->nodes;
    int i = 0;
    printf("Traversing Graph...\n");
    while (current != NULL) {
        printf("%d ", current->label);
        if (current->next != NULL) {
            current = current->next;
        } else {
            current = current->prev;
        }
        i++;
    }
    printf("\nGraph traversed successfully! :D\n");
}

int main() {
    Graph* g = new_graph();
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    traverse(g);
    return 0;
}