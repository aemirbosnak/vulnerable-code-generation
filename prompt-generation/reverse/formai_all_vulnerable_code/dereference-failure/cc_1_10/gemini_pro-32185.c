//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Romeo and Juliet Graph Coloring Problem

// Structure to represent a node in the graph
typedef struct node {
    int color;
    int num_neighbors;
    int *neighbors;
} node;

// Structure to represent the graph
typedef struct graph {
    int num_nodes;
    node *nodes;
} graph;

// Function to create a new graph
graph *create_graph(int num_nodes) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = (node *)malloc(num_nodes * sizeof(node));
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i].color = -1;
        g->nodes[i].num_neighbors = 0;
        g->nodes[i].neighbors = NULL;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(graph *g, int u, int v) {
    g->nodes[u].neighbors = (int *)realloc(g->nodes[u].neighbors, (g->nodes[u].num_neighbors + 1) * sizeof(int));
    g->nodes[u].neighbors[g->nodes[u].num_neighbors++] = v;
    g->nodes[v].neighbors = (int *)realloc(g->nodes[v].neighbors, (g->nodes[v].num_neighbors + 1) * sizeof(int));
    g->nodes[v].neighbors[g->nodes[v].num_neighbors++] = u;
}

// Function to check if the graph is colored properly
int is_colored_properly(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->nodes[i].num_neighbors; j++) {
            if (g->nodes[i].color == g->nodes[g->nodes[i].neighbors[j]].color) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: color %d, neighbors: ", i, g->nodes[i].color);
        for (int j = 0; j < g->nodes[i].num_neighbors; j++) {
            printf("%d ", g->nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

// Function to free the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i].neighbors);
    }
    free(g->nodes);
    free(g);
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph(6);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);

    // Color the graph
    g->nodes[0].color = 1;
    g->nodes[1].color = 2;
    g->nodes[2].color = 3;
    g->nodes[3].color = 4;
    g->nodes[4].color = 5;
    g->nodes[5].color = 6;

    // Print the graph
    print_graph(g);

    // Check if the graph is colored properly
    if (is_colored_properly(g)) {
        printf("The graph is colored properly.\n");
    } else {
        printf("The graph is not colored properly.\n");
    }

    // Free the graph
    free_graph(g);

    return 0;
}