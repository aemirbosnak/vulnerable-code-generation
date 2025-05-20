//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_Vertices 10

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = malloc(sizeof(int) * numVertices);
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

void graphColoring(Graph* graph) {
    int* colors = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int currentColor = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int available = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && colors[j] != -1) {
                if (colors[j] == currentColor) {
                    available = 0;
                }
            }
        }
        if (available) {
            colors[i] = currentColor;
        } else {
            currentColor++;
            colors[i] = currentColor;
        }
    }

    int maxColor = colors[0];
    for (int i = 1; i < graph->numVertices; i++) {
        if (colors[i] > maxColor) {
            maxColor = colors[i];
        }
    }

    printf("The maximum number of colors used in the graph is: %d\n", maxColor);
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    graphColoring(graph);

    return 0;
}