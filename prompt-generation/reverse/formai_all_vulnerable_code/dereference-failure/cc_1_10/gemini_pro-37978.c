//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
// Linus Torvalds style C Graph representation example

#include <stdio.h>
#include <stdlib.h>

// A graph is a data structure that consists of a set of vertices and a set of edges that connect the vertices.
// Each edge has a weight, which represents the cost of traversing the edge.

// A graph can be represented in various ways, one of the most common ways is the adjacency list representation.
// In an adjacency list representation, each vertex is represented by a node in a linked list.
// Each node contains a list of edges that connect the vertex to other vertices.

// The following C program implements an adjacency list representation of a graph:

// A node in the adjacency list
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} node_t;

// A graph is a collection of nodes
typedef struct graph {
    int num_vertices;
    node_t **adj_list;
} graph_t;

// Create a new graph with the specified number of vertices
graph_t *create_graph(int num_vertices) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->adj_list = (node_t **)malloc(sizeof(node_t *) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void add_edge(graph_t *graph, int src, int dest, int weight) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->vertex = dest;
    new_node->weight = weight;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

// Print the graph
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *temp = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("(%d, %d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *temp = graph->adj_list[i];
        while (temp) {
            node_t *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adj_list);
    free(graph);
}

// Driver program to test the graph representation
int main() {
    // Create a graph with 5 vertices
    graph_t *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 1, 3, 40);
    add_edge(graph, 2, 3, 50);
    add_edge(graph, 3, 4, 60);
    add_edge(graph, 4, 0, 70);

    // Print the graph
    print_graph(graph);

    // Free the graph
    free_graph(graph);

    return 0;
}