//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 50

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    return graph;
}

void initializeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0; // No self loop
            } else {
                graph->adjMatrix[i][j] = rand() % 2; // Randomly assign edges
            }
        }
    }
}

bool isSafe(int vertex, int color[], Graph *graph, int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true; // Safe to assign color
}

bool graphColoringUtil(Graph *graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return true; // All vertices colored successfully
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, graph, c)) {
            color[vertex] = c; // Assign color
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return false; // No color can be assigned
}

void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize colors
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    free(color);
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    srand(time(NULL)); // seed random number generator
    int vertices = 10; // Number of vertices
    int colors = 3; // Number of colors

    Graph *graph = createGraph(vertices);
    initializeGraph(graph);
    
    printf("Adjacency Matrix of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }

    graphColoring(graph, colors);
    freeGraph(graph);

    return 0;
}