//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

struct node {
    int id;
    char name[50];
    int num_links;
    struct node* next;
};

struct node* create_node(int id, char* name, int num_links) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->num_links = num_links;
    new_node->next = NULL;
    return new_node;
}

void print_node(struct node* node) {
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
    printf("Num links: %d\n", node->num_links);
    printf("\n");
}

void print_links(struct node* node) {
    struct node* link;
    for (link = node->next; link!= NULL; link = link->next) {
        printf("Link to node %d\n", link->id);
    }
}

int main() {
    struct node* root = create_node(1, "Node A", 2);
    struct node* node_b = create_node(2, "Node B", 1);
    struct node* node_c = create_node(3, "Node C", 1);
    struct node* node_d = create_node(4, "Node D", 1);

    root->next = node_b;
    node_b->next = node_c;
    node_c->next = node_d;

    printf("Network Topology Map:\n");
    print_node(root);
    print_links(root);

    return 0;
}