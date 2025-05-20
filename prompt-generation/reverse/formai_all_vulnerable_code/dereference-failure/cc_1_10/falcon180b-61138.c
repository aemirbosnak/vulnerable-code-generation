//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct {
    int id;
    char name[20];
    int num_links;
    struct Link *links[MAX_LINKS];
} Node;

typedef struct {
    Node *node1;
    Node *node2;
    int weight;
} Link;

int num_nodes = 0;
Node *nodes[MAX_NODES];

int add_node(char *name) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = num_nodes++;
    node->num_links = 0;
    memset(node->links, 0, sizeof(node->links));
    nodes[num_nodes - 1] = node;
    return num_nodes - 1;
}

int add_link(int id1, int id2, int weight) {
    Node *node1 = nodes[id1];
    Node *node2 = nodes[id2];
    Link *link = malloc(sizeof(Link));
    link->node1 = node1;
    link->node2 = node2;
    link->weight = weight;
    node1->num_links++;
    node1->links[node1->num_links - 1] = link;
    node2->num_links++;
    node2->links[node2->num_links - 1] = link;
    return 0;
}

void print_node(Node *node) {
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
    printf("Links:\n");
    for (int i = 0; i < node->num_links; i++) {
        Link *link = node->links[i];
        printf("ID: %d\n", link->node2->id);
        printf("Weight: %d\n", link->weight);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");

    add_link(0, 1, 10);
    add_link(1, 2, 20);

    print_node(nodes[0]);
    print_node(nodes[1]);
    print_node(nodes[2]);

    return 0;
}