//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

// Graph representation
typedef struct {
    int num_nodes;
    int num_edges;
    int *node_labels;
    int *edge_labels;
    int *adjacency_list;
} Graph;

// Create a new Graph
Graph* newGraph(int num_nodes) {
    Graph* g = malloc(sizeof(Graph));
    g->num_nodes = num_nodes;
    g->num_edges = 0;
    g->node_labels = malloc(num_nodes * sizeof(int));
    g->edge_labels = malloc(num_nodes * sizeof(int));
    g->adjacency_list = malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        g->node_labels[i] = i;
        g->edge_labels[i] = 0;
        g->adjacency_list[i] = 0;
    }
    return g;
}

// Add an edge to the Graph
void addEdge(Graph* g, int node1, int node2, int label) {
    g->num_edges++;
    g->edge_labels[g->num_edges - 1] = label;
    g->adjacency_list[node1] |= (1 << node2);
    g->adjacency_list[node2] |= (1 << node1);
}

// Print the Graph
void printGraph(Graph* g) {
    printf("Graph:\n");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < g->num_nodes; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    Graph* g = newGraph(6);
    addEdge(g, 0, 1, 1);
    addEdge(g, 0, 2, 2);
    addEdge(g, 1, 2, 3);
    addEdge(g, 2, 3, 4);
    addEdge(g, 2, 4, 5);
    addEdge(g, 3, 4, 6);
    printGraph(g);
    return 0;
}