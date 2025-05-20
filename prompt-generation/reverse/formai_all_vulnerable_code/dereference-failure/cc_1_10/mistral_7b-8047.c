//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int color;
    struct node *next;
} node;

typedef struct {
    int num_vertices;
    node **adj_list;
} graph;

void print_graph(graph *g) {
    int i;
    node *temp;

    printf("Adjacency list representation of the graph:\n");
    for (i = 0; i < g->num_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (temp = g->adj_list[i]; temp != NULL; temp = temp->next) {
            printf("(%d, %d) ", temp->vertex, temp->color);
        }
    }
}

bool is_valid_coloring(graph *g, int vertex, int color) {
    node *temp;

    for (temp = g->adj_list[vertex]; temp != NULL; temp = temp->next) {
        if (temp->color == color) {
            return false;
        }
    }

    return true;
}

bool graph_coloring(graph *g, int num_colors) {
    int i, v, c, min_unassigned;

    for (i = 0; i < g->num_vertices; i++) {
        g->adj_list[i] = NULL;
        g->adj_list[i]->color = -1;
    }

    for (v = 0; v < g->num_vertices; v++) {
        min_unassigned = -1;

        for (c = 0; c < num_colors; c++) {
            if (min_unassigned == -1 || is_valid_coloring(g, v, c)) {
                g->adj_list[v] = malloc(sizeof(node));
                g->adj_list[v]->vertex = v;
                g->adj_list[v]->color = c;
                min_unassigned = v;
            }
        }

        if (min_unassigned == -1) {
            printf("\nGraph cannot be colored with %d colors.\n", num_colors);
            return false;
        }
    }

    print_graph(g);
    return true;
}

int main() {
    int num_vertices = 10;
    graph *g = malloc(sizeof(graph));
    int num_colors = 3;

    g->num_vertices = num_vertices;
    g->adj_list = calloc(num_vertices, sizeof(node *));

    // Petersen graph construction
    // ...

    graph_coloring(g, num_colors);

    free(g->adj_list);
    free(g);

    return 0;
}