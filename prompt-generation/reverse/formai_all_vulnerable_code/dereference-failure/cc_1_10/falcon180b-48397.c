//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

typedef struct {
    int dest;
    int weight;
} Edge;

typedef struct {
    char name[20];
    int num;
} Node;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0, num_edges = 0;

void add_node(char* name) {
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num = num_nodes;
    num_nodes++;
}

int find_node(char* name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_edge(int src, int dest, int weight) {
    edges[num_edges].dest = dest;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s ", nodes[i].name);
    }
    printf("\n");

    for (int i = 0; i < num_edges; i++) {
        int src = find_node(edges[i].dest);
        int dest = find_node(edges[i].dest);
        printf("%s -- %s (%d)\n", nodes[src].name, nodes[dest].name, edges[i].weight);
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");

    add_edge(0, 1, 5);
    add_edge(0, 2, 3);
    add_edge(1, 3, 7);
    add_edge(2, 3, 2);
    add_edge(2, 4, 4);

    print_graph();

    return 0;
}