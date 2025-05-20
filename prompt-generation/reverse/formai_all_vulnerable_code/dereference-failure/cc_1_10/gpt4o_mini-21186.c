//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; // No edges initially
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // Undirected graph
}

bool isSafe(int v, Graph *g, int color[], int c) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] == 1 && color[i] == c) {
            return false; // Cannot color with the same color
        }
    }
    return true;
}

bool graphColoringUtil(Graph *g, int m, int color[], int v) {
    if (v == g->vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; // Assign color c to vertex v

            if (graphColoringUtil(g, m, color, v + 1)) {
                return true; // Recursive call
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        color[i] = 0; // Initialize color array
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Coloring of the graph is possible with %d colors.\n", m);
        for (int i = 0; i < g->vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Coloring of the graph is not possible with %d colors.\n", m);
    }

    free(color);
}

int main() {
    Graph g;
    int vertices, edges, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source and destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}