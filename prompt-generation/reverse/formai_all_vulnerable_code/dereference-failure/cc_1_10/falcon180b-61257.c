//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a node in the graph
typedef struct node {
    int data;
    bool visited;
    int num_edges;
    struct node **edges;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->visited = false;
    new_node->num_edges = 0;
    new_node->edges = NULL;
    return new_node;
}

// Function to add an edge between two nodes
void add_edge(Node *node1, Node *node2) {
    node1->num_edges++;
    node1->edges = (Node**) realloc(node1->edges, node1->num_edges * sizeof(Node*));
    node1->edges[node1->num_edges - 1] = node2;

    node2->num_edges++;
    node2->edges = (Node**) realloc(node2->edges, node2->num_edges * sizeof(Node*));
    node2->edges[node2->num_edges - 1] = node1;
}

// Function to print the graph in a readable format
void print_graph(Node *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("%d -> %d\n", graph->data, graph->edges[i]->data);
    }
}

// Function to perform a depth-first search on the graph starting at a given node
void dfs(Node *node) {
    node->visited = true;
    printf("%d ", node->data);

    for (int i = 0; i < node->num_edges; i++) {
        if (!node->edges[i]->visited) {
            dfs(node->edges[i]);
        }
    }
}

// Main function to create a graph and perform a depth-first search
int main() {
    Node *graph = create_node(1);
    add_edge(graph, create_node(2));
    add_edge(graph, create_node(3));
    add_edge(graph, create_node(4));
    add_edge(graph, create_node(5));

    print_graph(graph);

    dfs(graph);

    return 0;
}