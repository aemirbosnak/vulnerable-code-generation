//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numEdges * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src][dest] = 1;
}

void graphColoring(Graph* graph) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }
    int i = 0;
    while (i < graph->numVertices && color[i] == -1) {
        int available = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && color[j] != -1) {
                available = 1;
            }
        }
        if (available) {
            color[i] = 0;
        } else {
            i++;
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d colored with %d\n", i, color[i]);
    }
    free(color);
}

int main() {
    Graph* graph = createGraph(5, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    graphColoring(graph);
    free(graph);
    return 0;
}