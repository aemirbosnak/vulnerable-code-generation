//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Graph
{
    int **adj;
    int **visited;
    int numVertices;
} Graph;

Graph* graphCreate(int numVertices)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = numVertices;
    g->adj = (int**)malloc(numVertices * sizeof(int*));
    g->visited = (int**)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        g->adj[i] = (int*)malloc(numVertices * sizeof(int));
        g->visited[i] = 0;
    }
    return g;
}

void graphAddEdge(Graph* g, int u, int v)
{
    g->adj[u][v] = 1;
}

void dfs(Graph* g, int current)
{
    g->visited[current] = 1;
    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->adj[current][i] && !g->visited[i])
        {
            dfs(g, i);
        }
    }
}

int main()
{
    Graph* g = graphCreate(5);
    graphAddEdge(g, 0, 1);
    graphAddEdge(g, 0, 2);
    graphAddEdge(g, 1, 2);
    graphAddEdge(g, 1, 3);
    graphAddEdge(g, 2, 4);

    dfs(g, 0);

    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->visited[i] == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}