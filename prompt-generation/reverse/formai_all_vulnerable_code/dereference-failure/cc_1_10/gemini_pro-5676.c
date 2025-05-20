//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// A graph is a data structure that represents a set of vertices and
// edges. A vertex is a node in the graph, and an edge is a connection
// between two vertices.

// A graph can be represented in many different ways, but one common
// representation is the adjacency list. In an adjacency list, each vertex
// is represented by a linked list of the edges that are connected to it.

// The following program creates a graph using the adjacency list
// representation. The graph consists of 5 vertices and 6 edges.

// The first step is to define the structure of a vertex. A vertex
// consists of a name and a pointer to the first edge in the adjacency list.

typedef struct vertex {
    char *name;
    struct edge *first_edge;
} vertex;

// Next, we define the structure of an edge. An edge consists of a
// pointer to the destination vertex and a weight. The weight represents
// the cost of traversing the edge.

typedef struct edge {
    vertex *destination;
    int weight;
    struct edge *next_edge;
} edge;

// The following function creates a new vertex with the given name.

vertex *create_vertex(char *name) {
    vertex *new_vertex = malloc(sizeof(vertex));
    new_vertex->name = name;
    new_vertex->first_edge = NULL;
    return new_vertex;
}

// The following function creates a new edge with the given destination
// and weight.

edge *create_edge(vertex *destination, int weight) {
    edge *new_edge = malloc(sizeof(edge));
    new_edge->destination = destination;
    new_edge->weight = weight;
    new_edge->next_edge = NULL;
    return new_edge;
}

// The following function adds an edge to the adjacency list of the given
// vertex.

void add_edge(vertex *vertex, edge *edge) {
    edge->next_edge = vertex->first_edge;
    vertex->first_edge = edge;
}

// The following function prints the graph to the console.

void print_graph(vertex *vertices[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("%s: ", vertices[i]->name);
        for (edge *edge = vertices[i]->first_edge; edge != NULL; edge = edge->next_edge) {
            printf("%s (%d), ", edge->destination->name, edge->weight);
        }
        printf("\n");
    }
}

// The following function is the main function of the program. It creates
// a graph, adds some vertices and edges to it, and then prints the graph
// to the console.

int main() {
    // Create the vertices.
    vertex *vertices[] = {
        create_vertex("A"),
        create_vertex("B"),
        create_vertex("C"),
        create_vertex("D"),
        create_vertex("E")
    };

    // Create the edges.
    edge *edges[] = {
        create_edge(vertices[1], 1),
        create_edge(vertices[2], 2),
        create_edge(vertices[3], 3),
        create_edge(vertices[4], 4),
        create_edge(vertices[2], 5),
        create_edge(vertices[3], 6)
    };

    // Add the edges to the graph.
    for (int i = 0; i < 6; i++) {
        add_edge(vertices[i / 2], edges[i]);
    }

    // Print the graph to the console.
    print_graph(vertices, 5);

    return 0;
}