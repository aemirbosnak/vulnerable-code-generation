//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// A structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph->adj[i][j] = 0;
    return graph;
}

// Function to add an undirected edge between u and v
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1; // Because the graph is undirected
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j])
                printf("%d ", j);
        }
    }
}

// A utility function to check if the current color assignment
// is safe for vertex v
int isSafe(int v, struct Graph* graph, int color[], int c) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// A recursive utility function to solve m coloring problem
int graphColoringUtil(struct Graph* graph, int m, int color[], int v) {
    if (v == graph->V)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return 1;
            color[v] = 0; // Backtrack
        }
    }
    return 0;
}

// Function to solve the m-coloring problem using backtracking
void graphColoring(struct Graph* graph, int m) {
    int* color = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0))
        printf("Solution exists: The colors assigned are:\n");
    else
        printf("Solution does not exist.\n");

    for (int i = 0; i < graph->V; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);

    free(color);
}

int main() {
    int V, E, m;
    struct Graph* graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printGraph(graph);
    graphColoring(graph, m);

    // Free allocated memory
    free(graph);
    return 0;
}