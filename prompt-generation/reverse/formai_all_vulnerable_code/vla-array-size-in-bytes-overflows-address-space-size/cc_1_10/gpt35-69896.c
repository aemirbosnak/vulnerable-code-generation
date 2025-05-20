//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAXVERTICES 100
#define MAXCOLORS 5

int graph[MAXVERTICES][MAXVERTICES], num_vertices;

void printSolution(int color[])
{
    printf("\nMinimum total number of colors required is %d. The color assigned to each vertex is:\n", MAXCOLORS);
    for (int i = 0; i < num_vertices; ++i)
        printf("Vertex %d: Color %d\n", i, color[i]);
}

int isSafe(int v, int color[], int c)
{
    for (int i = 0; i < num_vertices; ++i)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

int graphColorUtil(int m, int color[], int v)
{
    if (v == num_vertices)
        return 1;
    for (int c = 1; c <= m; ++c)
    {
        if (isSafe(v, color, c))
        {
            color[v] = c;
            if (graphColorUtil(m, color, v + 1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int graphColoring(int m)
{
    int color[num_vertices];
    for (int i = 0; i < num_vertices; ++i)
        color[i] = 0;
    if (!graphColorUtil(m, color, 0))
        return 0;
    printSolution(color);
    return 1;
}

int main()
{
    printf("Enter the number of vertices in the graph (maximum 100): ");
    scanf("%d", &num_vertices);
    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < num_vertices; ++i)
    {
        for (int j = 0; j < num_vertices; ++j)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] < 0 || graph[i][j] > 1)
            {
                printf("Invalid matrix entry. Entries must be either 0 or 1.\n");
                return 0;
            }
        }
    }
    int m = MAXCOLORS;
    while (!graphColoring(m))
    {
        ++m;
    }
    return 0;
}