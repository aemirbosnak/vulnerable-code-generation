//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100
#define MAXDEG 50

typedef struct {
    int v;
    int e;
    int **adj;
} Graph;

void init_graph(Graph *g, int v)
{
    int i, j;

    g->v = v;
    g->e = 0;
    g->adj = (int **)malloc(sizeof(int *) * v);
    for (i = 0; i < v; i++) {
        g->adj[i] = (int *)malloc(sizeof(int) * MAXDEG);
        for (j = 0; j < MAXDEG; j++)
            g->adj[i][j] = 0;
    }
}

void insert_edge(Graph *g, int u, int v)
{
    int i;

    for (i = 0; i < MAXDEG && g->adj[u][i] != 0; i++)
        ;
    if (i == MAXDEG) {
        fprintf(stderr, "Warning: insertion (%d,%d) ignored\n", u, v);
    } else {
        g->adj[u][i] = v;
        g->e++;
    }
}

void print_graph(Graph *g)
{
    int i, j;

    for (i = 0; i < g->v; i++) {
        printf("%d: ", i);
        for (j = 0; j < MAXDEG && g->adj[i][j] != 0; j++)
            printf(" %d", g->adj[i][j]);
        printf("\n");
    }
}

bool is_valid_color(Graph *g, int v, int color[], int c)
{
    int i;

    for (i = 0; i < MAXDEG && g->adj[v][i] != 0; i++) {
        if (color[g->adj[v][i]] == c)
            return false;
    }
    return true;
}

bool graph_color_helper(Graph *g, int color[], int v)
{
    int c;

    if (v == g->v)
        return true;

    for (c = 1; c <= g->v; c++) {
        if (is_valid_color(g, v, color, c)) {
            color[v] = c;
            if (graph_color_helper(g, color, v + 1))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

void graph_color(Graph *g)
{
    int color[MAXV];
    int i;

    for (i = 0; i < g->v; i++)
        color[i] = 0;

    if (graph_color_helper(g, color, 0)) {
        printf("Graph can be colored with the following colors:\n");
        for (i = 0; i < g->v; i++)
            printf("%d: %d\n", i, color[i]);
    } else {
        printf("Graph cannot be colored with %d colors\n", g->v);
    }
}

int main(void)
{
    Graph g;

    init_graph(&g, 5);
    insert_edge(&g, 0, 1);
    insert_edge(&g, 0, 4);
    insert_edge(&g, 1, 0);
    insert_edge(&g, 1, 2);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 1);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 3, 1);
    insert_edge(&g, 3, 2);
    insert_edge(&g, 3, 4);
    insert_edge(&g, 4, 0);
    insert_edge(&g, 4, 1);
    insert_edge(&g, 4, 3);

    printf("Graph:\n");
    print_graph(&g);

    graph_color(&g);

    return 0;
}