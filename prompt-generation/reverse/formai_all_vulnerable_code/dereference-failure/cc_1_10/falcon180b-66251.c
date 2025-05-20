//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    char name[20];
    int id;
    int num_edges;
    int *edges;
} Node;

typedef struct {
    int from_node_id;
    int to_node_id;
    int weight;
} Edge;

Node *nodes;
Edge *edges;
int num_nodes, num_edges;

void add_node(char *name, int id) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Too many nodes!\n");
        exit(1);
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->num_edges = 0;
    new_node->edges = NULL;
    nodes[num_nodes++] = *new_node;
}

void add_edge(int from_node_id, int to_node_id, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Too many edges!\n");
        exit(1);
    }
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->from_node_id = from_node_id;
    new_edge->to_node_id = to_node_id;
    new_edge->weight = weight;
    edges[num_edges++] = *new_edge;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges() {
    printf("Edges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].from_node_id, edges[i].to_node_id, edges[i].weight);
    }
}

int main() {
    num_nodes = 0;
    num_edges = 0;
    nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    add_node("A", 1);
    add_node("B", 2);
    add_node("C", 3);
    add_node("D", 4);
    add_edge(1, 2, 10);
    add_edge(1, 3, 20);
    add_edge(2, 3, 15);
    add_edge(3, 4, 25);
    print_nodes();
    print_edges();
    return 0;
}