//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
/*
 ** Graph Coloring Problem **
 ** C Programming Language **
 ** Retro Style **
 */

/*
 ** Includes **
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 ** Defines **
 */
#define MAX_VERTICES 100
#define NO_COLOR 0

/*
 ** Types **
 */
typedef struct {
    int num_vertices;
    int num_edges;
    int **edges;
    int *colors;
} Graph;

/*
 ** Functions **
 */

/*
 ** Function: is_safe
 ** ----------------------------------------------------------------------
 ** Checks if it is safe to color a given vertex with a given color.
 */
static bool is_safe(const Graph *graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->edges[vertex][i] && graph->colors[i] == color) {
            return false;
        }
    }
    return true;
}

/*
 ** Function: graph_coloring
 ** ----------------------------------------------------------------------
 ** Solves the graph coloring problem using backtracking.
 */
static bool graph_coloring(Graph *graph, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= graph->num_vertices; color++) {
        if (is_safe(graph, vertex, color)) {
            graph->colors[vertex] = color;
            if (graph_coloring(graph, vertex + 1)) {
                return true;
            }
            graph->colors[vertex] = NO_COLOR;
        }
    }

    return false;
}

/*
 ** Function: main
 ** ----------------------------------------------------------------------
 ** Entry point of the program.
 */
int main() {
    /*
     ** Variables **
     */
    Graph graph;
    int num_vertices, num_edges;
    int i, j;

    /*
     ** Input **
     */
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    graph.num_vertices = num_vertices;
    graph.num_edges = num_edges;
    graph.edges = (int **)malloc(sizeof(int *) * num_vertices);
    for (i = 0; i < num_vertices; i++) {
        graph.edges[i] = (int *)malloc(sizeof(int) * num_vertices);
    }
    graph.colors = (int *)malloc(sizeof(int) * num_vertices);

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph.edges[i][j] = 0;
        }
        graph.colors[i] = NO_COLOR;
    }

    printf("Enter the edges:\n");
    for (i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph.edges[vertex1 - 1][vertex2 - 1] = 1;
        graph.edges[vertex2 - 1][vertex1 - 1] = 1;
    }

    /*
     ** Solve the problem **
     */
    bool result = graph_coloring(&graph, 0);

    /*
     ** Output **
     */
    if (result) {
        printf("The graph can be colored with %d colors.\n", graph.colors[graph.num_vertices - 1]);
        for (i = 0; i < graph.num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, graph.colors[i]);
        }
    } else {
        printf("The graph cannot be colored.\n");
    }

    return 0;
}