//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct node {
    char name[50];
    int id;
    struct node *links[MAX_LINKS];
    int num_links;
} Node;

Node *create_node(char *name, int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = id;
    node->num_links = 0;
    return node;
}

void add_link(Node *node1, Node *node2) {
    node1->links[node1->num_links++] = node2;
    node2->links[node2->num_links++] = node1;
}

void print_node(Node *node) {
    printf("Node %d: %s\n", node->id, node->name);
    printf("Links:\n");
    for (int i = 0; i < node->num_links; i++) {
        printf("  %d (%s)\n", node->links[i]->id, node->links[i]->name);
    }
}

void print_network(Node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        print_node(nodes + i);
    }
}

int main() {
    // Example network topology
    Node *nodes[5];
    nodes[0] = create_node("Node A", 1);
    nodes[1] = create_node("Node B", 2);
    nodes[2] = create_node("Node C", 3);
    nodes[3] = create_node("Node D", 4);
    nodes[4] = create_node("Node E", 5);

    add_link(nodes[0], nodes[1]);
    add_link(nodes[0], nodes[2]);
    add_link(nodes[1], nodes[3]);
    add_link(nodes[2], nodes[3]);
    add_link(nodes[2], nodes[4]);

    print_network(nodes, 5);

    return 0;
}