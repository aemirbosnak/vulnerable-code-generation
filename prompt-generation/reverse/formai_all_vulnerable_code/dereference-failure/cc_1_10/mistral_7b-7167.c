//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define MIN_COLOR 0
#define MAX_COLOR 5

typedef struct {
    int vertex;
    int color;
} Node;

typedef struct {
    int num_vertices;
    int num_edges;
    Node **adj_matrix;
} Graph;

void create_graph(Graph *graph, int vertices) {
    graph->num_vertices = vertices;
    graph->num_edges = 0;
    graph->adj_matrix = calloc(vertices, sizeof(Node *));

    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = calloc(vertices, sizeof(Node));
    }
}

void add_edge(Graph *graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2].vertex = vertex2;
    graph->adj_matrix[vertex2][vertex1].vertex = vertex1;
    graph->num_edges++;
}

bool is_valid_color(Graph *graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[i][vertex].color == color ||
            graph->adj_matrix[vertex][i].color == color) {
            return false;
        }
    }
    return true;
}

int greedy_coloring(Graph *graph, int vertex, int current_color) {
    if (vertex >= graph->num_vertices) {
        return graph->num_vertices;
    }

    int color = current_color;

    for (int i = MIN_COLOR; i <= MAX_COLOR; i++) {
        if (is_valid_color(graph, vertex, i)) {
            graph->adj_matrix[vertex][vertex].color = i;
            color = i;
            break;
        }
    }

    for (int neighbor = 0; neighbor < graph->num_vertices; neighbor++) {
        if (graph->adj_matrix[vertex][neighbor].vertex != -1) {
            color = greedy_coloring(graph, neighbor, color);
        }
    }

    return color;
}

void print_graph(Graph *graph) {
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j].color);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    create_graph(&graph, 6);

    add_edge(&graph, 0, 2);
    add_edge(&graph, 0, 5);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 5);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 2, 5);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);

    int num_vertices_colored = greedy_coloring(&graph, 0, MIN_COLOR);
    printf("Minimum number of colors required: %d\n", num_vertices_colored);

    print_graph(&graph);

    free(graph.adj_matrix);
    free(graph.adj_matrix);

    return 0;
}