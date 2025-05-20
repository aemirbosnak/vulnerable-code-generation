//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100
#define MAX_COLORS 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph *graphCreate()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->adjList = (int **)malloc(MAX_VERTS * sizeof(int *));
    g->numVertices = 0;
    g->numEdges = 0;
    return g;
}

void graphAddEdge(Graph *g, int u, int v)
{
    g->adjList[u] = (int *)realloc(g->adjList[u], (g->numVertices + 1) * sizeof(int));
    g->adjList[u][g->numVertices] = v;
    g->numVertices++;
    g->numEdges++;
}

void graphColor(Graph *g, int *colors)
{
    int i, j, k, color, usedColors[MAX_COLORS] = {0};
    for (i = 0; i < g->numVertices; i++)
    {
        usedColors[colors[i]] = 1;
        for (j = 0; j < g->numVertices; j++)
        {
            if (i != j && g->adjList[i][j] && usedColors[colors[j]] == 1)
            {
                color = -1;
                break;
            }
        }
        if (color == -1)
        {
            printf("No coloring solution found!\n");
            exit(1);
        }
        usedColors[colors[i]] = 1;
    }
    printf("Graph colored successfully!\n");
}

int main()
{
    Graph *g = graphCreate();
    graphAddEdge(g, 0, 1);
    graphAddEdge(g, 0, 2);
    graphAddEdge(g, 1, 2);
    graphAddEdge(g, 2, 3);
    graphAddEdge(g, 3, 4);
    graphAddEdge(g, 4, 0);

    int colors[] = {0, 1, 2, 3, 4};
    graphColor(g, colors);

    return 0;
}