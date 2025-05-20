//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    int size;
    Point *vertices;
} Graph;

Graph createGraph() {
    Graph graph;
    graph.size = 0;
    graph.vertices = NULL;
    return graph;
}

void addVertex(Graph *graph, int row, int col) {
    if (graph->size == MAX_ROWS) {
        printf("Graph is full\n");
        return;
    }
    Point *vertex = (Point *)malloc(sizeof(Point));
    vertex->row = row;
    vertex->col = col;
    graph->vertices = (Point *)realloc(graph->vertices, (graph->size + 1) * sizeof(Point));
    graph->vertices[graph->size++] = *vertex;
    printf("Vertex (%d, %d) added\n", vertex->row, vertex->col);
}

void addEdge(Graph *graph, int from, int to) {
    if (from >= graph->size || to >= graph->size) {
        printf("Invalid vertex index\n");
        return;
    }
    graph->vertices[from].row = to;
    graph->vertices[from].col = to;
    printf("Edge (%d, %d) -> (%d, %d) added\n", graph->vertices[from].row, graph->vertices[from].col, from, to);
}

void printGraph(Graph *graph) {
    if (graph->size == 0) {
        printf("Graph is empty\n");
        return;
    }
    for (int i = 0; i < graph->size; i++) {
        printf("%d: (%d, %d)\n", i, graph->vertices[i].row, graph->vertices[i].col);
    }
}

int main() {
    Graph graph = createGraph();
    addVertex(&graph, 0, 0);
    addVertex(&graph, 1, 1);
    addVertex(&graph, 2, 2);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    printGraph(&graph);
    return 0;
}