//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    char* name;
    Edge* edges;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex* vertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex*)malloc(numVertices * sizeof(Vertex));

    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].name = (char*)malloc(64 * sizeof(char));
        sprintf(graph->vertices[i].name, "Vertex%d", i);
        graph->vertices[i].edges = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    // Create new edge for the source vertex
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->vertices[src].edges;
    graph->vertices[src].edges = newEdge;

    // Uncomment below for an undirected graph
    // Add new edge for the destination vertex
    /*
    newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = src;
    newEdge->next = graph->vertices[dest].edges;
    graph->vertices[dest].edges = newEdge;
    */
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s -> ", graph->vertices[i].name);
        Edge* edge = graph->vertices[i].edges;
        while (edge) {
            printf("%s ", graph->vertices[edge->dest].name);
            edge = edge->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->vertices[i].name);
        Edge* edge = graph->vertices[i].edges;
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->vertices);
    free(graph);
}

int main() {
    int numVertices = 5; // Example for a small graph
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list representation:\n");
    printGraph(graph);

    freeGraph(graph);
    return 0;
}