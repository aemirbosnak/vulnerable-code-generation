//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Graph structure: an array of nodes, where each node is a struct with a name and a list of neighbors
struct node {
    char *name;
    struct node *neighbors[10]; // 10 is just a random number, feel free to adjust
};

// Function to create a new node
struct node* new_node(char *name) {
    struct node *n = malloc(sizeof(struct node));
    n->name = name;
    n->neighbors[0] = NULL; // no neighbors yet, sorry!
    return n;
}

// Function to add a neighbor to a node
void add_neighbor(struct node *n, char *name) {
    struct node **pp;
    for (pp = &n->neighbors[0]; pp < &n->neighbors[10]; pp++) {
        if (*pp == NULL) {
            *pp = new_node(name);
            break;
        }
    }
}

// Function to print out the graph
void print_graph(struct node *n) {
    printf("Node: %s\n", n->name);
    for (int i = 0; i < 10; i++) {
        if (n->neighbors[i] != NULL) {
            printf("  Neighbor: %s\n", n->neighbors[i]->name);
        }
    }
}

// Function to create a new graph
struct node* create_graph() {
    struct node *n1 = new_node("Node 1");
    struct node *n2 = new_node("Node 2");
    struct node *n3 = new_node("Node 3");
    struct node *n4 = new_node("Node 4");

    // Add some edges
    add_neighbor(n1, "Node 2");
    add_neighbor(n2, "Node 1");
    add_neighbor(n2, "Node 3");
    add_neighbor(n3, "Node 1");
    add_neighbor(n3, "Node 4");
    add_neighbor(n4, "Node 2");

    return n1;
}

int main() {
    struct node* g = create_graph();
    print_graph(g);
    return 0;
}