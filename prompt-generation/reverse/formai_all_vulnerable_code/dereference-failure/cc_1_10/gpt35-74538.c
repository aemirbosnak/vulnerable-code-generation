//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int vertices[MAX_VERTICES];
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int n;
} graph_t;

graph_t* create_graph(int n) {
    graph_t* graph = malloc(sizeof(graph_t));
    graph->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(graph_t* graph, int v1, int v2) {
    graph->matrix[v1][v2] = 1;
    graph->matrix[v2][v1] = 1;
}

void print_graph(graph_t* graph) {
    printf("Adjacency Matrix:\n");
    printf("\t");
    for (int i = 0; i < graph->n; i++) {
        printf("%d\t", graph->vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->n; i++) {
        printf("%d\t", graph->vertices[i]);
        for (int j = 0; j < graph->n; j++) {
            printf("%d\t", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t* graph = create_graph(5);
    graph->vertices[0] = 1;
    graph->vertices[1] = 2;
    graph->vertices[2] = 3;
    graph->vertices[3] = 4;
    graph->vertices[4] = 5;
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    free(graph);
    return 0;
}