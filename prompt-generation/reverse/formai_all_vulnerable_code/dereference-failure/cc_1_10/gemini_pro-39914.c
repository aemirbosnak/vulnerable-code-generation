//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Self-referencing struct to represent a node in the graph
struct Node {
    int data;                // Data stored in the node
    struct Node *next;       // Pointer to the next node in the adjacency list
    struct Node *prev;       // Pointer to the previous node in the adjacency list
};

// Self-referencing struct to represent the graph
struct Graph {
    int num_nodes;          // Number of nodes in the graph
    struct Node **nodes;     // Array of pointers to the nodes in the graph
};

// Function to create a new node with the given data
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to create a new graph with the given number of nodes
struct Graph* create_graph(int num_nodes) {
    struct Graph *new_graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (new_graph == NULL) {
        perror("Error allocating memory for new graph");
        exit(EXIT_FAILURE);
    }
    new_graph->num_nodes = num_nodes;
    new_graph->nodes = (struct Node**)malloc(sizeof(struct Node*) * num_nodes);
    if (new_graph->nodes == NULL) {
        perror("Error allocating memory for nodes array");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_nodes; i++) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}

// Function to add an edge between two nodes in the graph
void add_edge(struct Graph *graph, int node1, int node2) {
    // Check if the nodes are valid
    if (node1 < 0 || node1 >= graph->num_nodes || node2 < 0 || node2 >= graph->num_nodes) {
        fprintf(stderr, "Error: Invalid node indices\n");
        return;
    }

    // Create the new nodes if they don't exist
    if (graph->nodes[node1] == NULL) {
        graph->nodes[node1] = create_node(node1);
    }
    if (graph->nodes[node2] == NULL) {
        graph->nodes[node2] = create_node(node2);
    }

    // Add the edge to the adjacency list of node1
    struct Node *new_node = create_node(node2);
    new_node->next = graph->nodes[node1]->next;
    graph->nodes[node1]->next = new_node;

    // Add the edge to the adjacency list of node2
    new_node = create_node(node1);
    new_node->next = graph->nodes[node2]->next;
    graph->nodes[node2]->next = new_node;
}

// Function to print the graph
void print_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct Node *current_node = graph->nodes[i];
        printf("Node %d: ", i);
        while (current_node != NULL) {
            printf("%d -> ", current_node->data);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

// Function to free the memory allocated for the graph
void free_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct Node *current_node = graph->nodes[i];
        while (current_node != NULL) {
            struct Node *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    // Create a new graph with 5 nodes
    struct Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}