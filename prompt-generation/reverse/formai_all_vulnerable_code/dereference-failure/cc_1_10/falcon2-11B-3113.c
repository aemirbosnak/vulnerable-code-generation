//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct graph {
    int vertices;
    int **adjacency_list;
    bool *visited;
} Graph;

void initialize_graph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    graph->adjacency_list = (int **)malloc(vertices * sizeof(int *));
    graph->visited = (bool *)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjacency_list[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacency_list[i][j] = 0;
        }
    }
}

void print_graph(Graph *graph) {
    printf("Vertices: %d\n", graph->vertices);
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacency_list[i][j]);
        }
        printf("\n");
    }
}

bool is_adjacent(int v1, int v2, Graph *graph) {
    return graph->adjacency_list[v1][v2] == 1;
}

void solve_graph_coloring(Graph *graph, int start_vertex, int *colors) {
    graph->visited[start_vertex] = true;
    int color = 1;
    colors[start_vertex] = color;

    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i] && is_adjacent(start_vertex, i, graph)) {
            solve_graph_coloring(graph, i, colors);
        }
    }

    graph->visited[start_vertex] = false;
}

void print_coloring(int *colors, int vertices) {
    printf("Coloring: ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    int vertices = 4;
    Graph graph;
    initialize_graph(&graph, vertices);

    graph.adjacency_list[0][1] = 1;
    graph.adjacency_list[0][2] = 1;
    graph.adjacency_list[1][0] = 1;
    graph.adjacency_list[1][2] = 1;
    graph.adjacency_list[2][0] = 1;
    graph.adjacency_list[2][1] = 1;

    int colors[vertices];

    solve_graph_coloring(&graph, 0, colors);
    print_coloring(colors, vertices);

    return 0;
}