//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

void destroy_graph(Graph* graph) {
    free(graph);
}

void add_edge(Graph* graph, int source, int destination) {
    graph->adj_matrix[source][destination] = 1;
    graph->num_edges++;
}

void remove_edge(Graph* graph, int source, int destination) {
    graph->adj_matrix[source][destination] = 0;
    graph->num_edges--;
}

int has_edge(Graph* graph, int source, int destination) {
    return graph->adj_matrix[source][destination];
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = create_graph(5);

    // Add some edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the adjacency matrix of the graph
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Check if there is an edge between vertices 0 and 3
    if (has_edge(graph, 0, 3)) {
        printf("There is an edge between vertices 0 and 3.\n");
    } else {
        printf("There is no edge between vertices 0 and 3.\n");
    }

    // Remove the edge between vertices 1 and 2
    remove_edge(graph, 1, 2);

    // Print the adjacency matrix of the graph again
    printf("Adjacency matrix after removing the edge between vertices 1 and 2:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}