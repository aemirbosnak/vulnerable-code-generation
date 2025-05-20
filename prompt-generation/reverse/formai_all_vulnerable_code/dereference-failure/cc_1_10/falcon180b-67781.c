//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int vertex;
    int weight;
    int next;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Edge *edges;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->vertex = vertex2;
    newEdge->weight = weight;
    newEdge->next = graph->edges[vertex1].next;
    graph->edges[vertex1].next = newEdge;
    graph->numEdges++;
}

void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Edge *edge = graph->edges[i].next;
        while (edge!= NULL) {
            printf("(%d, %d) ", edge->vertex, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 10);
    addEdge(graph, 1, 3, 20);
    addEdge(graph, 2, 3, 15);
    addEdge(graph, 2, 4, 25);
    printGraph(graph);
    return 0;
}