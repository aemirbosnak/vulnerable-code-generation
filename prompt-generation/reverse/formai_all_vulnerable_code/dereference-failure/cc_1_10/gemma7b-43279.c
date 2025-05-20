//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
    char name[20];
} Vertex;

typedef struct Graph {
    Vertex** vertices;
    int numVertices;
    int numEdges;
    struct Edge** edges;
} Graph;

struct Edge {
    int srcIndex;
    int destIndex;
    char label[20];
};

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = malloc(MAX_VERTICES * sizeof(Vertex));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->edges = malloc(MAX_EDGES * sizeof(struct Edge));

    return graph;
}

void addVertex(Graph* graph, char* name) {
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->index = graph->numVertices++;
    vertex->neighbors = NULL;
    strcpy(vertex->name, name);

    graph->vertices[vertex->index] = vertex;
}

void addEdge(Graph* graph, int srcIndex, int destIndex, char* label) {
    struct Edge* edge = malloc(sizeof(struct Edge));
    edge->srcIndex = srcIndex;
    edge->destIndex = destIndex;
    strcpy(edge->label, label);

    graph->edges[graph->numEdges++] = edge;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("Vertex: %s, Index: %d\n", vertex->name, vertex->index);

        for (struct Edge* edge = vertex->neighbors; edge; edge) {
            printf("Edge: %s - %s, Label: %s\n", vertex->name, graph->vertices[edge->destIndex]->name, edge->label);
        }
    }
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph, "Alice");
    addVertex(graph, "Bob");
    addVertex(graph, "Charlie");
    addEdge(graph, 0, 1, "Strong");
    addEdge(graph, 1, 2, "Weak");
    addEdge(graph, 2, 0, "Close");

    printGraph(graph);

    return 0;
}