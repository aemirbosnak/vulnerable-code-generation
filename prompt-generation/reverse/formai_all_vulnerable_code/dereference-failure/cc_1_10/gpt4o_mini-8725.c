//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

bool isSafe(int v, Graph* g, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph* g, int m, int color[], int v) {
    if (v == g->numVertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c;
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(int color[], int n) {
    printf("Solution exists: Following are the allocated colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

bool graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(sizeof(int) * g->numVertices);
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; // No color assigned initially
    }

    if (graphColoringUtil(g, m, color, 0) == false) {
        printf("Solution does not exist.\n");
        free(color);
        return false;
    }

    printSolution(color, g->numVertices);
    free(color);
    return true;
}

int main() {
    int vertices, edges, src, dest, m;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph g;
    initializeGraph(&g, vertices);

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            addEdge(&g, src, dest);
        } else {
            printf("Invalid edge! Please enter valid vertices.\n");
            i--; // Decrement to repeat this iteration
        }
    }

    // Input number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Solve the graph coloring problem
    graphColoring(&g, m);

    return 0;
}