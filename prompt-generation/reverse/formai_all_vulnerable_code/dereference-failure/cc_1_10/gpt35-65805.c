//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Create the structure to represent graph
typedef struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **adj_matrix; // Adjacency matrix representation
} Graph;

// Function to initialize graph
Graph *initialize_graph(int V, int E) {
    Graph *graph = (Graph *) malloc(sizeof(Graph)); // Allocate memory for graph

    graph->V = V; // Set the number of vertices
    graph->E = E; // Set the number of edges

    // Allocate memory for adjacency matrix
    graph->adj_matrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj_matrix[i] = (int *) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj_matrix[i][j] = 0; // Initialize all values in matrix to 0
        }
    }

    return graph;
}

// Function to add edge to graph
void add_edge(Graph *graph, int src, int dest, int weight) {
    graph->adj_matrix[src][dest] = weight; // Set the weight of the edge
    graph->adj_matrix[dest][src] = weight; // Since graph is undirected, add edge in reverse direction too
}

// Function to display the graph
void display_graph(Graph *graph) {
    printf("Vertices: %d, Edges: %d\n", graph->V, graph->E);
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj_matrix[i][j]); // Display the adjacency matrix
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = initialize_graph(5, 7); // Create graph with 5 vertices and 7 edges
    add_edge(graph, 0, 1, 2); // Add edge between vertices 0 and 1 with weight 2
    add_edge(graph, 0, 3, 3); // Add edge between vertices 0 and 3 with weight 3
    add_edge(graph, 1, 2, 1); // Add edge between vertices 1 and 2 with weight 1
    add_edge(graph, 1, 3, 2); // Add edge between vertices 1 and 3 with weight 2
    add_edge(graph, 2, 3, 4); // Add edge between vertices 2 and 3 with weight 4
    add_edge(graph, 2, 4, 5); // Add edge between vertices 2 and 4 with weight 5
    add_edge(graph, 3, 4, 3); // Add edge between vertices 3 and 4 with weight 3

    display_graph(graph); // Display the graph
    return 0;
}