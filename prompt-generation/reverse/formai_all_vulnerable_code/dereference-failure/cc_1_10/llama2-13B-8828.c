//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph node
struct Node {
    int label; // node label
    int degree; // node degree (number of edges incident on the node)
    struct Node *adjacent[10]; // array of adjacent nodes
};

// Function to create a new graph
struct Node* createGraph(int n) {
    struct Node* graph = malloc(n * sizeof(struct Node));
    for (int i = 0; i < n; i++) {
        graph[i].label = i + 1; // assign unique label to each node
        graph[i].degree = 0; // initialize degree to 0
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Node* graph, int u, int v) {
    graph[u].adjacent[graph[u].degree] = &graph[v];
    graph[v].degree++;
}

// Function to print the graph
void printGraph(struct Node* graph) {
    for (int i = 0; i < 10; i++) {
        printf("%d:", graph[i].label);
        for (int j = 0; j < graph[i].degree; j++) {
            printf(" %d", graph[i].adjacent[j]->label);
        }
        printf("\n");
    }
}

int main() {
    struct Node* graph = createGraph(10);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 8);
    addEdge(graph, 7, 9);
    addEdge(graph, 8, 9);

    printGraph(graph);

    return 0;
}