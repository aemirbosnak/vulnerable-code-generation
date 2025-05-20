//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph.
#define MAX_VERTICES 100

// Define the data structure for a vertex in the graph.
typedef struct vertex {
    int data;
    struct vertex *next;
} vertex_t;

// Define the data structure for a graph.
typedef struct graph {
    int num_vertices;
    vertex_t *vertices[MAX_VERTICES];
} graph_t;

// Function to create a new graph.
graph_t *create_graph(void) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }

    graph->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = NULL;
    }

    return graph;
}

// Function to add a vertex to the graph.
int add_vertex(graph_t *graph, int data) {
    if (graph->num_vertices >= MAX_VERTICES) {
        return -1;
    }

    vertex_t *vertex = (vertex_t *)malloc(sizeof(vertex_t));
    if (vertex == NULL) {
        return -1;
    }

    vertex->data = data;
    vertex->next = NULL;

    graph->vertices[graph->num_vertices] = vertex;
    graph->num_vertices++;

    return 0;
}

// Function to add an edge to the graph.
int add_edge(graph_t *graph, int source, int destination) {
    if (source < 0 || source >= graph->num_vertices || destination < 0 || destination >= graph->num_vertices) {
        return -1;
    }

    vertex_t *vertex = graph->vertices[source];
    while (vertex != NULL) {
        if (vertex->data == destination) {
            return 0;
        }

        vertex = vertex->next;
    }

    vertex_t *new_vertex = (vertex_t *)malloc(sizeof(vertex_t));
    if (new_vertex == NULL) {
        return -1;
    }

    new_vertex->data = destination;
    new_vertex->next = graph->vertices[source];

    graph->vertices[source] = new_vertex;

    return 0;
}

// Function to print the graph.
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        vertex_t *vertex = graph->vertices[i];
        printf("%d: ", vertex->data);

        while (vertex != NULL) {
            printf("%d ", vertex->data);
            vertex = vertex->next;
        }

        printf("\n");
    }
}

// Function to free the graph.
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        vertex_t *vertex = graph->vertices[i];

        while (vertex != NULL) {
            vertex_t *next = vertex->next;
            free(vertex);
            vertex = next;
        }
    }

    free(graph);
}

int main(void) {
    // Create a new graph.
    graph_t *graph = create_graph();

    // Add vertices to the graph.
    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);

    // Add edges to the graph.
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph.
    print_graph(graph);

    // Free the graph.
    free_graph(graph);

    return 0;
}