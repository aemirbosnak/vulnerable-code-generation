//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the graph structure
typedef struct {
    int vertex; // Vertex ID
    int weight; // Weight of the edge
    struct node *next; // Next node in the list
} edge;

typedef struct {
    int vertex; // Vertex ID
    edge *edges; // List of edges incident to this vertex
} node;

// Function to create a new graph
node* create_graph() {
    node* graph = (node*) malloc(sizeof(node));
    graph->vertex = 1;
    graph->edges = (edge*) malloc(sizeof(edge));
    return graph;
}

// Function to add an edge to the graph
void add_edge(node* graph, int v1, int v2, int weight) {
    edge* new_edge = (edge*) malloc(sizeof(edge));
    new_edge->vertex = v1;
    new_edge->weight = weight;
    new_edge->next = graph->edges;
    graph->edges = new_edge;
}

// Function to traverse the graph
void traverse(node* graph) {
    int i = 1;
    edge* current = graph->edges;

    do {
        printf("Vertex %d has edges to %d with weight %d\n", i, current->vertex, current->weight);
        current = current->next;
    } while (current != NULL);
}

int main() {
    node* graph = create_graph();

    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 5);
    add_edge(graph, 3, 4, 15);
    add_edge(graph, 4, 5, 20);
    add_edge(graph, 5, 1, 25);

    traverse(graph);

    return 0;
}