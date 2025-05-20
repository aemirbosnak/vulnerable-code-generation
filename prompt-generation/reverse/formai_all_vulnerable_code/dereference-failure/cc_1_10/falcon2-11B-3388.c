//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_COLOR 5

typedef struct {
    int color;
    struct node *next;
} node;

typedef struct {
    node *head;
    int count;
} graph;

void add_node(graph *g, int color) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->color = color;
    new_node->next = NULL;
    if (g->head == NULL) {
        g->head = new_node;
        g->count = 1;
    } else {
        new_node->next = g->head;
        g->head = new_node;
        g->count++;
    }
}

void print_graph(graph *g) {
    node *node = g->head;
    while (node!= NULL) {
        printf("%d ", node->color);
        node = node->next;
    }
    printf("\n");
}

bool color_graph(graph *g) {
    int color_count[MAX_COLOR] = {0};
    for (int i = 0; i < MAX_COLOR; i++) {
        color_count[i] = 0;
    }
    for (int i = 0; i < g->count; i++) {
        node *node = g->head;
        while (node!= NULL) {
            if (node->color!= -1) {
                color_count[node->color]++;
            }
            node = node->next;
        }
    }
    for (int i = 0; i < MAX_COLOR; i++) {
        if (color_count[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    graph g;
    g.head = NULL;
    g.count = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        add_node(&g, i);
    }
    printf("Graph before coloring:\n");
    print_graph(&g);
    if (color_graph(&g)) {
        printf("Graph is colorable.\n");
    } else {
        printf("Graph is not colorable.\n");
    }
    return 0;
}