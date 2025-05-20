//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int vertices;
    int** adj_matrix;
};

void print_colors(int* colors, int vertices) {
    printf("Colors assigned to vertices:\n");
    for (int i = 0; i < vertices; i++)
        printf("Vertex %d: Color %d\n", i, colors[i]);
}

int check_color(int vertex, int color, struct Graph graph, int* colors) {
    for (int i = 0; i < graph.vertices; i++) {
        if (graph.adj_matrix[vertex][i] && color == colors[i])
            return 0;
    }
    return 1;
}

int graph_coloring_util(int vertex, int vertices, struct Graph graph, int* colors, int max_colors) {
    if (vertex == vertices)
        return 1;

    for (int i = 1; i <= max_colors; i++) {
        if (check_color(vertex, i, graph, colors)) {
            colors[vertex] = i;
            if (graph_coloring_util(vertex+1, vertices, graph, colors, max_colors))
                return 1;
            colors[vertex] = 0;
        }
    }
    return 0;
}

void graph_coloring(int vertices, struct Graph graph) {
    int max_colors = vertices;
    int* colors = (int *) calloc(vertices, sizeof(int));
    if (graph_coloring_util(0, vertices, graph, colors, max_colors))
        print_colors(colors, vertices);
    else
        printf("Could not color the graph with maximum %d colors\n", max_colors);
}

int main() {
    struct Graph graph;
    int vertices = 5;
    int max_edges = vertices*(vertices-1)/2;
    graph.vertices = vertices;
    graph.adj_matrix = (int **) calloc(vertices, sizeof(int*));
    for (int i = 0; i < vertices; i++)
        graph.adj_matrix[i] = (int *) calloc(vertices, sizeof(int));

    // Creating edges between vertices
    graph.adj_matrix[0][1] = 1;
    graph.adj_matrix[0][2] = 1;
    graph.adj_matrix[1][3] = 1;
    graph.adj_matrix[2][3] = 1;
    graph.adj_matrix[3][4] = 1;

    // Coloring the graph
    graph_coloring(vertices, graph);

    for (int i = 0; i < vertices; i++)
        free(graph.adj_matrix[i]);
    free(graph.adj_matrix);
    return 0;
}