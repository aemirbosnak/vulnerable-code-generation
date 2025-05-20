//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int data;
    int visited;
} Vertex;

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void add_edge(Graph *graph, int source, int destination) {
    graph->matrix[source][destination] = 1;
    graph->matrix[destination][source] = 1;
}

void depth_first_search(Graph *graph, int vertex) {
    Vertex *vertices = malloc(graph->num_vertices * sizeof(Vertex));

    for (int i = 0; i < graph->num_vertices; ++i) {
        vertices[i].data = i;
        vertices[i].visited = 0;
    }

    vertices[vertex].visited = 1;
    printf("%d ", vertices[vertex].data);

    for (int i = 0; i < graph->num_vertices; ++i) {
        if (graph->matrix[vertex][i] && !vertices[i].visited) {
            depth_first_search(graph, i);
        }
    }

    free(vertices);
}

int main() {
    Graph graph;
    graph.num_vertices = 5;

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    printf("Depth-First Search Traversal:\n");
    depth_first_search(&graph, 0);

    return 0;
}