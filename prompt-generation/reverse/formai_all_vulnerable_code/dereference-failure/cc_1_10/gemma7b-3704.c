//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10
#define MAX_C 3

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numColors;
} Graph;

Graph* createGraph(int numVertices, int numColors) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numColors = numColors;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numColors * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

int graphColor(Graph* graph) {
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && colors[i] == colors[j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Graph* graph = createGraph(5, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    if (graphColor(graph)) {
        printf("Graph coloring is successful!\n");
    } else {
        printf("Graph coloring is unsuccessful!\n");
    }

    return 0;
}