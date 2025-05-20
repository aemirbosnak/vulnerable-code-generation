//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A node in the graph
struct Node {
    int vertex;
    struct Node* next;
};

// A graph is represented as a linked list of nodes
struct Graph {
    struct Node* head;
};

// Function to create a new node
struct Node* create_node(int vertex) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
struct Graph* create_graph() {
    struct Graph* new_graph = (struct Graph*)malloc(sizeof(struct Graph));
    new_graph->head = NULL;
    return new_graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int source, int target) {
    struct Node* new_node = create_node(target);
    new_node->next = graph->head;
    graph->head = new_node;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    struct Node* node = graph->head;
    while (node!= NULL) {
        printf("%d ", node->vertex);
        node = node->next;
    }
    printf("\n");
}

// Function to check if a graph is connected
bool is_connected(struct Graph* graph) {
    struct Node* node = graph->head;
    while (node!= NULL) {
        if (node->next == NULL) {
            return false;
        }
        node = node->next;
    }
    return true;
}

int main() {
    struct Graph* graph = create_graph();
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    printf("Graph:\n");
    print_graph(graph);
    printf("\nIs connected: %s\n", is_connected(graph)? "yes" : "no");
    return 0;
}