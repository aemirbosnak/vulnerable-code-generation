//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1024

struct node {
    int ip;
    char name[256];
    struct node *next;
};

struct graph {
    int num_nodes;
    struct node *nodes;
};

struct graph *create_graph() {
    struct graph *g = malloc(sizeof(struct graph));
    g->num_nodes = 0;
    g->nodes = NULL;
    return g;
}

void add_node(struct graph *g, int ip, char *name) {
    struct node *n = malloc(sizeof(struct node));
    n->ip = ip;
    strcpy(n->name, name);
    n->next = g->nodes;
    g->nodes = n;
    g->num_nodes++;
}

void print_graph(struct graph *g) {
    struct node *n = g->nodes;
    while (n != NULL) {
        printf("%s (%d)\n", n->name, n->ip);
        n = n->next;
    }
}

void free_graph(struct graph *g) {
    struct node *n = g->nodes;
    while (n != NULL) {
        struct node *tmp = n->next;
        free(n);
        n = tmp;
    }
    free(g);
}

int main() {
    struct graph *g = create_graph();
    add_node(g, 19216811, "localhost");
    add_node(g, 19216812, "router");
    add_node(g, 19216813, "server");
    add_node(g, 19216814, "client");
    print_graph(g);
    free_graph(g);
    return 0;
}