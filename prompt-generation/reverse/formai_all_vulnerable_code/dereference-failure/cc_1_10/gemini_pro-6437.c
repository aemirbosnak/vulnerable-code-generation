//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10

typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adjacency_matrix;
} graph_t;

typedef struct solution {
    int *color_assignment;
    int num_colors_used;
} solution_t;

bool is_safe(graph_t *graph, solution_t *solution, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && solution->color_assignment[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_color(graph_t *graph, solution_t *solution, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 0; color < MAX_COLORS; color++) {
        if (is_safe(graph, solution, vertex, color)) {
            solution->color_assignment[vertex] = color;
            if (graph_color(graph, solution, vertex + 1)) {
                return true;
            }
            solution->color_assignment[vertex] = -1;
        }
    }

    return false;
}

solution_t *solve_graph_coloring(graph_t *graph) {
    solution_t *solution = malloc(sizeof(solution_t));
    solution->color_assignment = malloc(graph->num_vertices * sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        solution->color_assignment[i] = -1;
    }
    solution->num_colors_used = 0;

    if (graph_color(graph, solution, 0)) {
        return solution;
    } else {
        free(solution->color_assignment);
        free(solution);
        return NULL;
    }
}

void print_solution(solution_t *solution, graph_t *graph) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d\t%d\n", i, solution->color_assignment[i]);
    }
}

int main() {
    graph_t graph = {
        .num_vertices = 4,
        .num_edges = 4,
        .adjacency_matrix = (int **)malloc(4 * sizeof(int *))
    };

    for (int i = 0; i < 4; i++) {
        graph.adjacency_matrix[i] = (int *)malloc(4 * sizeof(int));
    }

    graph.adjacency_matrix[0][1] = 1;
    graph.adjacency_matrix[0][2] = 1;
    graph.adjacency_matrix[1][2] = 1;
    graph.adjacency_matrix[2][3] = 1;

    solution_t *solution = solve_graph_coloring(&graph);

    if (solution != NULL) {
        print_solution(solution, &graph);
    } else {
        printf("No solution found.\n");
    }

    for (int i = 0; i < 4; i++) {
        free(graph.adjacency_matrix[i]);
    }
    free(graph.adjacency_matrix);
    free(solution->color_assignment);
    free(solution);

    return 0;
}