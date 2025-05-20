//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// A structure to represent a graph
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int matrix[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to represent edges
};

// Function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
    graph->E++;
}

// Function to print the graph in a cheerful way
void printGraph(struct Graph* graph) {
    printf("Woohoo! Here's your graph! 🎉\n");
    printf("It has %d vertices and %d edges:\n", graph->V, graph->E);
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Main function where the magic happens
int main() {
    printf("Let's create a graph! 😀\n");
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    printf("Hope you like your graph! 😉");
    return 0;
}