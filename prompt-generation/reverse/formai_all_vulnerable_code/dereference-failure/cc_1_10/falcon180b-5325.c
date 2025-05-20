//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_LINES 10000

struct node {
    char name[32];
    int connected;
    int *connections;
    int num_connections;
};

struct line {
    int node1;
    int node2;
};

int num_nodes = 0;
int num_lines = 0;
struct node *nodes = NULL;
struct line *lines = NULL;

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    struct node *node = &nodes[num_nodes];
    strcpy(node->name, name);
    node->connected = 0;
    node->num_connections = 0;
    node->connections = NULL;
    num_nodes++;
}

void add_line(int node1, int node2) {
    if (num_lines >= MAX_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        exit(1);
    }
    struct line *line = &lines[num_lines];
    line->node1 = node1;
    line->node2 = node2;
    num_lines++;
}

int find_node(char *name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s\n", nodes[i].name);
    }
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d -> %d\n", lines[i].node1, lines[i].node2);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_line(0, 1);
    add_line(1, 2);
    print_nodes();
    print_lines();
    return 0;
}