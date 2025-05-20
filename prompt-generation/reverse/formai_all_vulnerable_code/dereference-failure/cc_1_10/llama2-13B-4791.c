//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure: an array of nodes, each with a name and a list of neighbors
typedef struct node {
    char *name;
    struct node *neighbors[10]; // 10 slots for neighbors, because who needs more than that?
} node_t;

// Function to create a new node with a random name
node_t *create_node(void) {
    node_t *n = malloc(sizeof(node_t));
    n->name = malloc(sizeof(char) * 20);
    int i = rand() % 20; // random name length, because why not?
    for (int j = 0; j < i; j++) {
        n->name[j] = 'a' + (rand() % 26); // random name characters, duh
    }
    n->name[i] = '\0';
    return n;
}

// Function to add a node to the graph
void add_node(node_t **graph, node_t *node) {
    int i = rand() % 10; // random slot in the array, because why not?
    graph[i] = node;
}

// Function to add an edge between two nodes
void add_edge(node_t **graph, node_t *node1, node_t *node2) {
    int i = rand() % 2; // random choice of neighbor, because why not?
    if (i == 0) {
        node1->neighbors[0] = node2;
    } else {
        node2->neighbors[0] = node1;
    }
}

// Function to print the graph
void print_graph(node_t **graph) {
    for (int i = 0; i < 10; i++) {
        printf("%s -> ", graph[i]->name);
        for (int j = 0; j < 10; j++) {
            if (graph[i]->neighbors[j] != NULL) {
                printf("%s ", graph[i]->neighbors[j]->name);
            }
        }
        printf("\n");
    }
}

int main(void) {
    node_t **graph = malloc(sizeof(node_t *) * 10);
    for (int i = 0; i < 10; i++) {
        node_t *node = create_node();
        add_node(graph, node);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            add_edge(graph, graph[i], graph[j]);
        }
    }
    print_graph(graph);
    return 0;
}