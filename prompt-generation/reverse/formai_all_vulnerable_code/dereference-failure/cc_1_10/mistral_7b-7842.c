//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLOR 10

typedef struct {
    int vertex;
    int color;
} Vertex;

typedef struct {
    int num_vertices;
    int num_edges;
    Vertex *vertices;
    int **adj_matrix;
} Graph;

void init_graph(Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->vertices = (Vertex *) calloc(num_vertices, sizeof(Vertex));
    graph->adj_matrix = (int *) calloc(num_vertices * num_vertices, sizeof(int));
}

void add_edge(Graph *graph, int u, int v) {
    if (u >= graph->num_vertices || v >= graph->num_vertices) {
        printf("Invalid vertices\n");
        return;
    }
    graph->adj_matrix[u * graph->num_vertices + v] = 1;
    graph->adj_matrix[v * graph->num_vertices + u] = 1;
    graph->num_edges++;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d : ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i * graph->num_vertices + j]);
        }
        printf("\n");
    }
}

bool is_safe(Graph *graph, int m, int v) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[v * graph->num_vertices + i] && graph->vertices[i].color == m) {
            return false;
        }
    }
    return true;
}

int graph_coloring(Graph *graph, int m) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (is_safe(graph, m, i)) {
            graph->vertices[i].color = m;
            if (graph->num_vertices - 1 == i) {
                return m;
            }
            m++;
        }
    }
    return -1;
}

void free_graph(Graph *graph) {
    free(graph->vertices);
    free(graph->adj_matrix);
    free(graph);
}

int main() {
    srand(time(NULL));
    int num_vertices = 5;

    Graph *graph = (Graph *) calloc(1, sizeof(Graph));
    init_graph(graph, num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        add_edge(graph, i, rand() % num_vertices);
    }

    printf("Graph before coloring:\n");
    print_graph(graph);

    int max_color = graph_coloring(graph, 0);
    printf("Graph after coloring:\n");
    print_graph(graph);

    free_graph(graph);
    return 0;
}