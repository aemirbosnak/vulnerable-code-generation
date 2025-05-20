//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VERTICES 100
#define NUM_COLORS 5

// Graph data structure
typedef struct graph {
    int num_vertices;
    int **adj_matrix;
} graph_t;

// Create a new graph
graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Free the memory allocated for the graph
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Add an edge to the graph
void add_edge(graph_t *graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
}

// Check if two vertices are adjacent
int are_adjacent(graph_t *graph, int vertex1, int vertex2) {
    return graph->adj_matrix[vertex1][vertex2] == 1;
}

// Color a vertex
void color_vertex(graph_t *graph, int vertex, int color) {
    graph->adj_matrix[vertex][vertex] = color;
}

// Check if a coloring is valid
int is_valid_coloring(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (are_adjacent(graph, i, j) && graph->adj_matrix[i][i] == graph->adj_matrix[j][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Print the coloring of the graph
void print_coloring(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, graph->adj_matrix[i][i]);
    }
}

// Generate a random graph
graph_t *generate_random_graph(int num_vertices) {
    graph_t *graph = create_graph(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            if (rand() % 2 == 1) {
                add_edge(graph, i, j);
            }
        }
    }
    return graph;
}

// Solve the graph coloring problem using a greedy algorithm
int graph_coloring(graph_t *graph) {
    int colors[NUM_VERTICES];
    for (int i = 0; i < NUM_VERTICES; i++) {
        colors[i] = -1;
    }
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (colors[i] == -1) {
            int color = 0;
            while (color < NUM_COLORS) {
                int valid = 1;
                for (int j = 0; j < NUM_VERTICES; j++) {
                    if (are_adjacent(graph, i, j) && colors[j] == color) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    colors[i] = color;
                    break;
                }
                color++;
            }
            if (colors[i] == -1) {
                return 0;
            }
        }
    }
    for (int i = 0; i < NUM_VERTICES; i++) {
        color_vertex(graph, i, colors[i]);
    }
    return 1;
}

int main() {
    srand(time(NULL));
    graph_t *graph = generate_random_graph(NUM_VERTICES);
    if (graph_coloring(graph)) {
        printf("Graph colored successfully\n");
        print_coloring(graph);
    } else {
        printf("Graph cannot be colored\n");
    }
    free_graph(graph);
    return 0;
}