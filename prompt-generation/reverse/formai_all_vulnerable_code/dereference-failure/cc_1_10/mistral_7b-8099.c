//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->vertices[i][j] = 0;
        }
    }
    return graph;
}

void addVertex(Graph* graph) {
    if (graph->num_vertices < MAX_VERTICES) {
        graph->vertices[graph->num_vertices][graph->num_vertices] = 1;
        graph->num_vertices++;
    }
}

void addEdge(Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->num_vertices && destination >= 0 && destination < graph->num_vertices) {
        graph->vertices[source][destination] = 1;
        graph->vertices[destination][source] = 1;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d : ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->vertices[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 0);
    printGraph(graph);
    return 0;
}