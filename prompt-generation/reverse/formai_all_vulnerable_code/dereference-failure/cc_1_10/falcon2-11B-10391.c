//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int color;
    struct node *next;
} node;

typedef struct {
    int num_nodes;
    node *head;
} graph;

void add_edge(graph *g, int src, int dest) {
    node *new_node = malloc(sizeof(node));
    new_node->color = 0;
    new_node->next = g->head;
    g->head = new_node;
    g->head->next = NULL;
    g->num_nodes++;
}

void graph_color(graph *g) {
    int colors[g->num_nodes];
    int num_colors = 0;
    node *curr = g->head;
    int prev_color = 0;

    while (curr!= NULL) {
        if (colors[curr->color] == 0) {
            colors[curr->color] = prev_color;
            num_colors++;
        }
        prev_color = colors[curr->color];
        curr = curr->next;
    }

    for (int i = 0; i < g->num_nodes; i++) {
        colors[i] = num_colors;
    }

    for (int i = 0; i < g->num_nodes; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    graph g;
    g.num_nodes = 0;
    g.head = NULL;

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 4, 5);

    graph_color(&g);

    return 0;
}