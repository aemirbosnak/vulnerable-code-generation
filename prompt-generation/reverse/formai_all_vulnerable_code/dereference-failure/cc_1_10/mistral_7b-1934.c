//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int color;
} vertex_t;

typedef struct {
    int num_vertices;
    int num_edges;
    vertex_t** vertices;
    int** adj_matrix;
} graph_t;

void create_graph(graph_t* graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->vertices = (vertex_t**) calloc(num_vertices, sizeof(vertex_t*));
    graph->adj_matrix = (int*) calloc(num_vertices * num_vertices, sizeof(int));

    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i] = (vertex_t*) calloc(1, sizeof(vertex_t));
        graph->vertices[i]->vertex = i;
        graph->vertices[i]->color = -1;
    }
}

void add_edge(graph_t* graph, int src, int dest) {
    graph->adj_matrix[src * graph->num_vertices + dest] = 1;
    graph->adj_matrix[dest * graph->num_vertices + src] = 1;
}

bool is_valid_color(graph_t* graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (i != vertex && graph->vertices[i]->color == color && graph->adj_matrix[vertex * graph->num_vertices + i] == 1) {
            return false;
        }
    }
    return true;
}

void graph_color(graph_t* graph, int vertex, int current_color) {
    if (vertex >= graph->num_vertices) {
        return;
    }

    if (graph->vertices[vertex]->color != -1) {
        return;
    }

    graph->vertices[vertex]->color = current_color;

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex * graph->num_vertices + i] == 1) {
            int next_color = current_color + 1 >= 7 ? 0 : current_color + 1;
            graph_color(graph, i, next_color);
        }
    }
}

void print_graph_coloring(graph_t* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d is colored with color %d\n", graph->vertices[i]->vertex, graph->vertices[i]->color);
    }
}

int main() {
    int num_vertices = 6;

    graph_t graph;
    create_graph(&graph, num_vertices);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 2, 5);

    graph_color(&graph, 0, 0);

    print_graph_coloring(&graph);

    free(graph.vertices);
    free(graph.adj_matrix);
    free(graph.vertices);
    free(graph.adj_matrix);

    return 0;
}