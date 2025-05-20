//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

Graph* graph_create(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->adjList = malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = malloc(sizeof(int) * numVertices);
    }
    graph->numVertices = numVertices;
    return graph;
}

void graph_add_edge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

int graph_coloring(Graph* graph) {
    int* colors = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int currentColor = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && colors[j] != -1) {
                availableColors++;
            }
        }

        if (availableColors == 0) {
            return -1;
        } else {
            colors[i] = currentColor;
            currentColor++;
        }
    }

    return 0;
}

int main() {
    Graph* graph = graph_create(5);
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 4);

    int result = graph_coloring(graph);

    if (result == 0) {
        printf("Graph colored successfully!\n");
    } else {
        printf("Graph coloring failed.\n");
    }

    return 0;
}