//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct node {
    int id;
    char *name;
    int num_links;
    int *links;
} node;

typedef struct graph {
    int num_nodes;
    int num_links;
    node *nodes;
} graph;

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = &g->nodes[i];
        printf("Node %d: %s\n", n->id, n->name);
        for (int j = 0; j < n->num_links; j++) {
            printf("  Link to node %d\n", n->links[j]);
        }
    }
}

int main() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    g->num_links = 0;
    g->nodes = malloc(sizeof(node) * MAX_NODES);

    // Add some nodes to the graph
    node *n1 = &g->nodes[g->num_nodes++];
    n1->id = 1;
    n1->name = "Node 1";
    n1->num_links = 0;
    n1->links = NULL;

    node *n2 = &g->nodes[g->num_nodes++];
    n2->id = 2;
    n2->name = "Node 2";
    n2->num_links = 0;
    n2->links = NULL;

    node *n3 = &g->nodes[g->num_nodes++];
    n3->id = 3;
    n3->name = "Node 3";
    n3->num_links = 0;
    n3->links = NULL;

    // Add some links to the graph
    n1->links = malloc(sizeof(int) * MAX_LINKS);
    n1->links[n1->num_links++] = n2->id;
    n1->links[n1->num_links++] = n3->id;

    n2->links = malloc(sizeof(int) * MAX_LINKS);
    n2->links[n2->num_links++] = n1->id;
    n2->links[n2->num_links++] = n3->id;

    n3->links = malloc(sizeof(int) * MAX_LINKS);
    n3->links[n3->num_links++] = n1->id;
    n3->links[n3->num_links++] = n2->id;

    // Print the graph
    print_graph(g);

    // Free the graph
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i].name);
        free(g->nodes[i].links);
    }
    free(g->nodes);
    free(g);

    return 0;
}