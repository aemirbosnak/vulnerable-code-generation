//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

// Define the structure of a node in the graph
typedef struct node {
    int id;
    char name[20];
    int degree;
    int *neighbors;
} Node;

// Function to create a new node with the given ID and name
Node* create_node(int id, char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->degree = 0;
    new_node->neighbors = NULL;
    return new_node;
}

// Function to add an edge between two nodes
void add_edge(Node* node1, Node* node2) {
    node1->degree++;
    node2->degree++;
    int* neighbor_list = realloc(node1->neighbors, sizeof(int) * node1->degree);
    neighbor_list[node1->degree-1] = node2->id;
    node1->neighbors = neighbor_list;
    neighbor_list = realloc(node2->neighbors, sizeof(int) * node2->degree);
    neighbor_list[node2->degree-1] = node1->id;
    node2->neighbors = neighbor_list;
}

// Function to print the details of a node
void print_node(Node* node) {
    printf("ID: %d, Name: %s, Degree: %d\n", node->id, node->name, node->degree);
    printf("Neighbors: ");
    for(int i=0; i<node->degree; i++) {
        printf("%d ", node->neighbors[i]);
    }
    printf("\n");
}

// Function to print the entire graph
void print_graph(Node* nodes, int num_nodes) {
    for(int i=0; i<num_nodes; i++) {
        print_node(nodes+i);
    }
}

int main() {

    // Create 5 nodes
    Node* nodes[5];
    nodes[0] = create_node(1, "Node 1");
    nodes[1] = create_node(2, "Node 2");
    nodes[2] = create_node(3, "Node 3");
    nodes[3] = create_node(4, "Node 4");
    nodes[4] = create_node(5, "Node 5");

    // Add edges between nodes
    add_edge(nodes[0], nodes[1]);
    add_edge(nodes[1], nodes[2]);
    add_edge(nodes[2], nodes[3]);
    add_edge(nodes[3], nodes[4]);

    // Print the graph
    print_graph(nodes, 5);

    return 0;
}