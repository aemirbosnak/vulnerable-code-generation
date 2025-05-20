//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7

typedef struct {
    int id;
    int color;
} Node;

typedef struct {
    Node *nodes;
    int num_nodes;
    int num_colors;
} Graph;

void create_graph(Graph *graph, int num_nodes) {
    graph->nodes = (Node *)malloc(sizeof(Node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].color = -1;
    }
    graph->num_nodes = num_nodes;
    graph->num_colors = MAX_COLORS;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d ", graph->nodes[i].id);
    }
    printf("\n");
}

int is_valid_color(Graph *graph, int node_id, int color) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->nodes[i].color == color && i!= node_id) {
            return 0;
        }
    }
    return 1;
}

int color_node(Graph *graph, int node_id, int color) {
    if (is_valid_color(graph, node_id, color)) {
        graph->nodes[node_id].color = color;
        return 1;
    }
    return 0;
}

int color_graph(Graph *graph) {
    srand(time(NULL));
    for (int i = 0; i < graph->num_nodes; i++) {
        int color = rand() % graph->num_colors;
        while (!color_node(graph, i, color)) {
            color = (color + 1) % graph->num_colors;
        }
    }
    return 1;
}

int main() {
    Graph graph;
    int num_nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    create_graph(&graph, num_nodes);

    if (color_graph(&graph)) {
        printf("Colored graph:\n");
        print_graph(&graph);
    } else {
        printf("Failed to color graph.\n");
    }

    return 0;
}