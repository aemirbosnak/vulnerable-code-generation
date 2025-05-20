//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct {
    char name[20];
    int id;
    int degree;
    int *links;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].links = (int *)malloc(MAX_LINKS * sizeof(int));
    num_nodes++;
}

void add_link(int from, int to) {
    nodes[from].degree++;
    nodes[to].degree++;
    int *links = nodes[from].links;
    for (int i = 0; i < nodes[from].degree; i++) {
        if (links[i] == to) {
            return;
        }
    }
    links[nodes[from].degree] = to;
    nodes[to].degree++;
}

void print_node(int node_id) {
    printf("Node %d: %s\n", node_id, nodes[node_id].name);
    printf("Degree: %d\n", nodes[node_id].degree);
    for (int i = 0; i < nodes[node_id].degree; i++) {
        printf("Link %d: %d\n", i, nodes[node_id].links[i]);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_link(0, 1);
    add_link(1, 0);
    print_node(0);
    print_node(1);
    return 0;
}