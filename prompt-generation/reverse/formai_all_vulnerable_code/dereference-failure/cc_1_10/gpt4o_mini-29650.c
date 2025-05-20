//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Undirected graph
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

bool isSafe(int v, Graph* graph, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] == 1 && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph* graph, int m, int color[], int v) {
    if (v == graph->numVertices) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

void graphColoring(Graph* graph, int m) {
    int* color = (int*)calloc(graph->numVertices, sizeof(int));
    
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }
  
    free(color);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices, edges, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges in the format 'src dest':\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    freeGraph(graph);
    
    return 0;
}