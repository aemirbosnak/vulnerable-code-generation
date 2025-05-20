//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#define N 4

void printSol(int *col)
{
    printf("\nThe assigned colors are:\n");
    for(int i = 0; i < N; i++)
        printf(" Vertex %d -> Color %d\n", i, col[i]);
}

int isSafe(int v, int **g, int *col, int c)
{
    for(int i = 0; i < N; i++)
        if(g[v][i] && c == col[i])
            return 0;
    return 1;
}

int graphColoring(int **g, int m, int *col, int v)
{
    if(v == N) return 1;

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(v, g, col, c))
        {
            col[v] = c;
            if(graphColoring(g, m, col, v+1))
                return 1;
            col[v] = 0;
        }
    }
    return 0;
}

int main()
{
    int **g, m, *col;
    g = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++)
        g[i] = (int *)malloc(sizeof(int) * N);

    int edges[][2] = {{0,1}, {1,2}, {2,3}, {3,0}};
    int E = sizeof(edges)/sizeof(edges[0]);

    for(int i = 0; i < E; i++)
    {
        int x = edges[i][0], y = edges[i][1];
        g[x][y] = 1; g[y][x] = 1;
    }

    printf("Please input the number of colors to be used for vertices:\n");
    scanf("%d", &m);
    col = (int *)calloc(N, sizeof(int));

    if(!graphColoring(g, m, col, 0))
    {
        printf("\nSolution does not exist.");
        return 0;
    }  
    printSol(col);

    // Memory Deallocation
    for(int i = 0; i < N; i++) free(g[i]);
    free(g); free(col);
    return 0;
}