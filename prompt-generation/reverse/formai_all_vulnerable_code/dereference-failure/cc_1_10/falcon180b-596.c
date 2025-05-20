//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the graph structure
typedef struct graph {
    int num_nodes;
    Node** nodes;
} Graph;

// Initialize a new graph with the given number of nodes
Graph* graph_init(int num_nodes) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (Node**) malloc(sizeof(Node*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

// Add a new node to the graph
void graph_add_node(Graph* graph, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    int num_nodes = graph->num_nodes;
    graph->nodes[num_nodes] = node;
    graph->num_nodes++;
}

// Connect two nodes in the graph
void graph_connect_nodes(Graph* graph, int node1, int node2) {
    Node* current = graph->nodes[node1];
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = graph->nodes[node2];
}

// Print the graph
void graph_print(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node* current = graph->nodes[i];
        printf("Node %d: ", i);
        while (current!= NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Free the memory used by the graph
void graph_free(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node* current = graph->nodes[i];
        while (current!= NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    Graph* graph = graph_init(5);
    graph_add_node(graph, 1);
    graph_add_node(graph, 2);
    graph_add_node(graph, 3);
    graph_add_node(graph, 4);
    graph_add_node(graph, 5);
    graph_connect_nodes(graph, 1, 2);
    graph_connect_nodes(graph, 2, 3);
    graph_connect_nodes(graph, 3, 4);
    graph_connect_nodes(graph, 4, 5);
    graph_print(graph);
    graph_free(graph);
    return 0;
}