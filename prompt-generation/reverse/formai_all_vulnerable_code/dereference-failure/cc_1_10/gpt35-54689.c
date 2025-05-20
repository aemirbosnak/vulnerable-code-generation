//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/* Define structures for graph vertices and edges */
struct vertex {
    int value;
    struct edge *edge_list; // pointer to first edge in linked list
};

struct edge {
    int weight;
    struct vertex *dest; // pointer to destination vertex
    struct edge *next; // pointer to next edge in linked list
};

/* Function to create a new vertex with specified value */
struct vertex* create_vertex(int value) {
    struct vertex *new_vertex = (struct vertex*) malloc(sizeof(struct vertex));
    new_vertex->value = value;
    new_vertex->edge_list = NULL;
    return new_vertex;
}

/* Function to add a new edge to a vertex's linked list */
void add_edge(struct vertex *v, int weight, struct vertex *dest) {
    struct edge *new_edge = (struct edge*) malloc(sizeof(struct edge));
    new_edge->weight = weight;
    new_edge->dest = dest;
    new_edge->next = v->edge_list;
    v->edge_list = new_edge;
}

/* Function to print the adjacency list representation of a graph */
void print_graph(struct vertex **graph, int num_vertices) {
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: ", graph[i]->value);
        struct edge *curr_edge = graph[i]->edge_list;
        while (curr_edge != NULL) {
            printf("(%d, %d) ", curr_edge->dest->value, curr_edge->weight);
            curr_edge = curr_edge->next;
        }
        printf("\n");
    }
}

/* Main function to create and print a sample graph */
int main() {
    /* Initialize four vertices {0, 1, 2, 3}, and add edges */
    struct vertex *vertex0 = create_vertex(0);
    struct vertex *vertex1 = create_vertex(1);
    struct vertex *vertex2 = create_vertex(2);
    struct vertex *vertex3 = create_vertex(3);
    add_edge(vertex0, 5, vertex1);
    add_edge(vertex0, 3, vertex2);
    add_edge(vertex1, 2, vertex3);
    add_edge(vertex2, 4, vertex3);

    struct vertex *graph[] = {vertex0, vertex1, vertex2, vertex3};
    print_graph(graph, 4);

    return 0;
}