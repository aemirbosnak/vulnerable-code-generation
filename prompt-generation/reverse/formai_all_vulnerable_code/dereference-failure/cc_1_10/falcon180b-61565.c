//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct node {
    char name[20];
    int id;
    struct node *links[MAX_LINKS];
    int num_links;
} Node;

Node *create_node(char *name, int id) {
    Node *node = (Node *) malloc(sizeof(Node));
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
    printf("Node %s (%d)\n", node->name, node->id);
    printf("Links: ");
    for (int i = 0; i < node->num_links; i++) {
        printf("%s ", node->links[i]->name);
    }
    printf("\n");
}

void print_network(Node *nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
    }
}

int main() {
    // Create nodes
    Node *node1 = create_node("Holmes", 1);
    Node *node2 = create_node("Watson", 2);
    Node *node3 = create_node("Lestrade", 3);
    Node *node4 = create_node("Irene", 4);

    // Connect nodes
    add_link(node1, node2);
    add_link(node1, node3);
    add_link(node2, node4);

    // Print network topology
    Node *nodes[] = {node1, node2, node3, node4};
    print_network(nodes, 4);

    return 0;
}