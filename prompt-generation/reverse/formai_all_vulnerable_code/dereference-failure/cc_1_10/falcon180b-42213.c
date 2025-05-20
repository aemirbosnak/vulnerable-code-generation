//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_LINKS 100
#define NODE_NAME_LENGTH 50
#define LINK_NAME_LENGTH 50

typedef struct node {
    char name[NODE_NAME_LENGTH];
    int id;
    int num_links;
    struct link *links[MAX_LINKS];
} Node;

typedef struct link {
    char name[LINK_NAME_LENGTH];
    Node *node1;
    Node *node2;
    int speed;
} Link;

int num_nodes = 0;
int num_links = 0;
Node *nodes[MAX_NODES];
Link *links[MAX_LINKS];

void add_node(char *name) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = num_nodes++;
    node->num_links = 0;
    nodes[num_nodes - 1] = node;
}

void add_link(char *name, Node *node1, Node *node2, int speed) {
    Link *link = malloc(sizeof(Link));
    strcpy(link->name, name);
    link->node1 = node1;
    link->node2 = node2;
    link->speed = speed;
    links[num_links++] = link;
    node1->num_links++;
    node2->num_links++;
}

void print_node(Node *node) {
    printf("Node %s (%d)\n", node->name, node->id);
    for (int i = 0; i < node->num_links; i++) {
        Link *link = node->links[i];
        printf("\tLink %s (%d -> %d)\n", link->name, link->node1->id, link->node2->id);
    }
}

void print_links() {
    for (int i = 0; i < num_links; i++) {
        Link *link = links[i];
        printf("Link %s (%d -> %d)\n", link->name, link->node1->id, link->node2->id);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_link("Link 1", nodes[0], nodes[1], 100);
    add_link("Link 2", nodes[1], nodes[2], 200);
    add_link("Link 3", nodes[0], nodes[2], 300);
    print_links();
    return 0;
}