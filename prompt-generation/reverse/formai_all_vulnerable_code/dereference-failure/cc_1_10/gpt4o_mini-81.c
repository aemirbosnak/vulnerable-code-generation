//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; 
    int numVertices; 
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; 
        }
    }

    return g;
}

void addEdge(Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1; 
    g->adjMatrix[end][start] = 1; 
}

int isSafe(int v, Graph* g, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] && color[i] == c) {
            return 0; 
        }
    }
    return 1; 
}

int graphColoringUtil(Graph* g, int m, int color[], int v) {
    if (v == g->numVertices) {
        return 1; 
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; 

            if (graphColoringUtil(g, m, color, v + 1)) {
                return 1; 
            }

            color[v] = 0; 
        }
    }
    return 0; 
}

void graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; 
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: \n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d is colored with color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists\n");
    }

    free(color); 
}

void freeGraph(Graph* g) {
    free(g); 
}

int main() {
    int vertices = 5; 
    int edges;
    Graph* g = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge in the format 'start end':\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(g, start, end); 
    }

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(g, m);

    freeGraph(g);
    return 0;
}