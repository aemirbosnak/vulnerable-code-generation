//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define NUM_COLORS 5

typedef struct {
    int num_nodes;
    int num_edges;
    int* adj_list;
} graph_t;

graph_t* create_graph(int num_nodes, int num_edges) {
    graph_t* graph = malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adj_list = malloc(sizeof(int) * num_nodes * num_nodes);
    return graph;
}

void destroy_graph(graph_t* graph) {
    free(graph->adj_list);
    free(graph);
}

int is_safe(graph_t* graph, int node, int color, int* colors) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_list[node * graph->num_nodes + i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_color(graph_t* graph, int* colors, int node) {
    if (node == graph->num_nodes) {
        return 1;
    }
    for (int i = 0; i < NUM_COLORS; i++) {
        if (is_safe(graph, node, i, colors)) {
            colors[node] = i;
            if (graph_color(graph, colors, node + 1)) {
                return 1;
            }
            colors[node] = -1;
        }
    }
    return 0;
}

void print_graph(graph_t* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_list[i * graph->num_nodes + j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t* graph = create_graph(4, 4);
    graph->adj_list[0 * 4 + 1] = 1;
    graph->adj_list[0 * 4 + 2] = 1;
    graph->adj_list[1 * 4 + 2] = 1;
    graph->adj_list[2 * 4 + 3] = 1;
    graph->adj_list[3 * 4 + 0] = 1;
    print_graph(graph);
    int* colors = malloc(sizeof(int) * graph->num_nodes);
    for (int i = 0; i < graph->num_nodes; i++) {
        colors[i] = -1;
    }
    if (graph_color(graph, colors, 0)) {
        printf("Graph can be colored with %d colors\n", NUM_COLORS);
        for (int i = 0; i < graph->num_nodes; i++) {
            printf("Node %d is colored with color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors\n", NUM_COLORS);
    }
    destroy_graph(graph);
    free(colors);
    return 0;
}