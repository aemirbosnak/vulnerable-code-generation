//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a node in the graph
typedef struct node {
    int data;
    struct node *next;
} node;

// Define a graph
typedef struct graph {
    int num_vertices;
    struct node **adj_lists;
} graph;

// Create a new graph
graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_lists = (node **)malloc(sizeof(node *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_lists[i] = NULL;
    }
    return g;
}

// Add an edge to the graph
void add_edge(graph *g, int src, int dest) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = dest;
    new_node->next = NULL;

    // Add the new node to the adjacency list of the source vertex
    node *curr = g->adj_lists[src];
    if (curr == NULL) {
        g->adj_lists[src] = new_node;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *curr = g->adj_lists[i];
        printf("%d: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    graph *g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    // Print the graph
    print_graph(g);

    return 0;
}