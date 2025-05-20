//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int source, int destination) {
    g->adjacencyMatrix[source][destination] = 1;
    g->adjacencyMatrix[destination][source] = 1; // Undirected graph
}

bool isSafe(Graph *g, int vertex, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph *g, int m, int color[], int vertex) {
    if (vertex == g->numVertices) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, vertex, color, c)) {
            color[vertex] = c; // Assign color c to vertex

            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return true;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(int color[], int vertices) {
    printf("Solution found:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    }
}

bool graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; // Not colored
    }

    if (!graphColoringUtil(g, m, color, 0)) {
        printf("No solution exists with %d colors.\n", m);
        free(color);
        return false;
    }

    printSolution(color, g->numVertices);
    free(color);
    return true;
}

int main() {
    printf("=== Cyberpunk Graph Coloring Experiment ===\n");
    Graph g;
    
    int vertices, edges, m;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initializeGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (source destination) in a Cyberpunk style:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src - 1, dest - 1); // Zero indexing
    }

    printf("These are the Neon colors available for your gang (1 to %d): ", MAX_COLORS);
    scanf("%d", &m);

    if (m > MAX_COLORS) {
        printf("Over the edge! Limiting to %d colors.\n", MAX_COLORS);
        m = MAX_COLORS;
    }

    if (!graphColoring(&g, m)) {
        printf("Sorry, gang. We couldn't find a color scheme.\n");
    } else {
        printf("Mission successful! Your crew is color-coordinated now!\n");
    }

    return 0;
}