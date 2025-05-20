//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Structure to represent a node in the graph
struct node {
    int id;
    char name[50];
    struct node *next;
};

// Structure to represent an edge in the graph
struct edge {
    int from;
    int to;
    struct edge *next;
};

// Function to create a new node
struct node *new_node(int id, char *name) {
    struct node *node = malloc(sizeof(struct node));
    node->id = id;
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

// Function to create a new edge
struct edge *new_edge(int from, int to) {
    struct edge *edge = malloc(sizeof(struct edge));
    edge->from = from;
    edge->to = to;
    edge->next = NULL;
    return edge;
}

// Function to print the graph
void print_graph(struct node *root) {
    printf("Graph:\n");
    struct node *current = root;
    while (current != NULL) {
        printf("Node %d: %s\n", current->id, current->name);
        struct edge *edge = current->next;
        while (edge != NULL) {
            printf("Edge %d -> %d\n", edge->from, edge->to);
            edge = edge->next;
        }
        current = current->next;
    }
}

// Function to traverse the graph
void traverse(struct node *root) {
    struct node *current = root;
    struct edge *edge;

    // Traverse the nodes
    while (current != NULL) {
        printf("Node %d: %s\n", current->id, current->name);
        current = current->next;
    }

    // Traverse the edges
    edge = root->next;
    while (edge != NULL) {
        traverse(edge->to);
        edge = edge->next;
    }
}

int main() {
    // Create a new node and an edge
    struct node *node1 = new_node(1, "Node 1");
    struct node *node2 = new_node(2, "Node 2");
    struct edge *edge1 = new_edge(1, 2);

    // Add the edge to the graph
    node1->next = edge1;
    edge1->from = 1;
    edge1->to = 2;

    // Create a new node and an edge
    struct node *node3 = new_node(3, "Node 3");
    struct node *node4 = new_node(4, "Node 4");
    struct edge *edge2 = new_edge(3, 4);

    // Add the edge to the graph
    node3->next = edge2;
    edge2->from = 3;
    edge2->to = 4;

    // Create a new node and an edge
    struct node *node5 = new_node(5, "Node 5");
    struct node *node6 = new_node(6, "Node 6");
    struct edge *edge3 = new_edge(5, 6);

    // Add the edge to the graph
    node5->next = edge3;
    edge3->from = 5;
    edge3->to = 6;

    // Print the graph
    print_graph(node1);

    // Traverse the graph
    traverse(node1);

    return 0;
}