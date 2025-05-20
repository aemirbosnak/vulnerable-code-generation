//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertex;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge *edges[MAX_VERTICES];
} Graph;

Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void add_edge(Graph *graph, int source, int destination, int weight) {
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->vertex = destination;
    new_edge->weight = weight;
    new_edge->next = graph->edges[source];
    graph->edges[source] = new_edge;
    graph->num_edges++;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Edge *edge = graph->edges[i];
        while (edge != NULL) {
            printf("%d -> %d (%d)\n", i, edge->vertex, edge->weight);
            edge = edge->next;
        }
    }
}

int main() {
    Graph *graph = create_graph(6);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 4, 5);
    add_edge(graph, 1, 2, 15);
    add_edge(graph, 1, 4, 3);
    add_edge(graph, 2, 3, 20);
    add_edge(graph, 3, 5, 7);
    add_edge(graph, 4, 5, 1);

    print_graph(graph);

    return 0;
}