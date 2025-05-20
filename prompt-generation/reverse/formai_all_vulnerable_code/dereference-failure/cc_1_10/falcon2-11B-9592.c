//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct graph {
    int **adjacency_list;
    int num_vertices;
    int num_edges;
};

struct graph* create_graph(int vertices, int edges) {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->adjacency_list = (int **)malloc(vertices * sizeof(int*));
    graph->num_vertices = vertices;
    graph->num_edges = edges;
    return graph;
}

int add_edge(struct graph *graph, int source, int dest) {
    if (source < graph->num_vertices && dest < graph->num_vertices) {
        graph->adjacency_list[source] = (int*)realloc(graph->adjacency_list[source], (graph->num_vertices+1)*sizeof(int));
        graph->adjacency_list[source][graph->num_edges] = dest;
        graph->num_edges++;
    }
    return graph->num_edges;
}

void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            printf("%d ", graph->adjacency_list[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 5;
    int num_edges = 6;
    struct graph* graph = create_graph(num_vertices, num_edges);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    print_graph(graph);

    free(graph->adjacency_list);
    free(graph);

    return 0;
}