//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge *edges;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->num_vertices = 0;
    graph->num_edges = 0;
    graph->edges = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    graph->edges = realloc(graph->edges, (graph->num_edges + 1) * sizeof(Edge));
    graph->edges[graph->num_edges++] = *edge;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            for (int k = 0; k < graph->num_edges; k++) {
                if (graph->edges[k].src == i && graph->edges[k].dest == j) {
                    printf("(%d, %d, %d) ", i, j, graph->edges[k].weight);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph();

    const int num_vertices = 5;
    const int num_edges = 6;

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 4, 4);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 3);

    graph->num_vertices = num_vertices;

    printGraph(graph);

    free(graph->edges);
    free(graph);

    return 0;
}