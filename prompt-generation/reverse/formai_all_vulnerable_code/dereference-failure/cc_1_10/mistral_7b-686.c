//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data;
    int visited;
} Vertex;

typedef struct Edge {
    int dest;
    struct Edge *next;
} Edge;

typedef struct Graph {
    int V;
    Vertex *vertices;
    Edge *adjList;
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->vertices = (Vertex *)malloc(V * sizeof(Vertex));
    graph->adjList = NULL;
    for (int i = 0; i < V; i++) {
        graph->vertices[i].visited = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->adjList;
    graph->adjList = newEdge;
}

void DFSUtil(Graph *graph, int i, int visited[]) {
    visited[i] = 1;
    printf("%d ", graph->vertices[i].data);

    for (Edge *edge = graph->adjList; edge != NULL; edge = edge->next) {
        int dest = edge->dest;
        if (visited[dest] == 0)
            DFSUtil(graph, dest, visited);
    }
}

void DFS(Graph *graph, int src) {
    int V = graph->V;
    int *visited = (int *)calloc(V, sizeof(int));

    DFSUtil(graph, src, visited);
    free(visited);
}

int main() {
    int V = 5;
    Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    DFS(graph, 0);

    return 0;
}