//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct {
    int num_colors;
    int *colors;
} Graph;

Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_colors = 0;
    graph->colors = malloc(sizeof(int) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->colors[i] = -1;
    }
    return graph;
}

void free_graph(Graph *graph) {
    free(graph->colors);
    free(graph);
}

int add_edge(Graph *graph, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= graph->num_colors || vertex2 < 0 || vertex2 >= graph->num_colors) {
        return -1;
    }
    if (graph->colors[vertex1] == graph->colors[vertex2]) {
        return -1;
    }
    return 0;
}

int color_graph(Graph *graph) {
    int num_vertices = graph->num_colors;
    int *colors = malloc(sizeof(int) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }
    int num_colors = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            colors[i] = num_colors++;
        }
        for (int j = i + 1; j < num_vertices; j++) {
            if (graph->colors[i] == graph->colors[j]) {
                colors[j] = colors[i];
            }
        }
    }
    free(graph->colors);
    graph->colors = colors;
    graph->num_colors = num_colors;
    return num_colors;
}

int main() {
    int num_vertices = 5;
    int num_edges = 4;
    Graph *graph = create_graph(num_vertices, num_edges);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    int num_colors = color_graph(graph);
    printf("Number of colors: %d\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, graph->colors[i]);
    }
    free_graph(graph);
    return 0;
}