//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int destination;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int id;
    Edge* edgeList;
} Vertex;

typedef struct Graph {
    int vertexCount;
    Vertex* vertices;
} Graph;

Graph* createGraph(int vertexCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->vertices = (Vertex*)malloc(vertexCount * sizeof(Vertex));
    
    for (int i = 0; i < vertexCount; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].edgeList = NULL;
    }
    
    return graph;
}

Edge* createEdge(int destination) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destination = destination;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Graph* graph, int source, int destination) {
    Edge* newEdge = createEdge(destination);
    newEdge->next = graph->vertices[source].edgeList;
    graph->vertices[source].edgeList = newEdge;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("Vertex %d: ", graph->vertices[i].id);
        Edge* edge = graph->vertices[i].edgeList;
        while (edge) {
            printf("%d -> ", edge->destination);
            edge = edge->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        Edge* edge = graph->vertices[i].edgeList;
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
    int vertexCount;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertexCount);

    Graph* graph = createGraph(vertexCount);
    
    while (1) {
        int source, destination;
        printf("Enter source and destination edges to add (-1 -1 to exit): ");
        scanf("%d %d", &source, &destination);
        if (source == -1 && destination == -1) {
            break;
        }
        if (source < 0 || source >= vertexCount || 
            destination < 0 || destination >= vertexCount) {
            printf("Invalid edge. Please enter valid vertex indices.\n");
        } else {
            addEdge(graph, source, destination);
            printf("Edge added from %d to %d.\n", source, destination);
        }
    }

    printf("\nAdjacency List Representation of Graph:\n");
    printGraph(graph);

    freeGraph(graph);
    return 0;
}