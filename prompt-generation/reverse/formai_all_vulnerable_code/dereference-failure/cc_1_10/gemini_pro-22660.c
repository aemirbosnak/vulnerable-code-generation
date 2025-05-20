//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
};

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    // Create adjacency matrix
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }

    // Initialize adjacency matrix to zero
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the graph is bipartite
int isBipartite(struct Graph* graph) {
    // Create a color array to store the colors of the vertices
    int *color = (int*)malloc(graph->V * sizeof(int));

    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // Assign a color to the first vertex
    color[0] = 0;

    // Queue to store the vertices to be colored
    int queue[graph->V];
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;

    // While there are vertices to be colored
    while (front != rear) {
        // Dequeue a vertex from the queue
        int u = queue[front++];

        // Iterate over all the adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->V; i++) {
            // If there is an edge between the dequeued vertex and the current adjacent vertex
            if (graph->adj[u][i] == 1) {
                // If the current adjacent vertex is not colored
                if (color[i] == -1) {
                    // Assign a color to the current adjacent vertex
                    color[i] = 1 - color[u];

                    // Enqueue the current adjacent vertex
                    queue[rear++] = i;
                }
                // If the current adjacent vertex is already colored and the color is the same as the dequeued vertex
                else if (color[i] == color[u]) {
                    return 0;  // Graph is not bipartite
                }
            }
        }
    }

    // Graph is bipartite
    return 1;
}

// Driver code to test the above functions
int main() {
    // Create a graph
    struct Graph* graph = createGraph(4, 4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the adjacency matrix
    printAdjacencyMatrix(graph);

    // Check if the graph is bipartite
    int is_bipartite = isBipartite(graph);

    // Print the result
    if (is_bipartite) {
        printf("The graph is bipartite\n");
    } else {
        printf("The graph is not bipartite\n");
    }

    return 0;
}