//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 1000
#define MAX_EDGE_NUM 10000

typedef struct {
    int vertex_num;
    int edge_num;
    int **edges;
} Graph;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex_num = 0;
    graph->edge_num = 0;
    graph->edges = (int **)malloc(MAX_VERTEX_NUM * sizeof(int *));
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        graph->edges[i] = (int *)malloc(MAX_EDGE_NUM * sizeof(int));
    }
    return graph;
}

void add_edge(Graph *graph, int vertex1, int vertex2) {
    graph->edges[vertex1][graph->edge_num] = vertex2;
    graph->edges[vertex2][graph->edge_num] = vertex1;
    graph->edge_num++;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->vertex_num; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->edge_num; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = create_graph();
    int vertex1, vertex2;

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 1);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 0);

    printf("Graph:\n");
    print_graph(graph);

    return 0;
}