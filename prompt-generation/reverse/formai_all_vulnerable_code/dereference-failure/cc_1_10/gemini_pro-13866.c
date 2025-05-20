//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// A graph is a data structure that consists of a finite set of vertices or nodes and a set of edges or arcs that connect these vertices.
// A directed graph is a graph in which the edges have a direction, while an undirected graph is a graph in which the edges do not have a direction.
// A weighted graph is a graph in which each edge has a weight, while an unweighted graph is a graph in which all edges have the same weight.

// A graph can be represented in many different ways.
// One common way to represent a graph is to use an adjacency list.
// In an adjacency list, each vertex is represented by a node in the list, and each edge is represented by a pair of nodes in the list.

// The following code snippet shows how to represent a directed, weighted graph using an adjacency list.

// A node in the adjacency list.
struct node {
    int vertex;
    int weight;
    struct node *next;
};

// A graph represented as an adjacency list.
struct graph {
    int num_vertices;
    struct node **adj_lists;
};

// Create a new graph.
struct graph *create_graph(int num_vertices) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->adj_lists = malloc(sizeof(struct node *) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph.
void add_edge(struct graph *graph, int src, int dest, int weight) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->vertex = dest;
    new_node->weight = weight;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
}

// Print the graph.
void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct node *curr = graph->adj_lists[i];
        printf("Vertex %d: ", i);
        while (curr != NULL) {
            printf("(%d, %d) ", curr->vertex, curr->weight);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    struct graph *graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 1, 3, 40);
    add_edge(graph, 2, 3, 50);
    add_edge(graph, 3, 4, 60);
    add_edge(graph, 4, 0, 70);

    print_graph(graph);

    return 0;
}