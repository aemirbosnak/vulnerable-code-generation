//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numVertices;
    int numEdges;
    int** adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->numEdges = 0;

    g->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return g;
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Undirected graph
    g->numEdges++;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int isSafe(int v, Graph* g, int** color, int col, int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
        if (g->adjMatrix[v][i] && color[i][0] == col) {
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(Graph* g, int m, int** color, int v, int vertexCount) {
    if (v == vertexCount) return 1;

    for (int col = 1; col <= m; col++) {
        if (isSafe(v, g, color, col, vertexCount)) {
            color[v][0] = col;
            if (graphColoringUtil(g, m, color, v + 1, vertexCount)) {
                return 1;
            }
            color[v][0] = 0; // Reset
        }
    }
    return 0; // backtrack
}

void graphColoring(Graph* g, int m) {
    int vertexCount = g->numVertices;
    int** color = (int**)malloc(vertexCount * sizeof(int*));
    for (int i = 0; i < vertexCount; i++) {
        color[i] = (int*)calloc(1, sizeof(int));
    }

    if (graphColoringUtil(g, m, color, 0, vertexCount)) {
        printf("Graph can be colored with %d colors:\n", m);
        for (int i = 0; i < vertexCount; i++) {
            printf("Vertex %d ==> Color %d\n", i, color[i][0]);
        }
    } else {
        printf("Graph cannot be colored with %d colors\n", m);
    }

    // Free color array
    for (int i = 0; i < vertexCount; i++) {
        free(color[i]);
    }
    free(color);
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}

int main() {
    int vertices = 5;
    Graph* g = createGraph(vertices);
    
    // Adding edges to the graph (example)
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);

    printf("Adjacency Matrix of the Graph:\n");
    printGraph(g);

    int m = 3; // Number of colors
    graphColoring(g, m);

    freeGraph(g);
    return 0;
}