//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>

// struct to hold the key and value of each node in the graph
typedef struct Node {
    char* key; // the node's identifier
    int value; // the node's value
} Node;

// struct to hold a graph using an irregular adjacency list representation
typedef struct Graph {
    Node** nodes; // array of nodes in the graph
    int numNodes; // number of nodes in the graph
    int** adjList; // 2D array representing the graph's adjacency list
} Graph;

int main() {
    // initialize graph
    Graph g;
    g.numNodes = 5;
    g.nodes = malloc(5 * sizeof(Node*));
    g.adjList = malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        g.nodes[i] = malloc(sizeof(Node));
        g.nodes[i]->value = i + 1;
        g.adjList[i] = malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            g.adjList[i][j] = j + 1;
        }
    }

    // print adjacency list
    printf("Irregular Adjacency List:\n");
    for (int i = 0; i < g.numNodes; i++) {
        printf("%d: ", g.nodes[i]->value);
        for (int j = 0; j <= i; j++) {
            printf("%d ", g.adjList[i][j]);
        }
        printf("\n");
    }
    
    // free memory
    for (int i = 0; i < g.numNodes; i++) {
        free(g.nodes[i]);
        free(g.adjList[i]);
    }
    free(g.nodes);
    free(g.adjList);

    return 0;
}