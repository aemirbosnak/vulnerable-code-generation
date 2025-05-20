//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A graph is a data structure that consists of a set of vertices and a set of edges that connect the vertices.
// In this example, we will represent a graph as an adjacency list.
// An adjacency list is an array of linked lists, where each linked list represents the set of vertices that are adjacent to a particular vertex.

// A vertex is a node in a graph.
// In this example, we will represent a vertex as an integer.

// An edge is a connection between two vertices.
// In this example, we will represent an edge as a pair of integers, where the first integer is the source vertex and the second integer is the destination vertex.

// A graph can be represented as an array of adjacency lists.
// Each entry in the array represents a vertex in the graph.
// The adjacency list for a vertex contains the set of vertices that are adjacent to that vertex.

// A linked list is a data structure that consists of a set of nodes.
// Each node in a linked list contains a value and a pointer to the next node in the list.

// A node in a linked list is represented by the following structure:

typedef struct node {
    int value;
    struct node *next;
} node;

// An adjacency list is represented by a linked list of nodes.
// Each node in the linked list represents a vertex that is adjacent to the vertex that the adjacency list represents.

typedef struct adjacency_list {
    node *head;
} adjacency_list;

// A graph is represented by an array of adjacency lists.
// Each entry in the array represents a vertex in the graph.
// The adjacency list for a vertex contains the set of vertices that are adjacent to that vertex.

typedef struct graph {
    int num_vertices;
    adjacency_list *adjacency_lists;
} graph;

// Create a new graph with the specified number of vertices.

graph *create_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adjacency_lists = malloc(sizeof(adjacency_list) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_lists[i].head = NULL;
    }
    return g;
}

// Add an edge to the graph.

void add_edge(graph *g, int source, int destination) {
    node *new_node = malloc(sizeof(node));
    new_node->value = destination;
    new_node->next = g->adjacency_lists[source].head;
    g->adjacency_lists[source].head = new_node;
}

// Print the graph.

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *current = g->adjacency_lists[i].head;
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Free the memory that is used by the graph.

void free_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *current = g->adjacency_lists[i].head;
        while (current != NULL) {
            node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(g->adjacency_lists);
    free(g);
}

// Main function.

int main() {
    // Create a new graph with 5 vertices.

    graph *g = create_graph(5);

    // Add some edges to the graph.

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);

    // Print the graph.

    print_graph(g);

    // Free the memory that is used by the graph.

    free_graph(g);

    return 0;
}