//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 20

typedef struct Graph {
    int matrix[MAX_VERTEX][MAX_VERTEX];
    int numVertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            g->matrix[i][j] = 0; // Initialize the adjacency matrix to zero
        }
    }
}

void addEdge(Graph *g, int start, int end) {
    g->matrix[start][end] = 1;
    g->matrix[end][start] = 1; // Undirected graph
}

bool isSafe(int v, Graph *g, int color[], int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (g->matrix[v][i] && c == color[i]) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

bool graphColoringUtil(Graph *g, int m, int color[], int v) {
    if (v == g->numVertices) {
        return true; // All vertices are processed
    }

    for (int c = 1; c <= m; c++) { // Trying different colors
        if (isSafe(v, g, color, c, g->numVertices)) {
            color[v] = c; // Assign color to vertex v
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtracking
        }
    }
    
    return false; // No valid color found
}

void graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; // Initialize all vertices to no color
    }
    
    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ----> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }
    
    free(color);
}

int main() {
    Graph g;
    int numVertices, numEdges, u, v, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initGraph(&g, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (u v) one per line:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    graphColoring(&g, m);
    
    return 0;
}