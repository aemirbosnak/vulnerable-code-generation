//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct Node {
    int label; // Node label
    struct Node *next; // Next node in the graph
} Node;

// Graph functions
void initGraph(Node **graph, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (i != j) {
                Node *new_node = malloc(sizeof(Node));
                new_node->label = i * j;
                new_node->next = graph[i];
                graph[i] = new_node;
                graph[j] = new_node;
            }
        }
    }
}

void printGraph(Node *graph) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d -> ", graph[i].label);
        if (graph[i].next != NULL) {
            printGraph(graph[i].next);
        }
        printf("\n");
    }
}

int main() {
    Node *graph;
    int n = 10;

    // Initialize the graph
    initGraph(&graph, n);

    // Print the graph
    printGraph(graph);

    return 0;
}