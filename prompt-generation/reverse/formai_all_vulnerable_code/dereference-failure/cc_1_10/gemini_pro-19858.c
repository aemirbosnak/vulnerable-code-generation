//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the number of colors and vertices
#define NUM_COLORS 4
#define NUM_VERTICES 5

// Define the graph as an adjacency matrix
int graph[NUM_VERTICES][NUM_VERTICES] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

// Define the colors as an array of strings
char *colors[NUM_COLORS] = {"Red", "Blue", "Green", "Yellow"};

// Function to check if a vertex is safe to color with a given color
int is_safe(int vertex, int color, int *colors) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to color the graph using backtracking
int color_graph(int vertex, int *colors) {
    // If all vertices have been colored, then return true
    if (vertex == NUM_VERTICES) {
        return 1;
    }

    // Try all colors for the current vertex
    for (int i = 0; i < NUM_COLORS; i++) {
        // If the color is safe, then assign it to the vertex and recursively color the remaining vertices
        if (is_safe(vertex, i, colors)) {
            colors[vertex] = i;
            if (color_graph(vertex + 1, colors)) {
                return 1;
            }
            // If the recursive call fails, then reset the color of the vertex
            colors[vertex] = -1;
        }
    }

    // If no color is safe for the current vertex, then return false
    return 0;
}

// Function to print the colored graph
void print_colored_graph(int *colors) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("%d\t%s\n", i, colors[i] == -1 ? "None" : colors[colors[i]]);
    }
}

int main() {
    // Initialize the colors array to -1
    int *colors = malloc(NUM_VERTICES * sizeof(int));
    for (int i = 0; i < NUM_VERTICES; i++) {
        colors[i] = -1;
    }

    // Color the graph using backtracking
    if (color_graph(0, colors)) {
        // Print the colored graph
        print_colored_graph(colors);
    } else {
        printf("The graph cannot be colored with %d colors.\n", NUM_COLORS);
    }

    // Free the memory allocated for the colors array
    free(colors);

    return 0;
}