//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define MAX_EDGES 8

typedef struct {
    int num_vertices;
    int **vertices;
    int **edges;
} Graph;

Graph create_graph(int num_vertices, int num_edges) {
    Graph g;
    g.num_vertices = num_vertices;
    g.vertices = (int **) malloc(sizeof(int *) * num_vertices);
    g.edges = (int **) malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g.vertices[i] = (int *) malloc(sizeof(int) * num_vertices);
        g.edges[i] = (int *) malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            g.vertices[i][j] = 0;
            g.edges[i][j] = 0;
        }
    }
    return g;
}

void print_graph(Graph g) {
    for (int i = 0; i < g.num_vertices; i++) {
        for (int j = 0; j < g.num_vertices; j++) {
            if (g.vertices[i][j] > 0) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    Graph g = create_graph(MAX_VERTICES, MAX_EDGES);
    g.vertices[0][0] = 1;
    g.vertices[0][1] = 2;
    g.vertices[0][2] = 3;
    g.vertices[0][3] = 4;
    g.vertices[0][4] = 5;
    g.vertices[1][0] = 1;
    g.vertices[1][1] = 2;
    g.vertices[1][2] = 3;
    g.vertices[1][3] = 4;
    g.vertices[1][4] = 5;
    g.vertices[2][0] = 2;
    g.vertices[2][1] = 3;
    g.vertices[2][2] = 4;
    g.vertices[2][3] = 5;
    g.vertices[2][4] = 5;
    g.vertices[3][0] = 3;
    g.vertices[3][1] = 4;
    g.vertices[3][2] = 5;
    g.vertices[3][3] = 5;
    g.vertices[3][4] = 5;
    g.vertices[4][0] = 4;
    g.vertices[4][1] = 5;
    g.vertices[4][2] = 5;
    g.vertices[4][3] = 5;
    g.vertices[4][4] = 5;
    print_graph(g);
    return 0;
}