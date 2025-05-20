//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a vertex in the graph
typedef struct vertex {
    int data;
    int edges[10]; // An array of edges connected to this vertex
} vertex_t;

// Define a struct to represent the entire graph
typedef struct graph {
    vertex_t* vertices; // An array of vertices
    int num_vertices; // The number of vertices in the graph
    int num_edges; // The number of edges in the graph
} graph_t;

// Define a function to add a new vertex to the graph
void add_vertex(graph_t* graph, int data) {
    // Allocate memory for a new vertex
    vertex_t* new_vertex = malloc(sizeof(vertex_t));
    
    // Initialize the new vertex
    new_vertex->data = data;
    
    // Add the new vertex to the list of vertices in the graph
    graph->vertices = realloc(graph->vertices, (graph->num_vertices + 1) * sizeof(vertex_t));
    graph->vertices[graph->num_vertices] = *new_vertex;
    
    // Increment the number of vertices in the graph
    graph->num_vertices++;
}

// Define a function to add an edge between two vertices
void add_edge(graph_t* graph, int from, int to) {
    // Check if the from vertex exists
    if (from >= graph->num_vertices || to >= graph->num_vertices) {
        fprintf(stderr, "Error: Invalid vertex index\n");
        return;
    }
    
    // Check if the to vertex already has an edge to the from vertex
    if (graph->vertices[to].edges[from]!= 0) {
        fprintf(stderr, "Error: Duplicate edge\n");
        return;
    }
    
    // Add the edge to the to vertex's list of edges
    graph->vertices[to].edges[from] = 1;
    
    // Increment the number of edges in the graph
    graph->num_edges++;
}

// Define a function to print the graph
void print_graph(graph_t* graph) {
    printf("Graph:\n");
    
    // Print each vertex and its connected edges
    for (int i = 0; i < graph->num_vertices; i++) {
        vertex_t* vertex = &(graph->vertices[i]);
        printf("Vertex %d: %d\n", i, vertex->data);
        
        for (int j = 0; j < 10; j++) {
            if (vertex->edges[j]!= 0) {
                printf("  --> Edge to vertex %d\n", j);
            }
        }
    }
}

int main() {
    // Create a new graph
    graph_t graph;
    graph.num_vertices = 0;
    graph.num_edges = 0;
    
    // Add some vertices to the graph
    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);
    add_vertex(&graph, 4);
    add_vertex(&graph, 5);
    add_vertex(&graph, 6);
    add_vertex(&graph, 7);
    add_vertex(&graph, 8);
    add_vertex(&graph, 9);
    add_vertex(&graph, 10);
    
    // Add some edges to the graph
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 4);
    add_edge(&graph, 3, 5);
    add_edge(&graph, 3, 6);
    add_edge(&graph, 4, 7);
    add_edge(&graph, 4, 8);
    add_edge(&graph, 5, 9);
    add_edge(&graph, 5, 10);
    add_edge(&graph, 6, 7);
    add_edge(&graph, 7, 8);
    add_edge(&graph, 8, 9);
    add_edge(&graph, 9, 10);
    
    // Print the graph
    printf("Graph:\n");
    print_graph(&graph);
    
    return 0;
}