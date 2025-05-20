//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_Vertices * sizeof(int*));
    graph->numVertices = 0;
    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjList = (int**)realloc(graph->adjList, graph->numVertices * sizeof(int*));
    graph->adjList[graph->numVertices - 1] = (int*)malloc(MAX_Vertices * sizeof(int));
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

void graphColoring(Graph* graph) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && color[i] == color[j]) {
                color[i] = -1;
            }
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        if (color[i] == -1) {
            printf("No coloring solution\n");
            return;
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d colored with %d\n", i, color[i]);
    }
    free(color);
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    graphColoring(graph);
    return 0;
}