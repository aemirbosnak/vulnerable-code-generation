//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 1000

// Define the structure for a vertex in the graph
typedef struct vertex {
    int color;
    int degree;
} vertex;

// Define the structure for a graph
typedef struct graph {
    vertex *vertices;
    int num_vertices;
    int num_edges;
} graph;

// Define the function to initialize a graph
graph* initialize_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->vertices = malloc(num_vertices * sizeof(vertex));
    for (int i = 0; i < num_vertices; i++) {
        g->vertices[i].color = 0;
        g->vertices[i].degree = 0;
    }
    return g;
}

// Define the function to add an edge to the graph
void add_edge(graph *g, int u, int v) {
    g->vertices[u].degree++;
    g->vertices[v].degree++;
    g->num_edges++;
}

// Define the function to perform graph coloring
bool graph_coloring(graph *g) {
    // Variables to keep track of the color of each vertex
    int colors[MAX_VERTICES];

    // Variable to keep track of the current color being assigned
    int current_color = 1;

    // Loop through each vertex in the graph
    for (int i = 0; i < g->num_vertices; i++) {
        // If the vertex has not been colored yet, assign it a color
        if (colors[i] == 0) {
            colors[i] = current_color;
            // Assign the vertex's degree to its color to avoid repeated colors
            g->vertices[i].color = g->vertices[i].degree;
        }
        // If the vertex has already been colored, check if it can be assigned a new color
        else if (colors[i] == g->vertices[i].degree) {
            int valid_colors = g->vertices[i].degree;
            for (int j = 0; j < valid_colors; j++) {
                if (colors[i] + 1 == j) {
                    colors[i]++;
                    g->vertices[i].color = colors[i];
                    break;
                }
            }
            // If no valid color was found, the coloring is not possible
            if (colors[i] == valid_colors) {
                return false;
            }
        }
    }
    // If all vertices were assigned colors, the coloring is possible
    return true;
}

// Define the function to print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d ", g->vertices[i].color);
    }
    printf("\n");
}

int main() {
    graph *g = initialize_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 3, 5);

    if (graph_coloring(g)) {
        printf("The graph is colorable.\n");
    } else {
        printf("The graph is not colorable.\n");
    }

    print_graph(g);

    return 0;
}