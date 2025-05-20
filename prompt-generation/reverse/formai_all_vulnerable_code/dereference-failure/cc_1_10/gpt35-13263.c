//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define the struct for a vertex in the graph
typedef struct Vertex {
    int id;
    struct Edge* edges;
    struct Vertex* next;
} Vertex;

// Define the struct for an edge in the graph
typedef struct Edge {
    int weight;
    struct Vertex* destination;
    struct Edge* next;
} Edge;

// Add a vertex to the graph
void add_vertex(Vertex** graph, int id) {
    Vertex* new_vertex = malloc(sizeof(Vertex));
    new_vertex->id = id;
    new_vertex->edges = NULL;
    new_vertex->next = *graph;
    *graph = new_vertex;
}

// Add an edge to the vertex in the graph
void add_edge(Vertex* v, Vertex* destination, int weight) {
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->destination = destination;
    new_edge->weight = weight;
    new_edge->next = v->edges;
    v->edges = new_edge;
}

// Print the graph
void print_graph(Vertex* graph) {
    Vertex* current_vertex = graph;
    printf("Vertices: ");
    while (current_vertex != NULL) {
        printf("%d ", current_vertex->id);
        Edge* current_edge = current_vertex->edges;
        while (current_edge != NULL) {
            printf("(%d) %d -> %d ", current_edge->weight, current_vertex->id, current_edge->destination->id);
            current_edge = current_edge->next;
        }
        printf("\n");
        current_vertex = current_vertex->next;
    }
}

// Main function to create and print a graph
int main() {
    Vertex* graph = NULL;

    // Add some vertices to the graph
    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);
    add_vertex(&graph, 4);
    add_vertex(&graph, 5);

    // Add some edges to the vertices
    add_edge(graph, graph->next, 6);
    add_edge(graph, graph->next->next, 3);
    add_edge(graph->next, graph->next->next, 2);
    add_edge(graph->next, graph->next->next->next, 7);
    add_edge(graph->next->next, graph->next->next->next, 1);
    add_edge(graph->next->next, graph->next->next->next->next, 8);
    add_edge(graph->next->next->next, graph->next->next->next->next, 5);

    // Print the graph
    print_graph(graph);

    return 0;
}