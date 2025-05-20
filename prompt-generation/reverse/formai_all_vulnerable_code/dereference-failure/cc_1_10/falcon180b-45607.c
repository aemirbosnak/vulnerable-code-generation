//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 200
#define MAX_LINK_LENGTH 20

typedef struct node {
    char name[MAX_LINK_LENGTH];
    int id;
    struct node* links[MAX_LINKS];
    int num_links;
} Node;

Node* create_node(char* name, int id) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->num_links = 0;
    for (int i = 0; i < MAX_LINKS; i++) {
        new_node->links[i] = NULL;
    }
    return new_node;
}

void add_link(Node* node1, Node* node2) {
    node1->links[node1->num_links++] = node2;
    node2->links[node2->num_links++] = node1;
}

void print_node(Node* node) {
    printf("Node Name: %s\n", node->name);
    printf("Node ID: %d\n", node->id);
    printf("Number of Links: %d\n", node->num_links);
    for (int i = 0; i < node->num_links; i++) {
        printf("Link %d: ", i+1);
        print_node(node->links[i]);
    }
}

int main() {
    Node* node1 = create_node("Node 1", 1);
    Node* node2 = create_node("Node 2", 2);
    Node* node3 = create_node("Node 3", 3);

    add_link(node1, node2);
    add_link(node1, node3);
    add_link(node2, node3);

    print_node(node1);

    return 0;
}