//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Data structures
typedef struct Node {
    int id;
    char *name;
    struct Node *next;
} Node;

typedef struct Graph {
    int num_nodes;
    Node *nodes;
} Graph;

// Function prototypes
Graph *create_graph();
void add_node(Graph *graph, int id, char *name);
void connect_nodes(Graph *graph, int id1, int id2);
void print_graph(Graph *graph);
void destroy_graph(Graph *graph);

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph();

    // Add nodes to the graph
    add_node(graph, 1, "Node 1");
    add_node(graph, 2, "Node 2");
    add_node(graph, 3, "Node 3");
    add_node(graph, 4, "Node 4");
    add_node(graph, 5, "Node 5");

    // Connect the nodes in the graph
    connect_nodes(graph, 1, 2);
    connect_nodes(graph, 1, 3);
    connect_nodes(graph, 2, 4);
    connect_nodes(graph, 3, 4);
    connect_nodes(graph, 4, 5);

    // Print the graph
    print_graph(graph);

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}

// Function definitions
Graph *create_graph() {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->nodes = NULL;
    return graph;
}

void add_node(Graph *graph, int id, char *name) {
    Node *node = malloc(sizeof(Node));
    node->id = id;
    node->name = strdup(name);
    node->next = NULL;
    if (graph->num_nodes == 0) {
        graph->nodes = node;
    } else {
        Node *last_node = graph->nodes;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = node;
    }
    graph->num_nodes++;
}

void connect_nodes(Graph *graph, int id1, int id2) {
    Node *node1 = graph->nodes;
    while (node1 != NULL && node1->id != id1) {
        node1 = node1->next;
    }
    if (node1 == NULL) {
        printf("Node %d not found in graph.\n", id1);
        return;
    }
    Node *node2 = graph->nodes;
    while (node2 != NULL && node2->id != id2) {
        node2 = node2->next;
    }
    if (node2 == NULL) {
        printf("Node %d not found in graph.\n", id2);
        return;
    }
    // Check if the nodes are already connected
    Node *temp = node1->next;
    while (temp != NULL && temp->id != id2) {
        temp = temp->next;
    }
    if (temp != NULL) {
        printf("Nodes %d and %d are already connected.\n", id1, id2);
        return;
    }
    // Connect the nodes
    Node *new_node = malloc(sizeof(Node));
    new_node->id = id2;
    new_node->name = strdup(node2->name);
    new_node->next = NULL;
    node1->next = new_node;
}

void print_graph(Graph *graph) {
    Node *node = graph->nodes;
    while (node != NULL) {
        printf("Node %d: %s\n", node->id, node->name);
        Node *neighbor = node->next;
        while (neighbor != NULL) {
            printf("  - %s\n", neighbor->name);
            neighbor = neighbor->next;
        }
        node = node->next;
    }
}

void destroy_graph(Graph *graph) {
    Node *node = graph->nodes;
    while (node != NULL) {
        Node *next_node = node->next;
        free(node->name);
        free(node);
        node = next_node;
    }
    free(graph);
}