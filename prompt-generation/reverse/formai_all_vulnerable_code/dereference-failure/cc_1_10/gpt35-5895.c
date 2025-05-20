//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to add edge between two nodes in the graph
void addEdge(int** graph, int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight;
}

// Function to print the graph
void printGraph(int** graph, int V) {
    printf("The graph is:\n");

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hey! Let's create a graph representation in C!\n");

    int V; // Number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    // Dynamically allocate memory for graph
    int **graph = (int **) malloc(V * sizeof(int *));
    for(int i = 0; i < V; i++) {
        graph[i] = (int *) malloc(V * sizeof(int));
    }

    // Initialize the graph with 0s
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    int E; // Number of edges
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    int u, v, weight;
    for(int i = 0; i < E; i++) {
        printf("Enter the vertices and weight of edge %d: ", i+1);
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u-1, v-1, weight);
    }

    // Print the graph
    printGraph(graph, V);

    // Free the dynamically allocated memory
    for(int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    printf("Yay! We successfully created a graph representation in C!\n");

    return 0;
}