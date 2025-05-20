//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 10
#define MAX_COLOR 10

typedef struct {
    int vertex;
    int color;
} Vertex;

typedef struct {
    int vertex;
    int color;
    struct Graph *graph;
} GraphVertex;

typedef struct {
    GraphVertex *vertex;
    int size;
} Graph;

void createGraph(Graph *graph, int vertex) {
    graph->size = vertex;
    graph->vertex = (GraphVertex *) malloc(vertex * sizeof(GraphVertex));
    for (int i = 0; i < vertex; i++) {
        graph->vertex[i].vertex = i;
        graph->vertex[i].color = -1;
        graph->vertex[i].graph = graph;
    }
}

int isValid(Graph *graph, int vertex, int color) {
    for (int i = 0; i < vertex; i++) {
        if (graph->vertex[i].color == color || graph->vertex[i].color == -color) {
            return 0;
        }
    }
    return 1;
}

void colorVertex(Graph *graph, int vertex, int color) {
    graph->vertex[vertex].color = color;
}

int main() {
    int vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);

    Graph graph;
    createGraph(&graph, vertex);

    srand(time(NULL));
    for (int i = 0; i < vertex; i++) {
        int color = rand() % MAX_COLOR;
        while (!isValid(&graph, i, color)) {
            color = rand() % MAX_COLOR;
        }
        colorVertex(&graph, i, color);
    }

    printf("\nVertex\tColor\n");
    for (int i = 0; i < vertex; i++) {
        printf("%d\t%d\n", graph.vertex[i].vertex, graph.vertex[i].color);
    }

    return 0;
}