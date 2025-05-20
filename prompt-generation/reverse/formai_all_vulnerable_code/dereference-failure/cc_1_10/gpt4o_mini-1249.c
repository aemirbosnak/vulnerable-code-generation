//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;  // For undirected graph
}

bool isSafe(Graph *g, int v, int color[], int c) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(Graph *g, int m, int color[], int v) {
    if (v == g->vertices) {
        return true; // Successfully assigned colors
    }

    for (int c = 1; c <= m; c++) { // Try different colors
        if (isSafe(g, v, color, c)) {
            color[v] = c;  // Assign color c to vertex v

            if (graphColorUtil(g, m, color, v + 1)) {
                return true; // Recur for the next vertex
            }

            color[v] = 0; // Backtrack: remove color c from vertex v
        }
    }
    return false; // If no color can be assigned
}

void graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColorUtil(g, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < g->vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist for given color count %d\n", m);
    }

    free(color);
}

int main() {
    int vertices, edges, m;

    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    Graph g;
    initGraph(&g, vertices);
    
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (u v) for the graph:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u - 1, v - 1);  // Adjust for zero indexing
    }

    printf("Enter the maximum number of colors to use: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}