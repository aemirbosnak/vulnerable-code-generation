//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

// Graph coloring data structure
typedef struct Coloring {
    int num_colors;
    int *colors;
} Coloring;

// Function to allocate memory for a graph
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adj_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to free memory allocated for a graph
void free_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Function to allocate memory for a coloring
Coloring *create_coloring(int num_vertices) {
    Coloring *coloring = malloc(sizeof(Coloring));
    coloring->num_colors = 0;
    coloring->colors = malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        coloring->colors[i] = -1;
    }
    return coloring;
}

// Function to free memory allocated for a coloring
void free_coloring(Coloring *coloring) {
    free(coloring->colors);
    free(coloring);
}

// Function to check if two vertices are adjacent
int are_adjacent(Graph *graph, int vertex1, int vertex2) {
    return graph->adj_matrix[vertex1][vertex2] == 1;
}

// Function to check if a coloring is valid
int is_valid_coloring(Graph *graph, Coloring *coloring) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (are_adjacent(graph, i, j) && coloring->colors[i] == coloring->colors[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to find the minimum number of colors needed to color a graph
int find_min_colors(Graph *graph) {
    int min_colors = 1;
    while (1) {
        Coloring *coloring = create_coloring(graph->num_vertices);
        if (color_graph(graph, coloring, min_colors)) {
            free_coloring(coloring);
            return min_colors;
        }
        free_coloring(coloring);
        min_colors++;
    }
}

// Function to color a graph with a given number of colors
int color_graph(Graph *graph, Coloring *coloring, int num_colors) {
    if (coloring->num_colors == graph->num_vertices) {
        return is_valid_coloring(graph, coloring);
    }

    for (int color = 1; color <= num_colors; color++) {
        int can_color = 1;
        for (int i = 0; i < coloring->num_colors; i++) {
            if (are_adjacent(graph, coloring->num_colors, i) && coloring->colors[i] == color) {
                can_color = 0;
                break;
            }
        }
        if (can_color) {
            coloring->colors[coloring->num_colors] = color;
            coloring->num_colors++;
            if (color_graph(graph, coloring, num_colors)) {
                return 1;
            }
            coloring->num_colors--;
        }
    }

    return 0;
}

// Function to print a graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print a coloring
void print_coloring(Graph *graph, Coloring *coloring) {
    printf("Colors:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", coloring->colors[i]);
    }
    printf("\n");
}

// Function to test the graph coloring algorithm
int main() {
    // Create a graph
    Graph *graph = create_graph(4, 4);
    graph->adj_matrix[0][1] = 1;
    graph->adj_matrix[0][2] = 1;
    graph->adj_matrix[1][2] = 1;
    graph->adj_matrix[2][3] = 1;

    // Find the minimum number of colors needed to color the graph
    int min_colors = find_min_colors(graph);

    // Color the graph with the minimum number of colors
    Coloring *coloring = create_coloring(graph->num_vertices);
    color_graph(graph, coloring, min_colors);

    // Print the graph and the coloring
    printf("Graph:\n");
    print_graph(graph);
    printf("\n");
    printf("Coloring:\n");
    print_coloring(graph, coloring);
       
    
    // Free memory
    free_graph(graph);
    free_coloring(coloring);
    return 0;
}