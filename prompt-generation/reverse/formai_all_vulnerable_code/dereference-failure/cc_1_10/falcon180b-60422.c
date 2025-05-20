//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 100

struct node {
    char name[20];
    int id;
    int degree;
    struct node *links[MAX_LINKS];
};

struct node *create_node(char *name, int id) {
    struct node *node = malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->id = id;
    node->degree = 0;
    return node;
}

void add_link(struct node *node1, struct node *node2) {
    node1->links[node1->degree++] = node2;
    node2->degree++;
}

void print_node(struct node *node) {
    printf("%s (%d)\n", node->name, node->id);
}

void print_links(struct node *node) {
    int i;
    for (i = 0; i < node->degree; i++) {
        print_node(node->links[i]);
    }
}

int main() {
    struct node *node1 = create_node("Node 1", 1);
    struct node *node2 = create_node("Node 2", 2);
    struct node *node3 = create_node("Node 3", 3);
    struct node *node4 = create_node("Node 4", 4);

    add_link(node1, node2);
    add_link(node1, node3);
    add_link(node2, node4);

    printf("Network Topology:\n");
    print_node(node1);
    print_links(node1);
    printf("\n");

    return 0;
}