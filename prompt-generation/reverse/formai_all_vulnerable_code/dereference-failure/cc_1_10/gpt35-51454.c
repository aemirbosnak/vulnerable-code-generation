//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int vertices; // number of vertices in the graph
    int** matrix; // 2D matrix representation of the graph
};

// function to create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = n;

    // allocate memory for the 2D matrix
    graph->matrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        graph->matrix[i] = (int*)malloc(n * sizeof(int)); // allocate memory for each row
        for (int j = 0; j < n; j++) {
            graph->matrix[i][j] = 0; // initialize all values to 0
        }
    }

    return graph;
}

// function to add an edge to the graph between vertices src and dest
void addEdge(struct Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1; // if graph is undirected
}

// function to print the graph
void printGraph(struct Graph* graph) {
    printf("Graph:\n");

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    struct Graph* graph = createGraph(5);

    // add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // print the graph
    printGraph(graph);

    return 0;
}