//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct graphEdge {
    int src, dest, weight;
} GraphEdge;

typedef struct adjList {
    int dest, weight;
    struct adjList* next;
} AdjList;

typedef struct graph {
    int numVertices, numEdges;
    AdjList** adjLists;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->adjLists = malloc(numVertices * sizeof(AdjList*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjList* newEdge = malloc(sizeof(AdjList));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;
}

void printGraph(Graph* graph) {
    printf("--- Graph ---\n\n");
    printf("Number of vertices: %d\n", graph->numVertices);
    printf("Number of edges: %d\n", graph->numEdges);
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        AdjList* adjList = graph->adjLists[i];
        while (adjList) {
            printf("(%d, %d) ", adjList->dest, adjList->weight);
            adjList = adjList->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;
    int numEdges = 6;

    // Create graph
    Graph* graph = createGraph(numVertices, numEdges);

    // Add edges
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 3, 4, 3);

    // Print graph
    printGraph(graph);

    // Clean up
    for (int i = 0; i < graph->numVertices; i++) {
        AdjList* adjList = graph->adjLists[i];
        while (adjList) {
            AdjList* temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}