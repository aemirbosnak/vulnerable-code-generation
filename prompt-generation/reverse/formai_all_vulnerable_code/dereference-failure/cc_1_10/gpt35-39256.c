//FormAI DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct graph {
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    int i, j;
    for(i = 0; i < num_vertices; i++) {
        for(j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int source, int destination) {
    graph->adjacency_matrix[source][destination] = 1;
    graph->adjacency_matrix[destination][source] = 1;
}

void print_graph(Graph* graph) {
    printf("Adjacency Matrix Representation:\n");
    int i, j;
    for(i = 0; i < graph->num_vertices; i++) {
        for(j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);
    print_graph(graph);
    return 0;
}