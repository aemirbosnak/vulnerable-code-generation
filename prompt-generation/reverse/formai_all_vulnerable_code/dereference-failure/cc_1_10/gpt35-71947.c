//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Structure for representing a vertex
typedef struct Vertex {
    int id;   // Vertex ID
    int *edges;  // Array of connected edges
    int n_edges; // Number of connected edges
} Vertex;

// Adds an edge between two vertices
void add_edge(Vertex *v1, Vertex *v2) {
    v1->n_edges++;
    v1->edges = realloc(v1->edges, v1->n_edges * sizeof(int));
    v1->edges[v1->n_edges-1] = v2->id;
    
    v2->n_edges++;
    v2->edges = realloc(v2->edges, v2->n_edges * sizeof(int));
    v2->edges[v2->n_edges-1] = v1->id;
}

// Prints the graph in an adjacency list representation
void print_graph(Vertex **vertices, int n_vertices) {
    printf("Graph Representation:\n");
    for(int i=0; i<n_vertices; i++) {
        printf("%d -> ", vertices[i]->id);
        for(int j=0; j<vertices[i]->n_edges; j++) {
            printf("%d ", vertices[i]->edges[j]);
        }
        printf("\n");
    }
}

int main() {
    // Create vertices
    Vertex *v1 = malloc(sizeof(Vertex));
    v1->id = 1;
    v1->edges = NULL;
    v1->n_edges = 0;
    
    Vertex *v2 = malloc(sizeof(Vertex));
    v2->id = 2;
    v2->edges = NULL;
    v2->n_edges = 0;
    
    Vertex *v3 = malloc(sizeof(Vertex));
    v3->id = 3;
    v3->edges = NULL;
    v3->n_edges = 0;
    
    // Add edges between vertices
    add_edge(v1, v2);
    add_edge(v1, v3);
    add_edge(v2, v3);
    
    // Create an array of vertices
    Vertex **vertices = malloc(3 * sizeof(Vertex*));
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    
    // Print the graph
    print_graph(vertices, 3);
    
    // Free allocated memory
    for(int i=0; i<3; i++) {
        free(vertices[i]->edges);
        free(vertices[i]);
    }
    free(vertices);
    
    return 0;
}