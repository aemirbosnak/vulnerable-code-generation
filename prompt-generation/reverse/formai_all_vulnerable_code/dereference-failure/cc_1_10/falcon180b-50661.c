//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 10000

typedef struct {
    int id;
    char name[20];
} Vertex;

typedef struct {
    int id;
    char name[20];
    int weight;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Vertex* vertices;
    Edge* edges;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->vertices = (Vertex*) malloc(MAX_VERTEX * sizeof(Vertex));
    graph->edges = (Edge*) malloc(MAX_EDGE * sizeof(Edge));
    return graph;
}

void destroyGraph(Graph* graph) {
    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

void addEdge(Graph* graph, int startId, int endId, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->id = graph->numEdges;
    edge->name[0] = '\0';
    edge->weight = weight;
    graph->edges[graph->numEdges] = *edge;
    graph->numEdges++;
}

void addVertex(Graph* graph, int id, char* name) {
    Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
    vertex->id = id;
    strcpy(vertex->name, name);
    graph->vertices[graph->numVertices] = *vertex;
    graph->numVertices++;
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph, 1, "A");
    addVertex(graph, 2, "B");
    addVertex(graph, 3, "C");
    addVertex(graph, 4, "D");
    addVertex(graph, 5, "E");
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 4, 5, 5);
    destroyGraph(graph);
    return 0;
}