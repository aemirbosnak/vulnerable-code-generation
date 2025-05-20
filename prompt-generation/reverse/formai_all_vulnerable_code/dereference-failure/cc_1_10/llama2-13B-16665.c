//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Graph structure using linked lists
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a graph
Node* createGraph(int num_vertices) {
    Node* graph = malloc(num_vertices * sizeof(Node));
    for (int i = 0; i < num_vertices; i++) {
        graph[i].data = i + 1;
        graph[i].next = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Node** graph, int v1, int v2) {
    Node* node1 = graph[v1];
    Node* node2 = graph[v2];
    Node* new_node = malloc(sizeof(Node));
    new_node->data = v1 + v2;
    new_node->next = NULL;
    node1->next = new_node;
    node2->next = new_node;
}

// Function to traverse the graph
void traverse(Node* graph) {
    if (graph == NULL) {
        return;
    }
    printf("%d -> ", graph->data);
    traverse(graph->next);
}

int main() {
    srand(time(NULL));
    int num_vertices = 10;
    Node* graph = createGraph(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            addEdge(&graph, i, j);
        }
    }
    traverse(graph);
    return 0;
}