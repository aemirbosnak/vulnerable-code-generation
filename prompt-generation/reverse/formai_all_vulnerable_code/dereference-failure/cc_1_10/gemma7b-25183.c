//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int **adjList;
    int numVertices;
    int **visited;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->visited = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int *)malloc(numVertices * sizeof(int));
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

void traverseGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            graph->visited[i] = 1;

            printf("Visiting vertex %d\n", i);

            for (int j = 0; j < graph->numVertices; j++) {
                if (graph->adjList[i][j] && graph->visited[j] == 0) {
                    addEdge(graph, i, j);
                }
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    traverseGraph(graph);

    return 0;
}