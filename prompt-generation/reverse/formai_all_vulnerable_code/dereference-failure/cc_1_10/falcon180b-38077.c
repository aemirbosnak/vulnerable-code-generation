//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 1000

typedef struct {
    int vertex;
    int color;
} AdjacencyList;

typedef struct {
    AdjacencyList* adjacencyList;
    int numVertices;
    int numColors;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjacencyList = (AdjacencyList*)malloc(numVertices * sizeof(AdjacencyList));
    graph->numVertices = numVertices;
    graph->numColors = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i].vertex = i;
        graph->adjacencyList[i].color = i;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjacencyList[u].color = v;
    graph->adjacencyList[v].color = u;
}

int minimumColor(Graph* graph, int vertex, int color) {
    int minColor = color;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyList[i].color == vertex && graph->adjacencyList[i].color < minColor) {
            minColor = graph->adjacencyList[i].color;
        }
    }
    return minColor;
}

void colorGraph(Graph* graph) {
    int numColors = graph->numVertices;
    int* usedColors = (int*)malloc(numColors * sizeof(int));
    for (int i = 0; i < numColors; i++) {
        usedColors[i] = 0;
    }
    int color = 0;
    while (color < numColors) {
        int vertex = rand() % graph->numVertices;
        int minColor = minimumColor(graph, vertex, color);
        if (minColor == color) {
            color++;
        } else {
            graph->adjacencyList[vertex].color = color;
            color++;
        }
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d - %d\n", graph->adjacencyList[i].vertex, graph->adjacencyList[i].color);
    }
}

int main() {
    srand(time(NULL));
    int numVertices = 10;
    Graph* graph = createGraph(numVertices);
    for (int i = 0; i < numVertices - 1; i++) {
        addEdge(graph, i, i + 1);
    }
    colorGraph(graph);
    printGraph(graph);
    return 0;
}