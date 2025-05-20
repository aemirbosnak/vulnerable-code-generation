//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int source;
    int destination;
    int weight;
};

struct Graph {
    int number_of_vertices;
    int number_of_edges;
    struct Edge *edges;
};

struct Graph *create_graph(int number_of_vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->number_of_vertices = number_of_vertices;
    graph->number_of_edges = 0;
    graph->edges = NULL;
    return graph;
}

void add_edge(struct Graph *graph, int source, int destination, int weight) {
    graph->edges = realloc(graph->edges, (graph->number_of_edges + 1) * sizeof(struct Edge));
    graph->edges[graph->number_of_edges].source = source;
    graph->edges[graph->number_of_edges].destination = destination;
    graph->edges[graph->number_of_edges].weight = weight;
    graph->number_of_edges++;
}

void print_graph(struct Graph *graph) {
    for (int i = 0; i < graph->number_of_edges; i++) {
        printf("Edge %d: (%d, %d, %d)\n", i, graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main() {
    struct Graph *graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 1, 3, 40);
    add_edge(graph, 2, 3, 50);
    add_edge(graph, 3, 4, 60);
    add_edge(graph, 4, 0, 70);

    print_graph(graph);

    return 0;
}