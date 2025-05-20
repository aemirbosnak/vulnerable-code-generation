//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the graph.
#define MAX_SIZE 100

// Define the data structure for a graph node.
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the data structure for a graph.
typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t *adj_list[MAX_SIZE];
} graph_t;

// Create a new graph.
graph_t *create_graph() {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->num_vertices = 0;
    graph->num_edges = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// Add a vertex to the graph.
void add_vertex(graph_t *graph, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    graph->adj_list[graph->num_vertices] = new_node;
    graph->num_vertices++;
}

// Add an edge to the graph.
void add_edge(graph_t *graph, int src, int dest) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = dest;
    new_node->next = NULL;

    node_t *temp = graph->adj_list[src];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    graph->num_edges++;
}

// Print the graph.
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *temp = graph->adj_list[i];
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the graph.
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *temp = graph->adj_list[i];
        while (temp != NULL) {
            node_t *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(graph);
}

// Main function.
int main() {
    // Create a new graph.
    graph_t *graph = create_graph();

    // Add vertices to the graph.
    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);

    // Add edges to the graph.
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph.
    print_graph(graph);

    // Free the graph.
    free_graph(graph);

    return 0;
}