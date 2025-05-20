//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INIT_INFINITY 9999999

typedef struct {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = INIT_INFINITY;
        }
    }
    
    return graph;
}

void add_edge(Graph* graph, int u, int v, int weight) {
    graph->adj_matrix[u][v] = weight;
    graph->num_edges++;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == INIT_INFINITY) {
                printf("∞ ");
            } else {
                printf("%d ", graph->adj_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 5);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 2);
    add_edge(graph, 2, 4, 6);
    add_edge(graph, 3, 4, 8);
    
    print_graph(graph);
    
    return 0;
}