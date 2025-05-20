//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000
#define MAX_COLORS 7

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int vertex, color;
} Node;

int **adjacency_matrix, **color_matrix;
int num_vertices, num_edges, **edge_list, available_colors[MAX_VERTICES];

void read_graph_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fscanf(file, "%d %d", &num_vertices, &num_edges);

    adjacency_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; ++i) {
        adjacency_matrix[i] = calloc(num_vertices, sizeof(int));
    }

    edge_list = malloc(num_edges * sizeof(int *));

    for (int i = 0; i < num_edges; ++i) {
        fscanf(file, "%d %d %d", &edge_list[i][0], &edge_list[i][1], &edge_list[i][2]);
        adjacency_matrix[edge_list[i][0]][edge_list[i][1]] = edge_list[i][2];
        adjacency_matrix[edge_list[i][1]][edge_list[i][0]] = edge_list[i][2];
    }

    fclose(file);
}

bool is_graph_colorable(int current_vertex, int current_color) {
    for (int i = 0; i < num_vertices; ++i) {
        if (adjacency_matrix[current_vertex][i] && color_matrix[i][current_color % MAX_COLORS]) {
            return false;
        }
    }
    return true;
}

void graph_coloring_backtracking(int current_vertex, int current_color) {
    if (current_vertex >= num_vertices) {
        printf("Found a valid coloring:\n");
        for (int i = 0; i < num_vertices; ++i) {
            printf("Vertex %d is colored with %d\n", i, color_matrix[i][(current_color + i) % MAX_COLORS]);
        }
        exit(0);
    }

    for (int color = 0; color < MAX_COLORS; ++color) {
        if (is_graph_colorable(current_vertex, color)) {
            color_matrix[current_vertex][color] = 1;
            available_colors[current_vertex] = -1;
            graph_coloring_backtracking(current_vertex + 1, current_color + 1);
            if (current_vertex > 0) {
                color_matrix[current_vertex][color] = 0;
                available_colors[current_vertex] = color;
            }
        }
    }
}

void initialize_color_matrix() {
    for (int i = 0; i < num_vertices; ++i) {
        color_matrix[i] = calloc(MAX_COLORS, sizeof(int));
        available_colors[i] = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <graph.txt>\n", argv[0]);
        return 1;
    }

    clock_t start = clock();

    read_graph_from_file(argv[1]);
    initialize_color_matrix();

    graph_coloring_backtracking(0, 0);

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Could not find a valid coloring in %.2f seconds.\n", elapsed_time);

    for (int i = 0; i < num_vertices; ++i) {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);

    for (int i = 0; i < num_edges; ++i) {
        free(edge_list[i]);
    }
    free(edge_list);

    for (int i = 0; i < num_vertices; ++i) {
        free(color_matrix[i]);
    }
    free(color_matrix);

    return 0;
}