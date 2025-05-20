//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;  // Initialize adjacency matrix to 0
        }
    }
}

void addEdge(Graph* g, int v1, int v2) {
    g->adjMatrix[v1][v2] = 1;
    g->adjMatrix[v2][v1] = 1;  // Undirected graph
}

bool isSafe(int v, Graph* g, int* color, int c) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] == 1 && color[i] == c) {
            return false;  // Adjacent vertex has the same color
        }
    }
    return true;
}

bool graphColoringUtil(Graph* g, int m, int* color, int v) {
    if (v == g->vertices) {
        return true;  // All vertices are colored
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c;  // Assign color
            
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;  // If successful, return true
            }
            
            color[v] = 0;  // Backtrack
        }
    }
    return false;  // If no color can be assigned
}

void graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        color[i] = 0;  // Initialize all vertices to color 0
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < g->vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    free(color);
}

int main() {
    int vertices, edges, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph g;
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (format: v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        if (v1 < 1 || v1 > vertices || v2 < 1 || v2 > vertices) {
            printf("Invalid edge (%d, %d)\n", v1, v2);
            i--;  // Decrement to not count this invalid edge
            continue;
        }
        addEdge(&g, v1 - 1, v2 - 1);  // Adjust for 0-based index
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}