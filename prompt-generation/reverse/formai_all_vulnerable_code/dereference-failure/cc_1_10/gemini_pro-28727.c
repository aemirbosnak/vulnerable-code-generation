//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Graph coloring problem
// Given a graph with n vertices and m edges, find a coloring of the vertices with k colors such that no two adjacent vertices have the same color.

struct graph_node {
    int val;
    struct graph_node *next;
};

struct graph {
    int n;
    struct graph_node **adj;
};

struct color {
    int val;
    struct color *next;
};

struct coloring {
    int n;
    struct color **col;
};

bool is_safe(struct graph *g, struct coloring *c, int v, int color) {
    struct graph_node *u;
    for (u = g->adj[v]; u != NULL; u = u->next) {
        if (c->col[u->val]->val == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(struct graph *g, struct coloring *c, int v) {
    if (v == g->n) {
        return true;
    }
    struct color *p;
    for (p = c->col[v]; p != NULL; p = p->next) {
        if (is_safe(g, c, v, p->val)) {
            c->col[v]->val = p->val;
            if (color_graph(g, c, v + 1)) {
                return true;
            }
            c->col[v]->val = 0;
        }
    }
    return false;
}

int main() {
    struct graph g;
    g.n = 4;
    g.adj = malloc(sizeof(struct graph_node *) * g.n);
    for (int i = 0; i < g.n; i++) {
        g.adj[i] = NULL;
    }
    struct graph_node *n1 = malloc(sizeof(struct graph_node));
    n1->val = 1;
    n1->next = NULL;
    struct graph_node *n2 = malloc(sizeof(struct graph_node));
    n2->val = 2;
    n2->next = NULL;
    struct graph_node *n3 = malloc(sizeof(struct graph_node));
    n3->val = 3;
    n3->next = NULL;
    g.adj[0] = n1;
    g.adj[1] = n2;
    g.adj[2] = n3;

    struct coloring c;
    c.n = 4;
    c.col = malloc(sizeof(struct color *) * c.n);
    for (int i = 0; i < c.n; i++) {
        c.col[i] = NULL;
    }
    struct color *col1 = malloc(sizeof(struct color));
    col1->val = 1;
    col1->next = NULL;
    struct color *col2 = malloc(sizeof(struct color));
    col2->val = 2;
    col2->next = NULL;
    struct color *col3 = malloc(sizeof(struct color));
    col3->val = 3;
    col3->next = NULL;
    c.col[0] = col1;
    c.col[1] = col2;
    c.col[2] = col3;

    if (color_graph(&g, &c, 0)) {
        for (int i = 0; i < c.n; i++) {
            printf("%d ", c.col[i]->val);
        }
        printf("\n");
    } else {
        printf("No solution\n");
    }

    return 0;
}