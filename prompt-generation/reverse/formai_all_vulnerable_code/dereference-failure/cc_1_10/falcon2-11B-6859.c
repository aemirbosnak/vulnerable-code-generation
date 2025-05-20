//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex;
    int weight;
    struct graph_node *next;
} graph_node;

typedef struct {
    int num_vertices;
    int num_edges;
    graph_node *head;
} graph;

void add_vertex(graph *g, int vertex) {
    graph_node *new_node = malloc(sizeof(graph_node));
    new_node->vertex = vertex;
    new_node->weight = INT_MIN;
    new_node->next = NULL;

    if (g->head == NULL) {
        g->head = new_node;
        g->num_vertices++;
    } else {
        graph_node *current = g->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
        g->num_vertices++;
    }
}

void add_edge(graph *g, int vertex1, int vertex2, int weight) {
    graph_node *new_edge = malloc(sizeof(graph_node));
    new_edge->vertex = vertex2;
    new_edge->weight = weight;
    new_edge->next = NULL;

    graph_node *current = g->head;
    while (current!= NULL) {
        if (current->vertex == vertex1) {
            current->next = new_edge;
            new_edge->next = current->next;
            g->num_edges++;
            break;
        }
        current = current->next;
    }
}

void print_graph(graph *g) {
    graph_node *current = g->head;
    while (current!= NULL) {
        printf("Vertex: %d, Weight: %d\n", current->vertex, current->weight);
        current = current->next;
    }
}

int main() {
    graph g;
    g.num_vertices = 0;
    g.num_edges = 0;
    g.head = NULL;

    add_vertex(&g, 1);
    add_vertex(&g, 2);
    add_vertex(&g, 3);

    add_edge(&g, 1, 2, 5);
    add_edge(&g, 1, 3, 10);
    add_edge(&g, 2, 3, 7);

    print_graph(&g);

    return 0;
}