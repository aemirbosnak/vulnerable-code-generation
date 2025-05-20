//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a vertex in the graph
struct vertex {
    int vertex_id;
    struct vertex *next;
};

// Define a struct to represent the graph
struct graph {
    int num_vertices;
    struct vertex *vertices;
};

// Define a function to create a new vertex
struct vertex *new_vertex(int id) {
    struct vertex *vertex = (struct vertex *)malloc(sizeof(struct vertex));
    vertex->vertex_id = id;
    vertex->next = NULL;
    return vertex;
}

// Define a function to create a new graph
struct graph *new_graph(int num_vertices) {
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->vertices = NULL;
    return graph;
}

// Define a function to add a new edge to the graph
void add_edge(struct graph *graph, int source, int target) {
    struct vertex *source_vertex = graph->vertices;
    struct vertex *target_vertex = graph->vertices;
    while (source_vertex->vertex_id!= source && source_vertex->next!= NULL) {
        source_vertex = source_vertex->next;
    }
    while (target_vertex->vertex_id!= target && target_vertex->next!= NULL) {
        target_vertex = target_vertex->next;
    }
    if (source_vertex->vertex_id == source && target_vertex->vertex_id == target) {
        printf("Error: Duplicate edge detected!\n");
    } else {
        struct vertex *new_edge = new_vertex(target);
        source_vertex->next = new_edge;
        target_vertex->next = new_edge;
    }
}

// Define a function to print the graph
void print_graph(struct graph *graph) {
    struct vertex *vertex = graph->vertices;
    while (vertex!= NULL) {
        printf("%d -> ", vertex->vertex_id);
        vertex = vertex->next;
    }
    printf("\n");
}

int main() {
    struct graph *graph = new_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    printf("Vertices: ");
    print_graph(graph);
    printf("\n");
    return 0;
}