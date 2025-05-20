//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Graph structure using a 2D array
typedef struct {
    int nodes[100][100]; // 2D array to represent the graph
    int num_nodes; // number of nodes in the graph
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_nodes = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int x, int y) {
    if (g->num_nodes == 0) {
        g->nodes[0][0] = x;
        g->nodes[0][1] = y;
    } else {
        int i = g->num_nodes / 2;
        if (x > g->nodes[i][0]) {
            i++;
        }
        g->nodes[i][0] = x;
        g->nodes[i][1] = y;
    }
    g->num_nodes++;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int x1, int y1, int x2, int y2) {
    add_node(g, x1, y1);
    add_node(g, x2, y2);
    g->nodes[x1][y1] = g->num_nodes - 2;
    g->nodes[x2][y2] = g->num_nodes - 1;
    g->num_nodes++;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            if (g->nodes[i][j] != 0) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main(void) {
    Graph* g = new_graph();

    // Add some nodes and edges to the graph
    add_node(g, 0, 0);
    add_node(g, 10, 0);
    add_node(g, 0, 10);
    add_node(g, 10, 10);
    add_edge(g, 0, 0, 10, 0);
    add_edge(g, 0, 10, 10, 0);
    add_edge(g, 10, 0, 10, 10);

    // Print the graph
    print_graph(g);

    // Free the memory
    free(g);

    return 0;
}