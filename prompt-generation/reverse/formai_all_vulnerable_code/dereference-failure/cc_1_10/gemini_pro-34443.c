//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    int n;
    struct node **adj;
};

struct graph {
    int n;
    struct node **nodes;
};

struct graph *new_graph(int n) {
    struct graph *g = malloc(sizeof(struct graph));
    g->n = n;
    g->nodes = malloc(n * sizeof(struct node *));
    for (int i = 0; i < n; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

void add_node(struct graph *g, char *name) {
    int i = g->n++;
    g->nodes = realloc(g->nodes, g->n * sizeof(struct node *));
    g->nodes[i] = malloc(sizeof(struct node));
    g->nodes[i]->name = strdup(name);
    g->nodes[i]->n = 0;
    g->nodes[i]->adj = NULL;
}

void add_edge(struct graph *g, char *a, char *b) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        if (strcmp(g->nodes[i]->name, a) == 0) {
            break;
        }
    }
    for (j = 0; j < g->n; j++) {
        if (strcmp(g->nodes[j]->name, b) == 0) {
            break;
        }
    }
    if (i == g->n || j == g->n) {
        fprintf(stderr, "Invalid node name\n");
        return;
    }
    g->nodes[i]->adj = realloc(g->nodes[i]->adj, (g->nodes[i]->n + 1) * sizeof(struct node *));
    g->nodes[i]->adj[g->nodes[i]->n++] = g->nodes[j];
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%s: ", g->nodes[i]->name);
        for (int j = 0; j < g->nodes[i]->n; j++) {
            printf("%s ", g->nodes[i]->adj[j]->name);
        }
        printf("\n");
    }
}

int main() {
    struct graph *g = new_graph(0);
    add_node(g, "A");
    add_node(g, "B");
    add_node(g, "C");
    add_node(g, "D");
    add_edge(g, "A", "B");
    add_edge(g, "B", "C");
    add_edge(g, "C", "D");
    add_edge(g, "D", "A");
    print_graph(g);
    return 0;
}