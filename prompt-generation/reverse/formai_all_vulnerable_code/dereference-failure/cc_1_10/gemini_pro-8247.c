//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A mathematical representation of a graph
// where each vertex is represented by a complex number

// A complex number is represented by two doubles, real and imaginary
typedef struct {
    double real;
    double imaginary;
} complex;

// A graph is represented by an array of vertices
typedef struct {
    complex *vertices;
    int num_vertices;
} graph;

// Create a new graph with the given number of vertices
graph *create_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->vertices = malloc(num_vertices * sizeof(complex));
    g->num_vertices = num_vertices;
    return g;
}

// Free the memory used by the graph
void free_graph(graph *g) {
    free(g->vertices);
    free(g);
}

// Add a vertex to the graph
void add_vertex(graph *g, complex vertex) {
    g->vertices[g->num_vertices++] = vertex;
}

// Get the vertex at the given index
complex get_vertex(graph *g, int index) {
    return g->vertices[index];
}

// Set the vertex at the given index
void set_vertex(graph *g, int index, complex vertex) {
    g->vertices[index] = vertex;
}

// Print the graph to the console
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("(%f, %f)\n", g->vertices[i].real, g->vertices[i].imaginary);
    }
}

// Main function
int main() {
    // Create a new graph with 5 vertices
    graph *g = create_graph(5);

    // Add vertices to the graph
    add_vertex(g, (complex) {.real = 1, .imaginary = 2});
    add_vertex(g, (complex) {.real = 3, .imaginary = 4});
    add_vertex(g, (complex) {.real = 5, .imaginary = 6});
    add_vertex(g, (complex) {.real = 7, .imaginary = 8});
    add_vertex(g, (complex) {.real = 9, .imaginary = 10});

    // Print the graph to the console
    print_graph(g);

    // Free the memory used by the graph
    free_graph(g);

    return 0;
}