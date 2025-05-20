//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Define a graph structure
typedef struct graph {
    int num_vertices;
    node_t* vertices;
} graph_t;

// Function to initialize a graph
graph_t* create_graph(int num_vertices) {
    graph_t* graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->vertices = malloc(num_vertices * sizeof(node_t));
    return graph;
}

// Function to add an edge to the graph
void add_edge(graph_t* graph, int v1, int v2) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = 0;
    new_node->next = graph->vertices[v1].next;
    graph->vertices[v1].next = new_node;
    graph->vertices[v2].next = graph->vertices[v1].next;
}

// Function to print the graph
void print_graph(graph_t* graph) {
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->vertices[i].data);
    }
    printf("\n");
}

int main() {
    // Create a graph with 5 vertices
    graph_t* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}