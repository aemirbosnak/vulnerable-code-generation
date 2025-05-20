//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int **adjacencyMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // because it's an undirected graph
}

int isSafe(int vertex, int color[], Graph* graph, int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && color[i] == c) {
            return 0; // Unsafe
        }
    }
    return 1; // Safe
}

int graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    // If all vertices are assigned a color then return true
    if (vertex == graph->vertices) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, graph, c)) {
            color[vertex] = c; // Assign color

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;
            }

            // If no color can be assigned, remove the color (backtrack)
            color[vertex] = 0;
        }
    }
    return 0; // No solution found
}

void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution Exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist for m = %d\n", m);
    }

    free(color);
}

void removeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

void printIntroduction() {
    printf("Sherlock Holmes Graph Coloring Mystery!\n");
    printf("In this case, Holmes must assign colors to each vertex of the case\n");
    printf("without two adjacent vertices sharing the same color.\n");
    printf("Can you assist Holmes in solving this puzzle?\n\n");
}

int main() {
    printIntroduction();

    int vertices, edges, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter %d pairs of edges (format: src dest): \n", edges);
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src - 1, dest - 1); // Zero-based indexing
    }
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    removeGraph(graph);
    return 0;
}