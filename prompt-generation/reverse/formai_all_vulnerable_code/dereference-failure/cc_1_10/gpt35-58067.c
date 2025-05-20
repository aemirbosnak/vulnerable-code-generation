//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// creates a new graph and sets all edges to zero
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    
    return graph;
}

// adds an edge to the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < graph->num_vertices && vertex2 >= 0 && vertex2 < graph->num_vertices) {
        graph->adjacency_matrix[vertex1][vertex2] = 1;
        graph->adjacency_matrix[vertex2][vertex1] = 1;
        graph->num_edges++;
    }
}

// prints the graph
void print_graph(Graph* graph) {
    int i, j;
    printf("    ");
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}