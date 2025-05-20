//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numNodes;         // Number of nodes
    int **adjMatrix;      // Adjacency matrix
};

// Function to create a graph with the given number of nodes
struct Graph *createGraph(int nodes) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numNodes = nodes;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int **)malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        graph->adjMatrix[i] = (int *)malloc(nodes * sizeof(int));
        for (int j = 0; j < nodes; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize all connections to 0
        }
    }
    return graph;
}

// Function to add an edge between two nodes in the graph
void addEdge(struct Graph *graph, int from, int to) {
    graph->adjMatrix[from][to] = 1; // Mark the edge
    graph->adjMatrix[to][from] = 1; // Undirected graph connection
}

// Function to perform DFS and print the topology
void dfsPrintTopology(struct Graph *graph, int node, int *visited) {
    visited[node] = 1; // Mark the node as visited
    printf("Node %d --> ", node); // Print current node

    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjMatrix[node][i] == 1 && !visited[i]) {
            printf("%d ", i); // Print connected nodes
            dfsPrintTopology(graph, i, visited); // Recursive call
        }
    }
    printf("\n");
}

// Function to print the entire network topology
void printNetworkTopology(struct Graph *graph) {
    printf("Network Topology:\n");
    int *visited = (int *)malloc(graph->numNodes * sizeof(int));

    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0; // Initialize visited array
    }
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            dfsPrintTopology(graph, i, visited);
        }
    }

    free(visited); // Clean up
}

// Main function to execute the program
int main() {
    int nodes, edges;
    printf("Welcome to the Network Topology Mapper!\n");
    printf("Please enter the number of nodes in the network: ");
    scanf("%d", &nodes);
    
    struct Graph *graph = createGraph(nodes);

    printf("Now, you will define the edges.\n");
    printf("How many edges are there in the network? ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int from, to;
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);
        addEdge(graph, from, to);
    }

    printNetworkTopology(graph);

    // Free allocated memory
    for (int i = 0; i < nodes; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
    
    printf("Network mapping complete! Thank you for using the Network Topology Mapper.\n");
    return 0;
}