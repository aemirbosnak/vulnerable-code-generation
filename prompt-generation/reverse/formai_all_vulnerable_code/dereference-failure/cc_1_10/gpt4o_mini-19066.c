//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int isSafeToColor(Graph* graph, int vertex, int color, int* colors) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && colors[i] == color) {
            return 0; // Not safe to color
        }
    }
    return 1; // Safe to color
}

int graphColoringUtil(Graph* graph, int m, int* colors, int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices colored
    }

    for (int color = 1; color <= m; color++) {
        if (isSafeToColor(graph, vertex, color, colors)) {
            colors[vertex] = color; // Assign color
            
            if (graphColoringUtil(graph, m, colors, vertex + 1)) {
                return 1; // Successful coloring
            }

            colors[vertex] = 0; // Backtrack
        }
    }
    return 0; // No valid coloring found
}

void graphColoring(Graph* graph, int m) {
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, colors, 0)) {
        printf("Solution exists: \n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d is colored with color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution exists for the given number of colors.\n");
    }

    free(colors);
}

int main() {
    int numVertices, numEdges, src, dest, maxColors;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter maximum number of colors: ");
    scanf("%d", &maxColors);

    printf("Graph representation:\n");
    printGraph(graph);

    graphColoring(graph, maxColors);

    free(graph);
    return 0;
}