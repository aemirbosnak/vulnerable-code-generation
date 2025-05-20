//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

typedef struct node {
    int id;
    char name[50];
    int degree;
    struct node **adj;
} Node;

typedef struct edge {
    int weight;
    Node *to;
} Edge;

Node *nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = num_nodes++;
    new_node->degree = 0;
    new_node->adj = (Node **)malloc(sizeof(Node *));
    nodes[num_nodes - 1] = new_node;
}

Node *get_node(char *name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i]->name, name) == 0) {
            return nodes[i];
        }
    }
    return NULL;
}

void add_edge(int from_id, int to_id, int weight) {
    Node *from_node = get_node(nodes[from_id]->name);
    Node *to_node = get_node(nodes[to_id]->name);
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->weight = weight;
    new_edge->to = to_node;
    from_node->adj[from_node->degree++] = to_node;
    to_node->degree++;
}

void print_graph() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("%s (%d): ", nodes[i]->name, nodes[i]->id);
        for (j = 0; j < nodes[i]->degree; j++) {
            printf("%s (%d) ", nodes[i]->adj[j]->name, nodes[i]->adj[j]->id);
        }
        printf("\n");
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_edge(0, 1, 2);
    add_edge(1, 2, 3);
    add_edge(2, 0, 4);
    add_edge(2, 3, 5);
    print_graph();
    return 0;
}