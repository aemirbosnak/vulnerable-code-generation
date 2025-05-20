//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} Graph;

typedef struct {
    int num_colors;
    int* colors;
} Coloring;

bool is_valid_coloring(Graph* graph, Coloring* coloring) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] == 1 && coloring->colors[i] == coloring->colors[j]) {
                return false;
            }
        }
    }
    return true;
}

Coloring* color_graph(Graph* graph, int num_colors) {
    Coloring* coloring = (Coloring*)malloc(sizeof(Coloring));
    coloring->num_colors = num_colors;
    coloring->colors = (int*)malloc(graph->num_vertices * sizeof(int));

    for (int i = 0; i < graph->num_vertices; i++) {
        coloring->colors[i] = -1;
    }

    if (!is_valid_coloring(graph, coloring)) {
        return NULL;
    }

    return coloring;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_coloring(Graph* graph, Coloring* coloring) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, coloring->colors[i]);
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = 5;
    graph->num_edges = 6;
    graph->adjacency_matrix = (int**)malloc(graph->num_vertices * sizeof(int*));
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(graph->num_vertices * sizeof(int));
    }

    graph->adjacency_matrix[0][1] = 1;
    graph->adjacency_matrix[0][2] = 1;
    graph->adjacency_matrix[0][3] = 1;
    graph->adjacency_matrix[1][2] = 1;
    graph->adjacency_matrix[2][3] = 1;
    graph->adjacency_matrix[3][4] = 1;

    printf("Graph:\n");
    print_graph(graph);

    Coloring* coloring = color_graph(graph, 3);
    if (coloring == NULL) {
        printf("No valid coloring exists for this graph.\n");
    } else {
        printf("Valid coloring:\n");
        print_coloring(graph, coloring);
    }

    return 0;
}