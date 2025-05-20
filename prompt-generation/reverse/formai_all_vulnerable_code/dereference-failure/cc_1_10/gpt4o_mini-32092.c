//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 30

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }

    return g;
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Because the graph is undirected
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int v, Graph* g, int color[], int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (g->adjMatrix[v][i] == 1 && color[i] == c) {
            return 0; // Not safe to color
        }
    }
    return 1; // Safe to color
}

int graphColoringUtil(Graph* g, int m, int color[], int vertex) {
    if (vertex == g->numVertices) {
        return 1; // All vertices colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, g, color, c, g->numVertices)) {
            color[vertex] = c; // Assign color c to vertex

            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return 1; // Recursively call for next vertex
            }

            color[vertex] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

void graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->numVertices * sizeof(int));

    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("No solution exists\n");
    }

    free(color);
}

int main() {
    int vertices, edges, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* g = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(g, src - 1, dest - 1); // Adjusting for 0-based index
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Adjacency Matrix of the graph:\n");
    printGraph(g);

    graphColoring(g, m);

    free(g);
    return 0;
}