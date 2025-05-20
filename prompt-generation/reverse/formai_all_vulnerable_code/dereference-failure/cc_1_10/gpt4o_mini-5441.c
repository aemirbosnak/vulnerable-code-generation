//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 50
#define INF 9999

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void addEdge(Graph *g, int src, int dest, int weight) {
    g->adjacencyMatrix[src][dest] = weight;
    g->adjacencyMatrix[dest][src] = weight; // Undirected graph
}

bool isSafe(int v, Graph *g, int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (g->adjacencyMatrix[v][i] != INF && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(Graph *g, int m, int color[], int v) {
    if (v == g->numVertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c, g->numVertices)) {
            color[v] = c;
            if (graphColorUtil(g, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(Graph *g, int m) {
    int *color = (int*)malloc(g->numVertices * sizeof(int));
    memset(color, 0, g->numVertices * sizeof(int));

    if (graphColorUtil(g, m, color, 0)) {
        printf("Coloring of vertices:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d --> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }
    free(color);
}

void printGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjacencyMatrix[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, v1, v2, weight;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges in the format (v1 v2 weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        addEdge(&g, v1 - 1, v2 - 1, weight);
    }

    printGraph(&g);

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}