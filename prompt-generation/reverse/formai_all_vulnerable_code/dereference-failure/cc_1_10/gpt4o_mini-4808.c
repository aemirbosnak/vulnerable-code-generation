//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Structure to represent a graph
typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
int isSafe(Graph* graph, int vertex, int color[], int c);
int graphColoringUtil(Graph* graph, int m, int color[], int vertex);
int graphColoring(Graph* graph, int m);

int main() {
    int vertices, edges, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    printf("Adjacency Matrix of the Graph:\n");
    printGraph(graph);
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    
    if (graphColoring(graph, m)) {
        printf("Graph can be colored with %d colors.\n", m);
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    free(graph);
    return 0;
}

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Initializing the adjacency matrix to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it is safe to color a vertex with a given color
int isSafe(Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Utility function for graph coloring
int graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1;
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;
            }
            color[vertex] = 0;
        }
    }
    return 0;
}

// Function to solve the graph coloring problem
int graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0;
    }
    
    int result = graphColoringUtil(graph, m, color, 0);
    free(color);
    return result;
}