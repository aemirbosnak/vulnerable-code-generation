//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 1000

typedef struct {
    int vertex;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    int vertex;
    int degree;
    Edge *firstEdge;
} Vertex;

typedef struct {
    int numVertices;
    int numEdges;
    Vertex *vertices;
    Edge *edges;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->vertices = (Vertex *)malloc(numVertices * sizeof(Vertex));
    graph->edges = (Edge *)malloc(MAX_EDGE * sizeof(Edge));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].vertex = i;
        graph->vertices[i].degree = 0;
        graph->vertices[i].firstEdge = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int from, int to, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->vertex = to;
    newEdge->weight = weight;
    newEdge->next = graph->vertices[from].firstEdge;
    graph->vertices[from].firstEdge = newEdge;
    graph->vertices[to].degree++;
    graph->numEdges++;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Edge *edge = graph->vertices[i].firstEdge;
        while (edge!= NULL) {
            printf("(%d, %d) ", edge->vertex, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    printGraph(graph);
    return 0;
}