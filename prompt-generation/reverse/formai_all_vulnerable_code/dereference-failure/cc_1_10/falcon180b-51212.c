//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    int num_links;
    int *links;
} Node;

typedef struct {
    int node1_id;
    int node2_id;
    int cost;
} Link;

Node nodes[MAX_NODES];
Link links[MAX_LINKS];
int num_nodes = 0;
int num_links = 0;

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].num_links = 0;
    nodes[num_nodes].links = NULL;
    num_nodes++;
}

void add_link(int node1_id, int node2_id, int cost) {
    if (num_links >= MAX_LINKS) {
        printf("Error: Maximum number of links reached.\n");
        exit(1);
    }
    Link *link = &links[num_links];
    link->node1_id = node1_id;
    link->node2_id = node2_id;
    link->cost = cost;
    nodes[node1_id].num_links++;
    nodes[node1_id].links = realloc(nodes[node1_id].links, sizeof(int) * nodes[node1_id].num_links);
    nodes[node1_id].links[nodes[node1_id].num_links - 1] = num_links;
    num_links++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", i, nodes[i].name);
    }
}

void print_links() {
    printf("\nLinks:\n");
    for (int i = 0; i < num_links; i++) {
        Link link = links[i];
        printf("%d -> %d, cost: %d\n", link.node1_id, link.node2_id, link.cost);
    }
}

int main() {
    add_node("London");
    add_node("Paris");
    add_node("Berlin");
    add_link(0, 1, 10);
    add_link(0, 2, 20);
    add_link(1, 2, 15);
    print_nodes();
    print_links();
    return 0;
}