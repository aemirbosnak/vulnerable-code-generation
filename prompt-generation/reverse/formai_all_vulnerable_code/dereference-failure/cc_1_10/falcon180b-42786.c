//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000

typedef struct {
    int vertex;
    struct Edge* next;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Edge* edges;
    int* visited;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->edges = (Edge*)malloc(MAX_EDGES * sizeof(Edge));
    graph->visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = vertex2;
    newEdge->next = graph->edges[vertex1].next;
    graph->edges[vertex1].next = newEdge;
    graph->numEdges++;
}

void DFS(Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);
    Edge* currentEdge = graph->edges[startVertex].next;
    while (currentEdge!= NULL) {
        int nextVertex = currentEdge->vertex;
        if (graph->visited[nextVertex] == 0) {
            DFS(graph, nextVertex);
        }
        currentEdge = currentEdge->next;
    }
}

int main() {
    Graph* graph = createGraph(9);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 7);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 7);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    DFS(graph, 0);
    return 0;
}