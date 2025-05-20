//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
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

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjacencyMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int isSafe(int vertex, Graph* g, int colors[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(Graph* g, int m, int colors[], int vertex) {
    if (vertex == g->numVertices) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, g, colors, c)) {
            colors[vertex] = c;

            if (graphColoringUtil(g, m, colors, vertex + 1)) {
                return 1;
            }

            colors[vertex] = 0; // Backtracking
        }
    }
    return 0;
}

void graphColoring(Graph* g, int m) {
    int* colors = (int*)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        colors[i] = 0;
    }

    if (graphColoringUtil(g, m, colors, 0)) {
        printf("Solution Exists: Following are the assigned colors:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }

    free(colors);
}

int main() {
    Graph g;
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(&g, vertices);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Graph adjacency list representation:\n");
    printGraph(&g);

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}