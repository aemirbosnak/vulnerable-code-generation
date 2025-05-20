//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COLORS 4
#define NUM_NODES 10

typedef struct node {
    int color;
    struct node *next;
} node_t;

typedef struct graph {
    node_t *nodes;
} graph_t;

graph_t *create_graph(int num_nodes) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->nodes = malloc(num_nodes * sizeof(node_t));

    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].color = -1;
        graph->nodes[i].next = NULL;
    }

    return graph;
}

void free_graph(graph_t *graph) {
    for (int i = 0; i < NUM_NODES; i++) {
        node_t *node = &graph->nodes[i];
        while (node->next != NULL) {
            node = node->next;
            free(node->next);
        }
    }

    free(graph->nodes);
    free(graph);
}

void add_edge(graph_t *graph, int node1, int node2) {
    node_t *node = &graph->nodes[node1];
    while (node->next != NULL) {
        node = node->next;
    }

    node->next = malloc(sizeof(node_t));
    node->next->color = -1;
    node->next->next = NULL;
}

int is_valid_coloring(graph_t *graph) {
    for (int i = 0; i < NUM_NODES; i++) {
        node_t *node = &graph->nodes[i];
        while (node->next != NULL) {
            node = node->next;
            if (node->color == graph->nodes[i].color) {
                return 0;
            }
        }
    }

    return 1;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < NUM_NODES; i++) {
        printf("Node %d: ", i);
        node_t *node = &graph->nodes[i];
        while (node->next != NULL) {
            node = node->next;
            printf("%d ", node->color);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    graph_t *graph = create_graph(NUM_NODES);

    for (int i = 0; i < NUM_NODES; i++) {
        for (int j = i + 1; j < NUM_NODES; j++) {
            if (rand() % 2 == 0) {
                add_edge(graph, i, j);
            }
        }
    }

    int num_colors = NUM_COLORS;
    int num_solutions = 0;

    while (num_colors <= NUM_COLORS) {
        for (int i = 0; i < NUM_NODES; i++) {
            graph->nodes[i].color = rand() % num_colors;
        }

        if (is_valid_coloring(graph)) {
            num_solutions++;
            printf("Solution %d:\n", num_solutions);
            print_graph(graph);
        }

        num_colors++;
    }

    printf("Number of solutions: %d\n", num_solutions);

    free_graph(graph);

    return 0;
}