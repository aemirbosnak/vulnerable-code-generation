//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct {
    int num_vertices;
    int *edges;
} graph_t;

// Graph creation function
graph_t* create_graph(int num_vertices) {
    graph_t* g = (graph_t*)malloc(sizeof(graph_t));
    g->num_vertices = num_vertices;
    g->edges = (int*)malloc(num_vertices * sizeof(int));
    return g;
}

// Graph vertex structure definition
typedef struct {
    int label;
    int neighbors[5];
} vertex_t;

// Vertex creation function
vertex_t* create_vertex(int label) {
    vertex_t* v = (vertex_t*)malloc(sizeof(vertex_t));
    v->label = label;
    v->neighbors[0] = -1;
    return v;
}

// Graph traversal function
void traverse_graph(graph_t* g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        vertex_t* v = g->edges[i];
        printf("%d -> ", v->label);
        for (j = 0; j < 5; j++) {
            if (v->neighbors[j] != -1) {
                traverse_graph(g->edges[v->neighbors[j]]);
            }
        }
        printf("\n");
    }
}

int main() {
    graph_t* g = create_graph(8);
    vertex_t* v1 = create_vertex(1);
    vertex_t* v2 = create_vertex(2);
    vertex_t* v3 = create_vertex(3);
    vertex_t* v4 = create_vertex(4);
    vertex_t* v5 = create_vertex(5);

    g->edges[0] = v1;
    g->edges[1] = v2;
    g->edges[2] = v3;
    g->edges[3] = v4;
    g->edges[4] = v5;

    traverse_graph(g);

    return 0;
}