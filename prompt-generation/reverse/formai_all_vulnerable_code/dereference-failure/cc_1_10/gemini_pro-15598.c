//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// A visionary representation of a graph as a constellation of vertices connected by ethereal links.

// A vertex in the celestial tapestry.
typedef struct Vertex {
    char *name;
    struct Edge *edges;
} Vertex;

// A conduit of the cosmic forces that bind vertices.
typedef struct Edge {
    Vertex *destination;
    int weight;
    struct Edge *next;
} Edge;

// The celestial canvas upon which the graph is inscribed.
typedef struct Graph {
    Vertex *vertices;
    int vertexCount;
    Edge *edges;
    int edgeCount;
} Graph;

// A celestial cartographer, guiding us through the graph's ethereal expanse.
Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertexCount = 0;
    graph->edges = NULL;
    graph->edgeCount = 0;
    return graph;
}

// Summoning a vertex into the celestial mosaic.
Vertex *addVertex(Graph *graph, char *name) {
    Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
    vertex->name = name;
    vertex->edges = NULL;
    graph->vertices = (Vertex *)realloc(graph->vertices, (graph->vertexCount + 1) * sizeof(Vertex));
    graph->vertices[graph->vertexCount++] = *vertex;
    return vertex;
}

// Forging an ethereal link between two vertices.
void addEdge(Graph *graph, Vertex *source, Vertex *destination, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->destination = destination;
    edge->weight = weight;
    edge->next = source->edges;
    source->edges = edge;
    graph->edges = (Edge *)realloc(graph->edges, (graph->edgeCount + 1) * sizeof(Edge));
    graph->edges[graph->edgeCount++] = *edge;
}

// A celestial voyager, traversing the graph's ethereal expanse.
void traverseGraph(Graph *graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("Vertex: %s\n", graph->vertices[i].name);
        for (Edge *edge = graph->vertices[i].edges; edge != NULL; edge = edge->next) {
            printf("  Edge to: %s (weight: %d)\n", edge->destination->name, edge->weight);
        }
    }
}

// A celestial cartographer, sketching the graph's ethereal form.
void visualizeGraph(Graph *graph) {
    // TODO: Implement this ethereal visualization.
}

// The celestial tapestry, a mosaic of vertices and ethereal links.
int main() {
    Graph *graph = createGraph();

    Vertex *vertex1 = addVertex(graph, "Sol");
    Vertex *vertex2 = addVertex(graph, "Luna");
    Vertex *vertex3 = addVertex(graph, "Terra");

    addEdge(graph, vertex1, vertex2, 384400);
    addEdge(graph, vertex1, vertex3, 149600000);
    addEdge(graph, vertex2, vertex3, 384400);

    traverseGraph(graph);
    visualizeGraph(graph);

    return 0;
}