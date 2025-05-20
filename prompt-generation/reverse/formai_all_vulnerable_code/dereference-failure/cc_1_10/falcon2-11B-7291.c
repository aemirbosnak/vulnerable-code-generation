//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj_list;
};

// Function to add a node to the graph
void add_node(struct Graph* graph, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    graph->adj_list[graph->V] = new_node;
    graph->V++;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int u, int v) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = v;
    new_node->next = graph->adj_list[u];
    graph->adj_list[u] = new_node;
}

int main() {
    // Initialize graph
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = 0;
    graph->adj_list = (struct Node**)malloc(graph->V * sizeof(struct Node*));
    
    // Add nodes to the graph
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);
    
    // Add edges to the graph
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 5);
    
    // Print the adjacency list
    struct Node* current = graph->adj_list[1];
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}