//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int num_edges;
    int *edges;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;
int num_edges = 0;

void add_node(int id, char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: maximum number of nodes reached.\n");
        exit(1);
    }
    nodes[num_nodes].id = id;
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_edges = 0;
    nodes[num_nodes].edges = NULL;
    num_nodes++;
}

void add_edge(int from_id, int to_id) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: maximum number of edges reached.\n");
        exit(1);
    }
    int from_index = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].id == from_id) {
            from_index = i;
            break;
        }
    }
    if (from_index == -1) {
        printf("Error: node with ID %d not found.\n", from_id);
        exit(1);
    }
    int to_index = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].id == to_id) {
            to_index = i;
            break;
        }
    }
    if (to_index == -1) {
        printf("Error: node with ID %d not found.\n", to_id);
        exit(1);
    }
    nodes[from_index].num_edges++;
    nodes[from_index].edges = (int *)realloc(nodes[from_index].edges, sizeof(int) * nodes[from_index].num_edges);
    nodes[from_index].edges[nodes[from_index].num_edges - 1] = to_index;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s (%d edges)\n", nodes[i].id, nodes[i].name, nodes[i].num_edges);
    }
}

void print_edges() {
    printf("\nEdges:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].num_edges; j++) {
            printf("%d ", nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    add_node(1, "Node 1");
    add_node(2, "Node 2");
    add_node(3, "Node 3");
    add_edge(1, 2);
    add_edge(2, 3);
    print_nodes();
    print_edges();
    return 0;
}