//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    return graph;
}

void add_edge(Graph* graph, int vertex1, int vertex2, int weight) {
    if (graph->num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached\n");
        return;
    }
    graph->edges[graph->num_edges].vertex = vertex2;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->edges[j].vertex == i) {
                printf("(%d, %d) ", graph->edges[j].vertex, graph->edges[j].weight);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 5);
    add_edge(graph, 1, 3, 7);
    add_edge(graph, 2, 3, 2);
    add_edge(graph, 2, 4, 8);
    add_edge(graph, 3, 4, 3);
    print_graph(graph);
    return 0;
}