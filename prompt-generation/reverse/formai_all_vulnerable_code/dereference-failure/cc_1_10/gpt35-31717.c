//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct edge
{
    int u, v, w;
};

struct graph
{
    int v, e;
    struct edge *edges;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int root_x = find(subsets, x);
    int root_y = find(subsets, y);

    if (subsets[root_x].rank < subsets[root_y].rank)
        subsets[root_x].parent = root_y;
    else if (subsets[root_x].rank > subsets[root_y].rank)
        subsets[root_y].parent = root_x;
    else
    {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

int compare(const void *a, const void *b)
{
    struct edge *edge_a = (struct edge*)a;
    struct edge *edge_b = (struct edge*)b;

    if (edge_a->w < edge_b->w)
        return -1;
    else if (edge_a->w > edge_b->w)
        return 1;
    else
        return 0;
}

void createGraph(struct graph* graph, int v, int e)
{
    graph->v = v;
    graph->e = e;

    graph->edges = (struct edge*)malloc(e * sizeof(struct edge));
}

void kruskalMST(struct graph* graph)
{
    int V = graph->v;
    struct edge result[V - 1];
    int i = 0;
    int e = 0;

    qsort(graph->edges, graph->e, sizeof(struct edge), compare);

    struct subset subsets[V];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->e)
    {
        struct edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].w);

    return;
}

int main()
{
    int v = 6;
    int e = 8;
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));

    createGraph(graph, v, e);

    graph->edges[0].u = 0;
    graph->edges[0].v = 1;
    graph->edges[0].w = 4;

    graph->edges[1].u = 0;
    graph->edges[1].v = 2;
    graph->edges[1].w = 4;

    graph->edges[2].u = 1;
    graph->edges[2].v = 2;
    graph->edges[2].w = 2;

    graph->edges[3].u = 2;
    graph->edges[3].v = 3;
    graph->edges[3].w = 3;

    graph->edges[4].u = 3;
    graph->edges[4].v = 4;
    graph->edges[4].w = 2;

    graph->edges[5].u = 4;
    graph->edges[5].v = 5;
    graph->edges[5].w = 5;

    graph->edges[6].u = 3;
    graph->edges[6].v = 5;
    graph->edges[6].w = 6;

    graph->edges[7].u = 2;
    graph->edges[7].v = 4;
    graph->edges[7].w = 1;

    kruskalMST(graph);

    return 0;
}