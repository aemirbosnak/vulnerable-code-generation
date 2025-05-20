//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int*) malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void destroy_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
    graph->num_edges++;
}

void remove_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2] = 0;
    graph->adj_matrix[vertex2][vertex1] = 0;
    graph->num_edges--;
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);
    printf("Number of vertices: %d\n", graph->num_vertices);
    printf("Number of edges: %d\n", graph->num_edges);
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
    destroy_graph(graph);
    return 0;
}