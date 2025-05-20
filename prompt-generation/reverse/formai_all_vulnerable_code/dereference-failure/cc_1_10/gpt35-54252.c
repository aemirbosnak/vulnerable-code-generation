//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

// A struct for a vertex in a graph
struct vertex {
    int value;
    int num_edges;
    struct vertex **edges;
};

// Function to add a new edge between two vertices
void add_edge(struct vertex *v1, struct vertex *v2) {
    v1->edges[v1->num_edges] = v2;
    v1->num_edges++;
}

int main() {
    // Create some vertices
    struct vertex *v1 = (struct vertex*)malloc(sizeof(struct vertex));
    v1->value = 1;
    v1->num_edges = 0;
    v1->edges = (struct vertex**)malloc(sizeof(struct vertex*) * 2);

    struct vertex *v2 = (struct vertex*)malloc(sizeof(struct vertex));
    v2->value = 2;
    v2->num_edges = 0;
    v2->edges = (struct vertex**)malloc(sizeof(struct vertex*) * 2);

    struct vertex *v3 = (struct vertex*)malloc(sizeof(struct vertex));
    v3->value = 3;
    v3->num_edges = 0;
    v3->edges = (struct vertex**)malloc(sizeof(struct vertex*) * 2);

    // Add edges between the vertices
    add_edge(v1, v2);
    add_edge(v1, v3);
    add_edge(v2, v3);

    // Print out the graph
    printf("Graph Representation:\n");
    printf("Vertex 1: %d -> ", v1->value);
    for (int i = 0; i < v1->num_edges; i++) {
        printf("%d ", v1->edges[i]->value);
    }
    printf("\n");

    printf("Vertex 2: %d -> ", v2->value);
    for (int i = 0; i < v2->num_edges; i++) {
        printf("%d ", v2->edges[i]->value);
    }
    printf("\n");

    printf("Vertex 3: %d -> ", v3->value);
    for (int i = 0; i < v3->num_edges; i++) {
        printf("%d ", v3->edges[i]->value);
    }
    printf("\n");

    // Free the memory allocated for the vertices and their edges
    free(v1->edges);
    free(v1);

    free(v2->edges);
    free(v2);

    free(v3->edges);
    free(v3);

    return 0;
}