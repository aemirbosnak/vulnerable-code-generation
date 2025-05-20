//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct node {
    char name[20];
    int id;
    int degree;
    struct node *edges[MAX_EDGES];
} Node;

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

Node *create_node(char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = 0;
    node->degree = 0;
    memset(node->edges, 0, sizeof(node->edges));
    return node;
}

void add_edge(Node *node1, Node *node2, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->start = node1->id;
    edge->end = node2->id;
    edge->weight = weight;
    node1->edges[node1->degree++] = node2;
    node2->edges[node2->degree++] = node1;
}

void print_graph(Node *node) {
    printf("Node: %s\n", node->name);
    printf("ID: %d\n", node->id);
    printf("Degree: %d\n", node->degree);
    printf("Edges:\n");
    for (int i = 0; i < node->degree; i++) {
        printf("  %s\n", node->edges[i]->name);
    }
}

int main() {
    Node *node1 = create_node("Node 1");
    Node *node2 = create_node("Node 2");
    Node *node3 = create_node("Node 3");
    Node *node4 = create_node("Node 4");

    add_edge(node1, node2, 5);
    add_edge(node2, node3, 3);
    add_edge(node3, node4, 2);

    print_graph(node1);
    print_graph(node2);
    print_graph(node3);
    print_graph(node4);

    return 0;
}