//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

// Define the structure of the graph node
typedef struct node {
    int id;
    char name[20];
    int degree;
    struct node *edges[MAX_EDGES];
} Node;

// Define the structure of the graph
typedef struct graph {
    int num_nodes;
    Node *nodes[MAX_NODES];
} Graph;

// Function to create a new node
Node *create_node(int id, char *name) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->degree = 0;
    for (int i = 0; i < MAX_EDGES; i++) {
        new_node->edges[i] = NULL;
    }
    return new_node;
}

// Function to create a new edge between two nodes
void create_edge(Node *node1, Node *node2) {
    node1->edges[node1->degree++] = node2;
    node2->edges[node2->degree++] = node1;
}

// Function to print the graph
void print_graph(Graph *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *node = graph->nodes[i];
        printf("%d %s\n", node->id, node->name);
        for (int j = 0; j < node->degree; j++) {
            Node *neighbor = node->edges[j];
            printf("\t%d\n", neighbor->id);
        }
    }
}

// Main function to test the graph creation and printing
int main() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->num_nodes = 0;

    Node *node1 = create_node(1, "Node 1");
    Node *node2 = create_node(2, "Node 2");
    Node *node3 = create_node(3, "Node 3");
    Node *node4 = create_node(4, "Node 4");

    create_edge(node1, node2);
    create_edge(node2, node3);
    create_edge(node3, node4);
    create_edge(node4, node1);

    graph->nodes[graph->num_nodes++] = node1;
    graph->nodes[graph->num_nodes++] = node2;
    graph->nodes[graph->num_nodes++] = node3;
    graph->nodes[graph->num_nodes++] = node4;

    print_graph(graph);

    return 0;
}