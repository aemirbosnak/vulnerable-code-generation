//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct graph_node {
    int color;
    struct graph_node *next;
} graph_node;

typedef struct graph {
    int num_nodes;
    int num_edges;
    graph_node *nodes;
} graph;

graph* create_graph(int num_nodes) {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = 0;
    g->nodes = malloc(sizeof(graph_node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i].color = -1;
        g->nodes[i].next = NULL;
    }
    return g;
}

void add_edge(graph *g, int u, int v) {
    graph_node *new_node = malloc(sizeof(graph_node));
    new_node->color = -1;
    new_node->next = g->nodes[u].next;
    g->nodes[u].next = new_node;
    g->num_edges++;
}

int check_color(graph *g, int u, int color) {
    graph_node *curr = g->nodes[u].next;
    while (curr != NULL) {
        if (curr->color == color) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int color_graph(graph *g) {
    int colors[MAX_COLORS];
    for (int i = 0; i < MAX_COLORS; i++) {
        colors[i] = 0;
    }
    for (int i = 0; i < g->num_nodes; i++) {
        int color = 0;
        while (color < MAX_COLORS && check_color(g, i, color)) {
            color++;
        }
        if (color == MAX_COLORS) {
            return 0;
        }
        g->nodes[i].color = color;
        colors[color]++;
    }
    return 1;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: color %d, neighbors: ", i, g->nodes[i].color);
        graph_node *curr = g->nodes[i].next;
        while (curr != NULL) {
            printf("%d ", curr->color);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);
    graph *g = create_graph(num_nodes);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(g, u, v);
    }
    if (color_graph(g)) {
        printf("The graph can be colored with %d colors.\n", MAX_COLORS);
        print_graph(g);
    } else {
        printf("The graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}