//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

//Defining the limit of colors allowed
#define MAX_COLOR 3

//function to check if the coloring is valid
int isSafe(int **graph, int *color, int v, int c, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] && c == color[i]) return 0;
    }
    return 1;
}

//function to color the vertices
int graphColoring(int **graph, int *color, int v, int n)
{
    if(v == n) return 1;

    for(int i = 0; i < MAX_COLOR; i++)
    {
        if(isSafe(graph, color, v, i, n))
        {
            color[v] = i;

            if(graphColoring(graph, color, v + 1, n)) return 1;

            color[v] = -1;
        }
    }
    return 0;
}

int main()
{
    //Initializing the graph
    int n = 4;
    int **graph = (int **)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
    {
        graph[i] = (int*)malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) graph[i][j] = 0;
    }
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    //Initializing the colors
    int *color = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) color[i] = -1;

    if(graphColoring(graph, color, 0, n))
    {
        for(int i = 0; i < n; i++) printf("Vertex %d is colored %d\n", i, color[i]);
    }
    else printf("No solution exists");

    return 0;
}