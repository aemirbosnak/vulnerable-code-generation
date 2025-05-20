//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// A happy Graph Coloring Problem solver!

// A graph is represented as an adjacency list. Each node is represented by an index in the adjacency list, and each edge is represented by a pair of indices in the adjacency list.
typedef struct Graph {
    int num_nodes;
    int num_edges;
    int** adjacency_list;
} Graph;

// A coloring of a graph is represented as an array of colors, where each color is an index in the color array.
typedef struct Coloring {
    int num_colors;
    int* color_array;
} Coloring;

// Creates a new graph with the given number of nodes and edges.
Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adjacency_list = malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adjacency_list[i] = malloc(sizeof(int) * num_nodes);
    }
    return graph;
}

// Creates a new coloring with the given number of colors.
Coloring* create_coloring(int num_colors) {
    Coloring* coloring = malloc(sizeof(Coloring));
    coloring->num_colors = num_colors;
    coloring->color_array = malloc(sizeof(int) * num_colors);
    return coloring;
}

// Adds an edge to the graph.
void add_edge(Graph* graph, int node1, int node2) {
    graph->adjacency_list[node1][node2] = 1;
    graph->adjacency_list[node2][node1] = 1;
}

// Colors the graph with the given coloring.
void color_graph(Graph* graph, Coloring* coloring) {
    for (int i = 0; i < graph->num_nodes; i++) {
        coloring->color_array[i] = rand() % coloring->num_colors;
    }
}

// Checks if the coloring is valid.
int is_valid_coloring(Graph* graph, Coloring* coloring) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            if (graph->adjacency_list[i][j] == 1 && coloring->color_array[i] == coloring->color_array[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Prints the graph.
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adjacency_list[i][j]);
        }
        printf("\n");
    }
}

// Prints the coloring.
void print_coloring(Coloring* coloring) {
    for (int i = 0; i < coloring->num_colors; i++) {
        printf("%d ", coloring->color_array[i]);
    }
    printf("\n");
}

// Solves the Graph Coloring Problem.
Coloring* solve_graph_coloring_problem(Graph* graph) {
    // Try all possible colorings.
    for (int num_colors = 1; num_colors <= graph->num_nodes; num_colors++) {
        Coloring* coloring = create_coloring(num_colors);
        color_graph(graph, coloring);
        if (is_valid_coloring(graph, coloring)) {
            return coloring;
        }
        free(coloring);
    }

    // No valid coloring was found.
    return NULL;
}

// Frees the memory allocated for the graph.
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adjacency_list[i]);
    }
    free(graph->adjacency_list);
    free(graph);
}

// Frees the memory allocated for the coloring.
void free_coloring(Coloring* coloring) {
    free(coloring->color_array);
    free(coloring);
}

int main() {
    // Create a graph.
    Graph* graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    print_graph(graph);

    // Solve the Graph Coloring Problem.
    Coloring* coloring = solve_graph_coloring_problem(graph);
    print_coloring(coloring);

    // Free the memory allocated for the graph and the coloring.
    free_graph(graph);
    free_coloring(coloring);

    return 0;
}