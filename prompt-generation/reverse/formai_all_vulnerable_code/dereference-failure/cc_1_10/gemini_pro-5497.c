//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Graph node
typedef struct node {
    int data;
    struct node *next;
} node;

// Graph
typedef struct graph {
    int num_vertices;
    node **adj_list;
} graph;

// Create a new graph
graph *create_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_list = malloc(sizeof(node *) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

// Add an edge to the graph
void add_edge(graph *g, int src, int dest) {
    node *new_node = malloc(sizeof(node));
    new_node->data = dest;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *curr = g->adj_list[i];
        printf("%d: ", i);
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Depth-first search (recursive)
void dfs(graph *g, int start) {
    // Mark the start node as visited
    printf("%d ", start);

    // Recursively visit all adjacent nodes
    node *curr = g->adj_list[start];
    while (curr) {
        if (curr->data != start) {
            dfs(g, curr->data);
        }
        curr = curr->next;
    }
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph(4);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Perform depth-first search
    printf("DFS: ");
    dfs(g, 0);  // Start DFS from node 0

    return 0;
}