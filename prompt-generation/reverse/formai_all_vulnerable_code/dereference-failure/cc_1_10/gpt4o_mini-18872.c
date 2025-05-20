//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize matrix to zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Ensure undirected graph
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

bool isSafe(int vertex, Graph *graph, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph *graph, int m, int color[], int vertex) {
    // If all vertices are assigned a color
    if (vertex == graph->numVertices) {
        return true;
    }

    // Try different colors
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }

            // Backtrack
            color[vertex] = 0;
        }
    }

    return false;
}

void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    // Print the color assigned to each vertex
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
    int vertices = V;
    Graph *graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    int m = 3; // Number of colors
    graphColoring(graph, m);

    freeGraph(graph);
    return 0;
}