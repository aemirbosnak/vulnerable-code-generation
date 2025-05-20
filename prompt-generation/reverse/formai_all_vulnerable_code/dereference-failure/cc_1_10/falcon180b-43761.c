//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char name[20];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

Node nodes[MAX_NODES];

int num_nodes = 0;
int num_edges = 0;

void add_node(int id, char* name) {
    num_nodes++;
    nodes[num_nodes-1].id = id;
    strcpy(nodes[num_nodes-1].name, name);
    nodes[num_nodes-1].num_edges = 0;
}

void add_edge(int from_node_id, int to_node_id) {
    num_edges++;
    nodes[from_node_id-1].edges[nodes[from_node_id-1].num_edges++] = to_node_id;
}

void print_node(int id) {
    printf("Node %d: %s\n", id, nodes[id-1].name);
}

void print_edges(int id) {
    printf("Edges for Node %d:\n", id);
    for (int i=0; i<nodes[id-1].num_edges; i++) {
        printf(" -> Node %d\n", nodes[id-1].edges[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <node_name> <edge_target>\n", argv[0]);
        exit(1);
    }

    int id = atoi(argv[1]);
    char* name = argv[1];
    int target_id = atoi(argv[2]);

    add_node(id, name);
    add_edge(id, target_id);

    print_node(id);
    print_edges(id);

    return 0;
}