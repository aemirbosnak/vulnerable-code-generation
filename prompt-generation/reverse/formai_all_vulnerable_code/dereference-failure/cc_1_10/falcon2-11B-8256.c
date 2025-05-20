//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NODE 100

// Graph Structure
typedef struct Graph {
    int size;
    int **adjacency_list;
} Graph;

// Function to print the adjacency list
void print_adjacency_list(Graph *graph) {
    int i, j;
    for (i = 0; i < graph->size; i++) {
        for (j = 0; j < graph->size; j++) {
            if (graph->adjacency_list[i][j]!= 0) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

// Function to create a new graph
Graph *create_graph(int size) {
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->size = size;
    graph->adjacency_list = (int**) malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        graph->adjacency_list[i] = (int*) malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            graph->adjacency_list[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int source, int destination) {
    graph->adjacency_list[source][destination] = 1;
}

// Function to remove an edge from the graph
void remove_edge(Graph *graph, int source, int destination) {
    graph->adjacency_list[source][destination] = 0;
}

// Function to check if there is an edge between two nodes
int has_edge(Graph *graph, int source, int destination) {
    return graph->adjacency_list[source][destination];
}

int main() {
    // Create a new graph with size 6
    Graph *graph = create_graph(6);
    
    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    
    // Print the adjacency list of the graph
    printf("Adjacency List:\n");
    print_adjacency_list(graph);
    
    return 0;
}