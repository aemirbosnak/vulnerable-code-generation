//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Graph structure using linked lists
typedef struct node {
    int data; // data stored in each node
    struct node *next; // next node in the list
} Node;

// Function to create a new graph
Node* createGraph(int num_vertices) {
    Node* graph = NULL;
    for (int i = 0; i < num_vertices; i++) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = graph;
        graph = new_node;
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(Node** graph, int vertex1, int vertex2) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = vertex1;
    new_node->next = graph[vertex2];
    graph[vertex1] = new_node;
}

// Function to traverse the graph
void traverse(Node* graph) {
    while (graph != NULL) {
        printf("%d ", graph->data);
        graph = graph->next;
    }
    printf("\n");
}

int main() {
    Node* graph = createGraph(5);

    // Add edges to the graph
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    // Traverse the graph
    traverse(graph);

    return 0;
}