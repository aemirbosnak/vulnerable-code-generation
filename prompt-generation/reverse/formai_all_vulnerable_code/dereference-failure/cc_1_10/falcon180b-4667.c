//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 1000
#define MAX_EDGE_NUM 10000

typedef struct {
    int vertex_num;
    int edge_num;
    int *vertex_list;
    int **edge_list;
} Graph;

Graph *create_graph() {
    Graph *g = malloc(sizeof(Graph));
    g->vertex_num = 0;
    g->edge_num = 0;
    g->vertex_list = NULL;
    g->edge_list = NULL;
    return g;
}

void free_graph(Graph *g) {
    free(g->vertex_list);
    for (int i = 0; i < g->edge_num; i++) {
        free(g->edge_list[i]);
    }
    free(g->edge_list);
    free(g);
}

void add_vertex(Graph *g, int v) {
    g->vertex_list = realloc(g->vertex_list, sizeof(int) * ++g->vertex_num);
    g->vertex_list[g->vertex_num - 1] = v;
}

void add_edge(Graph *g, int u, int v) {
    g->edge_list = realloc(g->edge_list, sizeof(int *) * ++g->edge_num);
    g->edge_list[g->edge_num - 1] = malloc(sizeof(int) * 2);
    g->edge_list[g->edge_num - 1][0] = u;
    g->edge_list[g->edge_num - 1][1] = v;
}

void print_graph(Graph *g) {
    printf("Vertex list: ");
    for (int i = 0; i < g->vertex_num; i++) {
        printf("%d ", g->vertex_list[i]);
    }
    printf("\n");

    printf("Edge list: ");
    for (int i = 0; i < g->edge_num; i++) {
        printf("(%d, %d) ", g->edge_list[i][0], g->edge_list[i][1]);
    }
    printf("\n");
}

int main() {
    Graph *g = create_graph();

    add_vertex(g, 0);
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_vertex(g, 3);
    add_vertex(g, 4);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);

    print_graph(g);

    free_graph(g);

    return 0;
}