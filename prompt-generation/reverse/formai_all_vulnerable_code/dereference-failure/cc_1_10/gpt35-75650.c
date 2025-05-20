//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#define N 100 // Maximum number of vertices in the graph

typedef struct {
    int node_data;
    int color;
    int degree;
} Node;

typedef struct {
    int size;
    Node *vertices;
    int **adj_matrix;
} Graph;

Graph create_graph(int size);
void init_color(Graph *graph, int num_colors);
void color_graph(Graph *graph, int num_colors);
int is_safe(Node *cur_node, Graph *graph, int color);
int pick_unassigned_node(Graph *graph);

int main() {
    Graph graph = create_graph(5);
    init_color(&graph, 4);
    color_graph(&graph, 4);

    printf("Node colors are:\n");
    for (int i = 0; i < graph.size; i++) {
        printf("Node %d -> color %d\n", graph.vertices[i].node_data, graph.vertices[i].color);
    }

    return 0;
}

Graph create_graph(int size) {
    Graph graph;
    graph.size = size;
    graph.vertices = (Node *)malloc(sizeof(Node) * size);
    graph.adj_matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        graph.adj_matrix[i] = (int *)calloc(size, sizeof(int));
    }
    
    graph.vertices[0].node_data = 0; graph.vertices[0].degree = 2;
    graph.vertices[1].node_data = 1; graph.vertices[1].degree = 2;
    graph.vertices[2].node_data = 2; graph.vertices[2].degree = 2;
    graph.vertices[3].node_data = 3; graph.vertices[3].degree = 2;
    graph.vertices[4].node_data = 4; graph.vertices[4].degree = 2;
    
    graph.adj_matrix[0][1] = 1; graph.adj_matrix[1][0] = 1;
    graph.adj_matrix[1][2] = 1; graph.adj_matrix[2][1] = 1;
    graph.adj_matrix[2][3] = 1; graph.adj_matrix[3][2] = 1;
    graph.adj_matrix[3][4] = 1; graph.adj_matrix[4][3] = 1;
    graph.adj_matrix[4][0] = 1; graph.adj_matrix[0][4] = 1;
    
    return graph;
}

void init_color(Graph *graph, int num_colors) {
    for (int i = 0; i < graph->size; i++) {
        graph->vertices[i].color = -1; // Unassigned
    }
}

void color_graph(Graph *graph, int num_colors) {
    int node_index, color;
    Node *cur_node;

    while ((node_index = pick_unassigned_node(graph)) >= 0) {
        cur_node = &graph->vertices[node_index];
        for (color = 0; color < num_colors; color++) {
            if (is_safe(cur_node, graph, color)) {
                cur_node->color = color;
                break;
            }
        }
        if (cur_node->color == -1) {
            printf("Error: All %d colors have been tried for node %d!\n", num_colors, cur_node->node_data);
            break;
        }
    }
}

int is_safe(Node *cur_node, Graph *graph, int color) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->adj_matrix[cur_node->node_data][i] && color == graph->vertices[i].color) {
            return 0; // Conflict
        }
    }
    return 1; // No conflict
}

int pick_unassigned_node(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->vertices[i].color == -1) {
            return i;
        }
    }
    return -1; // All nodes are assigned a color
}