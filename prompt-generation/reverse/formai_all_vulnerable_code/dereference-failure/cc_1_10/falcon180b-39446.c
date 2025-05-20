//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct node {
    char *name;
    int id;
    int num_neighbors;
    int *neighbors;
} Node;

typedef struct link {
    int from_node_id;
    int to_node_id;
} Link;

Node nodes[MAX_NODES];
Link links[MAX_LINKS];

int num_nodes = 0;
int num_links = 0;

void add_node(char *name) {
    Node *node = &nodes[num_nodes];
    node->name = strdup(name);
    node->id = num_nodes;
    node->num_neighbors = 0;
    node->neighbors = NULL;
    num_nodes++;
}

void add_link(int from_node_id, int to_node_id) {
    Link *link = &links[num_links];
    link->from_node_id = from_node_id;
    link->to_node_id = to_node_id;
    num_links++;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_links() {
    for (int i = 0; i < num_links; i++) {
        printf("Link %d: %d -> %d\n", i, links[i].from_node_id, links[i].to_node_id);
    }
}

void free_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        free(nodes[i].name);
        free(nodes[i].neighbors);
    }
    free(nodes);
}

void free_links() {
    free(links);
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_node("Node 4");
    add_node("Node 5");

    add_link(0, 1);
    add_link(0, 2);
    add_link(1, 2);
    add_link(2, 3);
    add_link(3, 4);

    print_nodes();
    print_links();

    free_nodes();
    free_links();

    return 0;
}