//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_LINKS 10000
#define MAX_LINK_LENGTH 100

typedef struct node {
    char name[20];
    int id;
    struct node **links;
    int num_links;
} Node;

typedef struct link {
    Node *node1;
    Node *node2;
    int length;
} Link;

Node *create_node(char *name, int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = id;
    node->links = NULL;
    node->num_links = 0;
    return node;
}

void add_link(Node *node1, Node *node2, int length) {
    Link *link = (Link *)malloc(sizeof(Link));
    link->node1 = node1;
    link->node2 = node2;
    link->length = length;
    node1->links = (Node **)realloc(node1->links, sizeof(Node *) * (node1->num_links + 1));
    node1->links[node1->num_links] = node2;
    node1->num_links++;
}

void print_links(Node *node) {
    int i;
    for (i = 0; i < node->num_links; i++) {
        printf("%s - %s (%d)\n", node->name, node->links[i]->name, node->links[i]->id);
    }
}

int main() {
    int i;
    Node *nodes[MAX_NODES];
    int num_nodes = 0;

    // Create nodes
    nodes[num_nodes] = create_node("Node 1", 1);
    num_nodes++;
    nodes[num_nodes] = create_node("Node 2", 2);
    num_nodes++;
    nodes[num_nodes] = create_node("Node 3", 3);
    num_nodes++;

    // Add links
    add_link(nodes[0], nodes[1], 50);
    add_link(nodes[1], nodes[2], 100);
    add_link(nodes[0], nodes[2], 150);

    // Print network topology
    printf("Network Topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i]->id, nodes[i]->name);
        print_links(nodes[i]);
    }

    return 0;
}